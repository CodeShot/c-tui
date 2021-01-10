#include "tui.h"

struct tui_cursor *make_cursor()
{
    struct tui_cursor *c = malloc(sizeof(*c));
    reset_cursor(c);
    return c;
}

void reset_cursor(struct tui_cursor *c) 
{
    c->row = 0;
    c->col = 0;
}

char *repr_cursor(struct tui_cursor *c)
{
    char *str = malloc(64);
    sprintf(str, "tui_cursor: at row=%d, col=%d\n", c->row, c->col);
    return str;
}
