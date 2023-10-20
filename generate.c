// Libraries
#include <stdio.h>
#include <stdlib.h> //for rand()
#include "generate.h"
#include "io.h"


void test(int *columns) {
    printf("int value = %d, Character = %c\n", columns[0], columns[0]);
    printf("int value = %d, Character = %c\n", columns[1], columns[1]);
    printf("int value = %d, Character = %c\n", columns[2], columns[2]);
}

//int *bufArray,
void generate_userID(int rowCount) {
    //int arrayID[rowCount]; // todo: should I include 1 for NULL?
    int ID = 1;  // Index in list will always be ID-1 as list starts at 0.
    int i;       // For loop until row count

    for (i = 0; i < rowCount; ++i)
    {
        // Set the digit entered at the index
        //bufArray[i] = ID;
        arrayID[i] = ID; // Declare a pointer to an int array

        // Print the value incremented : TODO: remove after debugging
        printf("int value = %d\n", ID);

        //Increment
        ID++;
    }

    // return array to main: https://stackoverflow.com/questions/16604631/return-integer-array-from-function
    // https://stackoverflow.com/questions/11656532/returning-an-array-using-c
    // return arrayID;
}

// Function to randomly select a name from the array
char *selectRandomName(char **names, int count) {
    // count represents max lines
    int randomIndex = rand() % count;
    // Select a name
    return names[randomIndex];
}
/*
void generate_firstName()
{

    printf("%s",arrayFirstName[randomNameIndex]); // todo: should this be c or s?

}
 */

/* AFTER CLASS:
 * - Generate a random name using generate_randomNumber().
 * - Change the code for it in io.c
 * - Adjust main
 * */