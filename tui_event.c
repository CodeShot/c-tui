#include "tui.h"


struct event_queue {
    struct tui_event *root;
};


struct event_queue *init_events()
{
    struct tui_event *evt = malloc(sizeof(*evt));
    struct event_queue *eq = malloc(sizeof(*eq));

    eq->root = evt;

    return  eq;
}


void add_event(struct tui_event *evt)
{

}

void pop_event(struct event_queue *eq)
{
    struct tui_event *evt = eq->root;

    eq->root = evt->next
    eq->root->prev = NULL;

    return eq->root
}
