#include "tui.h"
#include <stdlib.h>
#include <stdio.h>

tui_cursor_t *cursor_make()
{
    tui_cursor_t *c = malloc(sizeof(*c));
    reset_cursor(c);
    return c;
}

void cursor_reset(tui_cursor_t *c) 
{
    c->row = 0;
    c->col = 0;
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
