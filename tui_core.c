#include "tui.h"


// Fill a window
void fill_win(struct tui_win *win, uint8_t c)
{
    memset(win->buffer, c, win->length);
}

// Clear screen buffer by overwrting blitmask
void clear_win(struct tui_win *win)
{
    fill_win(win, TUICHR_EMPTY);
}

// Blit screen buffer to stdout
void blit_win(struct tui_win *win)
{
    lseek(STDOUT_FILENO, SEEK_SET, 0);
    write(STDOUT_FILENO, win->buffer, win->length);
}

// Blit mask buffer to stdout (like clear)
void blit_subwin(struct tui_win *win, uint16_t length)
{
   return; 
}

// Use to ensure a repaint (TODO: enquire to always require flush)
void repaint()
{
    fsync(STDOUT_FILENO);
}


// Put a singe char at specific location
void put_char(struct tui_win *win, uint16_t row, uint16_t col, uint8_t c) 
{
    memset((win->buffer + row * win->cols + col), c, 1); 
}

// Put a string at a specific location
void put_string(struct tui_win *win, uint16_t row, uint16_t col, uint8_t *str)
{
    memcpy((win->buffer + row * win->cols + col), str, strlen(str));  
}
