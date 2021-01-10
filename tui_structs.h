#ifndef _TUI_STRUCTS
#define _TUI_STRUCTS

#include <stdint.h>
#include <stdlib.h>

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

    uint8_t *buffer;
    uint16_t rows;
    uint16_t cols;
    uint32_t length;

    uint16_t offs_row;
    uint16_t offs_col;

    struct tui_win *subwins;
    uint8 subwin_count;
};

// Cursor (todo: add relative positioning)
struct tui_cursor {
    uint16_t id;

    int16_t row;
    int16_t col;

    uint8_t look;
    uint8_t color;
};

// Event definition
struct tui_event {
    uint16_t id;

    struct tui_event *prev;
    struct tui_event *next;
    
    uint8_t category;

    void *event_data;
    void *raw_data;
};

/**
 * Type definitions
 * (the library does not use these at any point)
 */

typedef struct tui_win TUIWin;
typedef struct tui_cursor TUICursor;
typedef struct tui_event TUIEvent;

#endif
