// Libraries
#include <stdio.h>
#include <stdlib.h> //for rand()
#include "generate.h"
#include "io.h"

//int *bufArray,
void generate_userID(int rowCount) {
    //int arrayID[rowCount]; // todo: should I include 1 for NULL?
    int ID = 1;  // Index in list will always be ID-1 as list starts at 0.
    int i;       // For loop until row count

    for (i = 0; i < rowCount; ++i)
    {
        // Set the digit entered at the index
        arrayID[i] = ID; // Declare a pointer to an int array

        //Increment
        ID++;
    }

    // return array to main: https://stackoverflow.com/questions/16604631/return-integer-array-from-function
    // https://stackoverflow.com/questions/11656532/returning-an-array-using-c
    // return arrayID;
}

// Function to randomly select a first name from the array
char *selectRandomName(char **arrayName, int count) {
    // count represents max lines
    int randomIndex = rand() % count;
    // Select a name
    return arrayName[randomIndex];
}
