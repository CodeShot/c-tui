#ifndef _TUI_H
#define _TUI_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <poll.h>

#include "tui_structs.h"


/**
 * tui_window
 */
struct winsize *get_winsize();
struct tui_win *make_subwin(uint16_t rows, uint16_t cols);
struct tui_win *make_win();
char *repr_win(struct tui_win *win);

/**
 * tui_cursor
 */
struct tui_cursor *make_cursor();
void reset_cursor(struct tui_cursor *c);
char *repr_cursor(struct tui_cursor *c);

/**
 * tui_core
 */
void fill_win(struct tui_win *win, uint8_t c);
void clear_win(struct tui_win *win);
void blit_win(struct tui_win *win);
void blit_subwin(struct tui_win *win, uint16_t length);

void repaint();

void put_char(struct tui_win *win, uint16_t row, uint16_t col, uint8_t c); 
void put_string(struct tui_win *win, uint16_t row, uint16_t col, uint8_t *str);

/**
 * tui_keyboard
 */
struct termios *init_keyboard();
void reset_keyboard(struct termios *t);
int8_t poll_keyboard(struct tui_event *event);

#endif
