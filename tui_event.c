#include <datastructs/datastructs.h>
#include "tui.h"


tui_event_t *event_create()
{
    return malloc(sizeof(tui_event_t));
}

tui_event_queue_t *event_queue_create()
{
    return malloc(sizeof(tui_event_queue_t));
}

tui_event_queue_t *events_init()
{
    tui_event_queue_t *eq = event_queue_create();
}


void event_enqueue(tui_event_queue_t *eq, tui_event_t *evt)
{
    add_queue(eq->q, evt);
}

tui_event_t *event_dequeue(tui_event_queue_t *eq)
{
    pop_queue(eq->q);
}
