#ifndef _TUI_H
#define _TUI_H

#include <datastructs/datastructs.h>
#include "tui_structs.h"
#include <stdbool.h>
#include <stdint.h>
#include <termios.h>


/**
 * tui_window
 */
struct winsize *get_winsize();
tui_win_t *make_subwin(uint16_t rows, uint16_t cols);
tui_win_t *make_win();
char *repr_win(tui_win_t *win);

/**
 * tui_cursor
 */
tui_cursor_t *make_cursor();
void reset_cursor(tui_cursor_t *c);
char *repr_cursor(tui_cursor_t *c);

/**
 * tui_core
 */
void fill_win(tui_win_t *win, uint8_t c);
void clear_win(tui_win_t *win);
void blit_win(tui_win_t *win);
void blit_subwin(tui_win_t *win, uint16_t length);

void repaint();

void put_char(tui_win_t *win, uint16_t row, uint16_t col, uint8_t c); 
void put_string(tui_win_t *win, uint16_t row, uint16_t col, uint8_t *str);

/**
 * tui_keyboard
 */
struct termios *init_keyboard();
void reset_keyboard(struct termios *t);
int8_t poll_keyboard(tui_event_t *event);

#endif
