#ifndef _TUI_H
#define _TUI_H

#include <datastructs/datastructs.h>
#include "tui_structs.h"
#include <stdbool.h>
#include <stdint.h>
#include <termios.h>


/**
 * Definitions
 */

// Event types 
#define TUIEVT_KEY  0x1 // Keyboard event
#define TUIEVT_FREQ 0x2 // Frequency triggered event

// Character properties 
#define TUICHR_EMPTY    32 // Character for empty position
#define TUICHR_NORMAL   
#define TUICHR_BLINK 

#define ROW_ORIGIN 0
#define COL_ORIGIN 0

/**
 * @defgroup Window Functions for interacting with windows and subwindows
 */
tui_win_t *win_create();
tui_win_t *win_make_sub(tui_win_t *parent, uint16_t rows, uint16_t cols);
ui_win_t *win_make();
void win_free(tui_win_t *win);
char *win_repr(tui_win_t *win); 
void win_fill(tui_win_t *win, uint8_t c);
void win_clear(tui_win_t *win);
void win_blit(tui_win_t *win);
void win_put_char(tui_win_t *win, uint16_t row, uint16_t col, uint8_t c); 
void win_put_line(tui_win_t *win, uint16_t row, uint16_t col, uint8_t *buf, uint8_t length);
void win_put_win(tui_win_t *dest, tui_win_t *src);
void win_render(tui_win_t *win);
/**
 * }
 */

/**
 * @defgroup Cursor Functions for cursor manipulation and handling
 * {
 */
tui_cursor_t *cursor_make();
void cursor_set(tui_cursor_t *c, uint16_t row, uint16_t col);
void cursor_move(tui_cursor_t, uint16_t row_ofs, uint16_t col_ofs);
void cursor_reset(tui_cursor_t *c); 
void cursor_free(tui_cursor_t *c);
char *cursor_repr(tui_cursor_t *c);
/**
 * }
 */

/**
 * @defgroup Event Functions for interacting and handling events
 * {
 */
tui_event_t *event_create();
tui_event_queue_t *event_queue_create();
tui_event_queue_t *events_init();
void event_enqueue(tui_event_queue_t *eq, tui_event_t *evt);
tui_event_t *event_dequeue(tui_event_queue_t *eq);
void event_loop();
/**
 * }
 */

/**
 * @defgroup Keyboard Funtions for keyboard handling
 * {
 */
tui_keyboard_t *keyboard_create();
tui_keyboard_t *keyboard_init();
void keyboard_reset(tui_keyboard_t *kbd);
void keyboard_readkey(uint8_t fd, tui_event_t *evt);
tui_event_t *keyboard_poll();
/**
 * }
 */
#endif

