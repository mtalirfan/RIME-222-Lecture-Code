// https://www.w3schools.com/c/c_structs.php
#include <stdio.h>
#include <cstring>
struct Person {
    char name[50];
    int CNIC_1, CNIC_2; // split since CNIC was long for even a long long integer
    float weight;
};

int main (void) {
struct Person person1;
    // person1.name={‘A’,’L’,’I’};
    strcpy(person1.name, "Ali"); // cannot declare array of characters or string in struct directly, see w3schools link
    person1.CNIC_1 = 37405;
    person1.CNIC_2 = 17492749;
    person1.weight = 60.5;
    printf("Name: %s, CNIC: %i %i, Weight: %.1fkg", person1.name, person1.CNIC_1, person1.CNIC_2, person1.weight);
    return 0;
};

