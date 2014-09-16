/*
    This file was autogenerated by ButtonParsePro
*/

#ifndef _PART2_BUTTONS_H
#define _PART2_BUTTONS_H

#include <message.h>

/* PIO defines */
#define BUTTON_A 0x800
#define BUTTON_B 0x1000

/* Raw PIO defines */

/* Button actions */
typedef enum
{
    ENTER,
    RELEASE,
    HELD,
    HELD_RELEASE,
    DOUBLE
} ActionType;

/* Button task messages to client */
typedef enum
{        
    A_PRESS = 1000,
    A_DOUBLE,
    B_RELEASE,
    PIO_RAW                         /* always the last value */
} PioMessage;

typedef uint32 pio_bits_t;

/*
 * PIO_RAW message type
 */

typedef struct _pio_raw_t
{
    pio_bits_t pio;
} PIO_RAW_T;

typedef struct
{
    pio_bits_t      bits;
    pio_bits_t      mask;
    ActionType      action;  
    uint16          timeout;
    uint16          repeat;       /* only used for HELD and ENTER actions */
    PioMessage      message;
} PioActionMessage;

typedef struct _pio_stored_states
{
    /* The PIO bits, as last read or indicated */
    pio_bits_t                  pio_bits;           
    /* PIO deep sleep wake up state PS Key setting */
    uint16                      pskey_wakeup;
    /* The PIO bits, whose release message is to be
       suppressed */
    pio_bits_t                  pio_release_disabled;
    /* PAM state stored for timers */
    const PioActionMessage      *held_release;
    const PioActionMessage      *repeat;
    const PioActionMessage      *double_tap; 
} PioStoredStates;

add new tetst 

typedef struct _pio_state
{
TaskData        task;
    Task            client;
    PioStoredStates stored;
} PioState;

/*
 * Function prototypes
 */

void pioInit(PioState *state, Task client);

#endif
