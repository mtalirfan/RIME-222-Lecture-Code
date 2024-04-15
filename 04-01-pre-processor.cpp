#include <stdio.h>
/* define vars are preprocessors,
they are substituted by what they have been defined with,
where they appear in the main code */
# define pi 3.14159
# define square(x) (x*x)


int main() {
  printf("Hello World! \n");
  printf("Value of PI squared = %f \n", square(pi));

  if (square(pi) >= 9) {
    printf("PI squared is greater than 9. \n");
  }
  else {
    printf("PI squared is less than 9. \n");
  };

  // TODO Switch-Case: the if-else logic can be replaced with switch-case

  return 0;
}