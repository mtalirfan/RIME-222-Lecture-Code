/* Using Interrupt based architecture to execute
function x() at regular (60 msec) interval */

// This code is controller-specific so interrupts defined won't work, for logic-building purposes

#define INTERRUPT_Timer_Overflow 5

void Timer_Init(void) // function 3.
{
// Timer is configured as a 16-bit timer,
// which is automatically reloaded when it overflows
T2CON = 0x04; // Load control register
TH2= 0xFC; // Load Timer high byte
TL2= 0x18; // Load Timer low byte
// Timer interrupt is enabled, and ISR will be called
ET2 = 1;
// Start Timer running
TR2 = 1;
}

/*The link between function X() and the timer
overflow is made using the compiler keyword
‘interrupt’ and the following #define directive
(value 5 from / depends upon
controller/compiler) :
#define INTERRUPT_Timer_Overflow 5
*/

void X(void) interrupt INTERRUPT_Timer_Overflow // function 5.
{
// This ISR is called every 60 ms
// Place required code here...
}

void main(void) { // function 1
    Init_System(); // function 2
    Timer_Init(); // function 3. Set Timer for 60 msec
    EA = 1; // Globally enable interrupts
    while(1) // 'for ever' (Super Loop)
        {
        // Enter idle mode to save power
        Go_To_Sleep(); // function 4
        }
}


