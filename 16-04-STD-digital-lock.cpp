#include <stdio.h>
#include <cstring> // other libraries as required
// #include <otherlibfiles.h>
// #include "myheaderfiles.h" // user defined header files

// Macro Definitions
// assigning correct numeric value to each digit
#define pass_digit_1 2
#define pass_digit_2 1
#define pass_digit_3 8

// giving events their assigned values
#define none_right 1
#define one_right 2
#define two_right 3
#define lock_open 4

// defining global variables and value initialisation
unsigned char key_entered_value = 0;
unsigned char key_count = 0;
bool key_pressed = 0; // or false

// function declarations
void controller_init(void); // function for controller settings
void interrupt_init(void); // function for interrupt initialisation
/*
we design or assume that we are using serial data out
interface when key is pressed from keypad
*/

// function definitions
void controller_init(void) {
    // controller-specific register settings will be done in this function
    return;
};

void interrupt_init(void) {
    // enabling serial interrupt
    // registers setting
    // interrupt priority cycle
    return;
};


// not defined in notes
void open_lock(void) {
    return;
};
void close_lock(void) {
    return;
};

/*
writing ISR function for serial data receive.
An interrupt will be set on every 1byte/8bits received
at micro controller serial module.
*/

// interrupt keyword links ISR with program address
// the name SERIAL_INTERRUPT is microcontroller dependant
// the function name my_serial_ISR is user-defined
void my_serial_ISR(void) interrupt SERIAL_INTERRUPT {
    SIF = 0; // the interrupt turns 1 when triggered, clear interrupt by switching it to 0
    // the name SIF is controller dependant
    key_entered_value = serialcharrx();
    /* serialcharrx() is a library function from compiler
    its declaration and definition is in some library file,
    which has to be included by using #include */
    key_count = key_count + 1; // increment
    // key_count++; // increment, alternative
    key_pressed = 1; // bool is made true, to handle in main function
};

/*
microcontroller program will automatically shift program execution
from main loop to my_serial_ISR() whenever a serial interrupt occurs.
After ISR execution code execution will return to main code
instruction (main function) from where is left (was interrupted).
*/

int main(void) { // void in notes, gcc says '::main' must return 'int'
    controller_init();
    interrupt_init();
    EI = 1; // global interrupt, name is microcontroller/compiler dependant
    while (1) {
        if (key_pressed) {
            switch (key_count)
            {
            key_pressed = 0;
            case none_right:
                if (key_entered_value != pass_digit_1) {
                    key_count = 0;
                }
                break;
            case one_right:
                if (key_entered_value != pass_digit_2) {
                    key_count = 0;
                }
                break;
            case two_right:
                if (key_entered_value != pass_digit_3) {
                    key_count = 0;
                }
                else {
                    open_lock(); // function that opens locks and gives indication also
                }
                break;
            case lock_open:
                close_lock();
                // when 4th key is pressed by user the lock is closed and state returns to initial value
                key_count = 0;
                break;
            default:
                break;
            } // close switch statement
        }; // close if bracket
    }; // close while() bracket
    return 0;
}; // close main() bracket


/*
In the 3 cases none_right, one_right, two_right we can call
function to display user-entered digit, if our design also
has a screen.

The four cases of switch can also be implemented using
if and else if statements.

In the required program we stay in one state
till an event occurs + new data is received,
and then we move to new state.
*/