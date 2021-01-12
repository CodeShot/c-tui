#include "tui.h"
#include <poll.h>
#include <termios.h>

int main()
{
    char ascii[] = {55, 55, 55, 55, 55, 00, 55, 55, 55, 55, 55, \
                    00, 00, 55, 00, 00, 00, 00, 00, 00, 00, 55, \
                    00, 00, 55, 00, 00, 00, 00, 00, 00, 00, 55, \
                    00, 00, 55, 00, 00, 00, 55, 00, 00, 00, 55, \
                    00, 00, 55, 00, 00, 00, 00, 55, 55, 55, 00};

    tui_win_t *win = make_win();
    tui_win_t *textbanner = make_subwin(5, 11);
    memcpy(textbanner->buffer, &ascii, 55);

    const char *str = "This string is a test.";
    const char chr = 'x';
    char kbd=' ';
    uint8_t x = 0;

    struct termios *old = init_keyboard();
    tui_event_t *evt = malloc(sizeof(*evt));

    blit_win(win);

    while(poll_keyboard(evt) > -1) {        
        fill_win(win, TUICHR_EMPTY);
        put_char(win, 40, x, chr);
        blit_win(win);
        repaint();
        x = (x + 1) % win->cols;
    }

    reset_keyboard(old);
    exit(EXIT_SUCCESS);
}
