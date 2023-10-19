// Libraries
#include <stdio.h>
#include "generate.h"

void test(int *columns) {
    printf("int value = %d, Character = %c\n", columns[0], columns[0]);
    printf("int value = %d, Character = %c\n", columns[1], columns[1]);
    printf("int value = %d, Character = %c\n", columns[2], columns[2]);
}

void generate_userID(int *bufArray, int rowCount) {
    //int arrayID[rowCount]; // todo: should I include 1 for NULL?
    int ID = 1;  // Index in list will always be ID-1 as list starts at 0.
    int i;       // For loop until row count

    for (i = 0; i < rowCount; ++i)
    {
        // Set the digit entered at the index
        bufArray[i] = ID;

        // Print the value incremented : TODO: remove after debugging
        printf("int value = %d\n", ID);

        //Increment
        ID++;
    }

    // return array to main: https://stackoverflow.com/questions/16604631/return-integer-array-from-function
    // https://stackoverflow.com/questions/11656532/returning-an-array-using-c
    // return arrayID;

}