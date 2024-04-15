// Interrupt Service Routine example
// Mobile Robot with Bump Sensors

#include <stdio.h>
// #include <other library files.h>
// #include "user defined files.h"

// # define interrupt_name _VECTOR(interrupt_value_in_vector_table)
// interrupts are basically pre-defined events in a vector table

// this vector table is different for each hardware, for example:
// # define TIMER _VECTOR(6)

// Global Variables Definition
bool bump_detected = 0; // false or 0

/* Macros Definition


*/

// Function Declaration

void controller_init(void) {
  return;
};
void GPIO_interrupt_init(void) {
  return;
};
void stop_motor(void) {
  return;
};
void move_opposite_direction(void) {
  return;
};


void my_ISR_handler(void) {
  // interrupt_name = 0; // Interrupt when triggered becomes 1, change it to 0
  bump_detected = 1; // true or 1
}


int main() {

  controller_init();
  GPIO_interrupt_init();

  while (1) {
    if (bump_detected == 1) {
      stop_motor();
      move_opposite_direction();
    }
  };

  return 0;
}