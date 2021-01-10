#include "tui.h"


struct termios *init_keyboard()
{
    struct termios *t = malloc(sizeof(*t)); 
    struct termios *old = malloc(sizeof(*old));

    tcgetattr(STDIN_FILENO, old);

    cfmakeraw(t);

    tcsetattr(STDIN_FILENO, TCSANOW, t);

    return old;
}


void reset_keyboard(struct termios *t)
{
    tcsetattr(STDIN_FILENO, TCSANOW, t);
}


int8_t poll_keyboard(struct tui_event *event)
{
    char chr;
    struct pollfd fd;
    fd.fd = STDIN_FILENO;
    fd.events = POLLIN;

    if (poll(&fd, 1, 100) > 0) {
        read(STDIN_FILENO, &chr, 1);
        if (chr == 'q')
            return -1;
    }
    
    return 1;
}

/*
int8_t poll_keyboard(struct tui_event *event)
{
    if (read(STDIN_FILENO, event->raw_data, 1) !=1)
        return -1;

    if (*event->raw_data[0] != '\x1b') 
        return 0; // Escape sequence maybe initiated

    if (*event->raw_data[1] != '[')
        return 0; // Look for modifier

    // COLLLECT ESCAPE SEQUENCE DATA        
    return 0;
}*/
