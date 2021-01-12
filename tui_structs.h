#ifndef _TUI_STRUCTS
#define _TUI_STRUCTS

#include <datastructs/datastructs.h>
#include <stdint.h>

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


/**
 * Data structure
 */

// Arbitrary window
struct tui_win {
    uint16_t id;
    bool is_root;

    uint8_t *buffer;
    uint16_t rows;
    uint16_t cols;
    uint32_t length;

    uint16_t offs_row;
    uint16_t offs_col;

    queue_t *subwins;
    uint8_t subwin_count;
};

// Cursor (todo: add relative positioning)
struct tui_cursor {
    uint16_t id;

    int16_t row;
    int16_t col;

    uint8_t look;
    uint8_t color;
};

// At the time only a container for termios structs
struct tui_keyboard {
    struct termios current;
    struct termios old;
};

// Event definition
struct tui_event {
    sl_node_t *next;
    
    uint8_t signal;

    void *event_data;
    void *raw_data;
};

// Event queue, bare at the moment
struct tui_event_queue {
    queue_t *q;
};

// Link a signal to a callback 
struct tui_callback_link {
    uint8_t signal;
    void *callback_data;
    void (*callback)(tui_event_t *, void *);
};


/**
 * Typedefs for exported types
 */
typedef struct tui_win tui_win_t;
typedef struct tui_cursor tui_cursor_t;
typedef struct tui_keyboard tui_keyboard_t;
typedef struct tui_event tui_event_t;
typedef struct tui_event_queue tui_event_queue_t;
typedef struct tui_callback_link tui_callback_link_t;
#endif
