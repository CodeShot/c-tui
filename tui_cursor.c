#include "tui.h"
#include <stdlib.h>
#include <stdio.h>

tui_cursor_t *cursor_make()
{
    tui_cursor_t *c = malloc(sizeof(*c));
    reset_cursor(c);
    return c;
}

void cursor_set(tui_cursor_t *c, uint16_t row, uint16_t col)
{
    c->row = row; 
    c->col = col;
}

void cursor_reset(tui_cursor_t *c) 
{
    cursor_set(c, ROW_ORIGIN, COL_ORIGIN);
}

// Wrap some more will ya
void cursor_move(tui_cursor_t *c, uint16_t row_ofs, uint16_t col_ofs)
{
    cursor_set(c, c->row + row_ofs, c->col + col_ofs);
}


void cursor_free(tui_cursor_t *c)
{
    free(c);
}

char *cursor_repr(tui_cursor_t *c)
{
    char *str = malloc(64);
    sprintf(str, "tui_cursor: at row=%d, col=%d\n", c->row, c->col);
    return str;
}
