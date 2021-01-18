#include "tui.h"


struct winsize *get_winsize()
{
    struct winsize *ws = malloc(sizeof(*ws));
    ioctl(STDOUT_FILENO, TIOCGWINSZ, ws);
    return ws;
}

/**
 * Creation
 */

tui_win_t *win_create()
{
    return malloc(sizeof(tui_win_t));
}

tui_win_t *win_make_sub(tui_win_t *parent, uint16_t rows, uint16_t cols)
{
    tui_win_t *win = create_win();
    win->is_root = false;

    // Set all struct values to 0 
    memset(win, 0, sizeof(*win));    

    win->length = rows * cols;
    win->rows = rows;
    win->cols = cols;
    win->buffer = malloc(win->length);

    // Fill buffer with empty chars
    memset(win->buffer, TUICHR_EMPTY, win->length);

    if (parent != NULL) {
        (parent->subwins + parent->subwin_count) = win;
        parent->subwin_count++;
    }

    return win;
}

// Main windows are per default non scrollable
tui_win_t *win_make()
{
    struct winsize *ws = get_winsize();
    tui_win_t *win = make_subwin(NULL, ws->ws_row, ws->ws_col, false);

    win->is_root = true;

    return win;
}

void win_free(tui_win_t *win)
{
    tui_win_t *sub = pop_queue(win->subwins);

    // Got to free them subwindows recursion is a bliss
    while(sub != NULL) {
        free_win(sub);
        sub = pop_queue(win->subwins);
    }

    free(win);
}

char *win_repr(tui_win_t *win) 
{
    char *str = malloc(64);
    sprintf(str, "tui_window: %dx%d, (%d characters)\n", win->rows, win->cols, win->length);

    return str;
}

/**
 * Modification
 */

// Fill a window
void win_fill(tui_win_t *win, uint8_t c)
{
    memset(win->buffer, c, win->length);
}

// Clear screen buffer by overwrting blitmask
void win_clear(tui_win_t *win)
{
    fill_win(win, TUICHR_EMPTY);
}

// Blit screen buffer to stdout
void win_blit(tui_win_t *win)
{
    lseek(STDOUT_FILENO, 0, SEEK_SET);
    write(STDOUT_FILENO, win->buffer, win->length);
    fsync(STDOUT_FILENO);
}

// Put a single char at specific location
void win_put_char(tui_win_t *win, uint16_t row, uint16_t col, uint8_t c) 
{
    memset((win->buffer + row * win->cols + col), c, 1); 
}

// Put a line of chars (buf) at a specific location
void win_put_line(tui_win_t *win, uint16_t row, uint16_t col, uint8_t *buf, uint8_t length)
{
    memcpy((win->buf + row * win->cols + col), str, length);  
}

// Put a window (src) at a specific location on dest window
void win_put_win(tui_win_t *dest, tui_win_t *src)
{
    uint8_t *rowbuf = malloc(src->cols * sizeof(*rowbuf));

    for (int row = 0; row < dest->rows; row++) {
        memcpy(rowbuf, (src->buffer + row * src->cols), src->cols);
        win_put_line(dest, src->row + row, src->col, rowbuf, win->cols);
    }
}

// Render put characters of subwindows on the win window buffer
void win_render(tui_win_t *win)
{
    tui_win_t *sub = pop_queue(win->sub);
    
    while (sub != NULL) {
        win_put_win(win, sub);
        win_render(sub);
    }
}
