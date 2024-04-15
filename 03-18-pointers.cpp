#include <stdio.h>
struct Person
{
    char name[50];
    int CNIC;
    float weight;
};

int main (void) {
    struct Person person1, person2, *pPerson;
    pPerson = &person1;
    pPerson->CNIC = 37405;
    pPerson->weight = 60.5;
    printf("CNIC: %i, Weight: %.1f", pPerson->CNIC, pPerson->weight);

    printf("\n");

    int *pc, c;
    c=5;
    pc=&c;
    printf("%d", *pc); // output is 5

    return 0;
}