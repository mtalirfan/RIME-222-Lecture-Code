/*
Note: Here we design that we use 4 interrupts of controller;
3 external (from external sources) and 1 internal interrupt from internal source.
So we will 4 interrupt service routines (ISRs) in this file.

External interrupt 1 detects light on, and detects logic 0 -> 1
level change on microcontroller I/O pin.

External interrupt 2 detects light off, and detects logic 1 -> 0
level change on microcontroller I/O pin.

The logic change 1 -> 0 and 0 -> 1 is designed by some external digital circuit and sensor.

External interrupt 3 detects an object when a positive edge (rising edge)
is detected/generated at microcontroller pin, by an external sensor and
digital/analog conditioning circuit.

Internal interrupt is from the internal source of microcontroller which is timer.
Timer interrupt occurs when a timer overflows after initialisation of timer registers.
*/

// include header files
#include <stdio.h>
#include <cstring>
// #include "user_header.h"

#define hiding_state 1
#define driving_forward_state 2
#define backing_up_state 3

// define global variable and initialising variables
unsigned char state_value = 0;
bool event_detect = 0;

// function declaration
void controller_init (void);
void interrupt_init (void);
/* The 3 external sources interrupt and 1 internal source interrupt
are all enabled and set in the interrupt_init() function.
*/

// not in notes
void disable_timer (void);
void stop_robot (void);
void move_robot_forward (void);
void turn_left (void);
void delay (void);
void reverse_robot (void);
void start_timer (void);

// function definition
void controller_init (void) {
    // controller-specific register settings will be in this function
};

void interrupt_init (void) {
    // all 4 interrupts are configured in this function
    // using the controller datasheet
};

// making ISR routines
void my_light_off_ISR (void) {
    // LIF = 0; // controller-specific flag that triggers when an interrupt occurs, switch it to 0
    state_value = 1;
    event_detect = 1;
} /*
my_light_off() ISR instruction will be executed when a level change
of logic from 1 -> 0 happens on microcontroller input after ISR execution.
The program execution returns to the main loop from where
it left when the interrupt occured. */

void my_object_detect_ISR (void) {
    // EIF = 0; // controller-specific flag that triggers when an interrupt occurs, switch it to 0
    state_value = 3;
    event_detect = 1;
}; /*
This interrupt service routine ISR occurs
when a positive edge is detected on controller input pin.
*/

int timer_variable = 0;
// internal timer ISR
void my_timer_ISR (void) {
    // TIF = 0; // timer flag is cleared, see datasheet for this flag bit active name.

    // USE EITHER THIS
    // for a short single interval of 3 sec
    state_value = 1;
    event_detect = 1;
    disable_timer(); // timer is also disabled/stopped.

    // OR THIS
    // for a large interval e.g. 30s
    // use a variable to increment and
    // check whether a certain number of increments is reached
    timer_variable = timer_variable + 1;
    // timer_variable++;
    if (timer_variable == 10) { // 10 * 3s = 30s passed
        timer_variable = 0;
        event_detect = 1;
        disable_timer();
    };

}; /*
In this program, for example, a timer interval of 3 seconds is required.
The timer interrupt occurs when 3 sec pass and corresponding timer register
value overflows (is reached). For large intervals e.g. 30 sec or any large value,
the practice is to keep the base timer interrupt for the small value, and then
increment a variable when the required time interval is reached.
*/

int main (void) { // '::main' must return 'int'
    controller_init();
    interrupt_init();
    // EI = 1; // enable interrupt globally, variable name compiler/microcontroller dependant

    while (1) {
        if (event_detect == 1) {
            event_detect = 0; // turn off the boolean flag
            switch (state_value) {
                case hiding_state:
                    stop_robot();
                    break;
                case driving_forward_state:
                    move_robot_forward();
                    break;
                case backing_up_state:
                    turn_left();
                    delay();
                    reverse_robot();
                    start_timer();
                    break;
                default:
                    break;
            }; // switch statement bracket
        }; // if bracket
    }; // while bracket
    return 0;
}; // main bracket

/*
stop_robot() and other functions are user-defined, here only function call
is done. It is needed to declare and define these functions in this file or in another
file before calling the function.

delay() and start_timer() } from compiler
turn_left() and reverse_robot() } user defined
*/

// not defined in notes

void disable_timer (void) {
    // disable timer in this function
    return;
};
void stop_robot (void) {
    // stop robot in this function
    return;
};
void move_robot_forward (void) {
    // move robot forward in this function
    return;
};
void turn_left (void) {
    // turn left in this function
    return;
};
void delay (void) {
    // delay in this function
    return;
};
void reverse_robot (void) {
    // reverse robot in this function
    return;
};
void start_timer (void) {
    // start timer in this function
    return;
};

