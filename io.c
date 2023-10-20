// Libraries
#include <stdio.h>
#include "io.h"

#include <string.h>
#include <unistd.h>
#include <errno.h>


void test2() {
    printf("int value)");

}

void read_file(char *filename, int maxRows) {
    // TODO: Full windows path on my laptop needed!! C:\Users\Haya\Documents\Docker\comp348\countries.txt
    FILE *file = fopen(filename, "r");

    // Message error and exit function if that file does not exist
    if (file == NULL) {
        perror("Error opening the file");
        return;
    }

    // Create a buffer the max size of the file and loop until it is empty
    char buffer[maxRows];
    int countRows = 0;
    for (countRows = 0; countRows < maxRows; ++countRows) // size of returns the size of THE pointer so need division
    {
        // Read the file
        fgets(buffer, sizeof(buffer), file);

        // source for strtok idea: https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input
        printf("%s", strtok(buffer, "\n")); // todo: remove any new line character

        // Print comma if not last element
        if (countRows!=maxRows-1) {
            printf(",");
        }
    }


    fclose(file);
}

void write_file(char *filename, int *columns) {
    FILE *file = fopen(filename, "wt"); // Open the file for writing

    // Prepare the header of the CSV with the columns entered
    fprintf(file, "User ID,First Name,Last Name\n");

    // Looping throught the "array" of columns saved in select_columns to generate
    int i;       // For loop of column values
    int max = sizeof(columns) / sizeof(int);
    for (i = 0; i < max; ++i) // size of returns the size of THE pointer so need division
    {
        switch(columns[i])
        {
            case 1:
                printf("User ID");
                break;
            case 2:
                printf("First Name");
                break;
            case 3:
                printf("Last Name");
                break;
            case 4:
                printf("Country");
                break;
            case 5:
                printf("Phone Number");
                break;
            case 6:
                printf("Email Address");
                break;
            case 7:
                printf("SIN");
                break;
            case 8:
                printf("Password");
                break;
        }

        // If last one, do not print a comma
        //int lastPosition = (sizeof(columns) / sizeof(int)) ; // TODO: erase this
        if (i != max - 1) // lastLoop
        {
            printf(",");
        }

    }

    // TODO: Write the actual line of data
    //fprintf(file, "%s,%s,%s\n", columns[0], columns[1], columns[2]);

    // Close file once writing is completed
    fclose(file);
}

/*
 * Good morning
 * - Clean up a bit and commit
 * - Test and fix
 * - Commit
 * - Save each read into automatic array with right amount (free by itself, no free needed)
 * - Code the generate for the first 4
 * - Commit
 * */