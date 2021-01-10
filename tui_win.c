#include "tui.h"


struct winsize *get_winsize()
{
    struct winsize *max = malloc(sizeof(*max));
    ioctl(STDOUT_FILENO, TIOCGWINSZ, max);
    return max;
}

struct tui_win *make_subwin(struct tui_win *parent, uint16_t rows, uint16_t cols)
{
    struct tui_win *win = malloc(sizeof(*win));

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

// TODO: add distinctions
struct tui_win *make_win()
{
    struct winsize *ws = get_winsize();
    struct tui_win *win = make_subwin(NULL, ws->ws_row, ws->ws_col);

    return win;
}

void free_win(struct tui_win *win)
{
    free_win(struct tui_win *win)
}

char *repr_win(struct tui_win *win) 
{
    char *str = malloc(64);
    sprintf(str, "tui_window: %dx%d, (%d characters)\n", win->rows, win->cols, win->length);

    return str;
}
