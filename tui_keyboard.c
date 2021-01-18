#include "tui.h"

tui_keyboard_t *keyboard_create()
{
    return malloc(sizeof(tui_keyboard_t));
}

tui_keyboard_t *keyboard_init()
{
    tui_keyboard_t *kbd = keyboard_create();

    tcgetattr(STDIN_FILENO, kbd->old);
    cfmakeraw(t);
    tcsetattr(STDIN_FILENO, TCSANOW, kbd-current);
    return kbd;
}


void keyboard_reset(tui_keyboard_t *kbd)
{
    tcsetattr(STDIN_FILENO, TCSANOW, kbd->old);
}

// Very unfinished, a keypress could be up to 4bytes if it is a escape sequence
void keyboard_readkey(uint8_t fd, tui_event_t *evt)
{
    read(fd, &chr, 1);
}

tui_event_t *keyboard_poll()
{
    struct pollfd fd;
    fd.fd = STDIN_FILENO;
    fd.events = POLLIN;

    if (poll(&fd, 1, 0) < 1)
        return NULL;

    tui_event_t *evt;
    keyboard_readkey(fd.fd, evt);
}
