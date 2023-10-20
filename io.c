// Libraries
#include <stdio.h>
#include "io.h"

#include <string.h>
#include <unistd.h>
#include <errno.h>


void test2() {
    printf("int value)");

}

void read_file(char *filename, int maxRows, char buffer[maxRows]) {
    // TODO: Full windows path on my laptop needed!! C:\Users\Haya\Documents\Docker\comp348\countries.txt
    FILE *file = fopen(filename, "r");

    // Message error and exit function if that file does not exist
    if (file == NULL) {
        perror("Error opening the file");
        return;
    }


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

        fprintf(file, "\n");
    }

    fclose(file);

    //TODO: Should I return stuff
    //return buffer[maxRows];
}

void write_file(char *filename, int *columns) {
    // Open the file for writing and overwrite if needed
    FILE *file = fopen(filename, "wt");

    /************************
     * HEADER GENERATION
     ************************/
    // Looping through the "array" of columns saved in select_columns to generate header
    int j;       // For loop of column values
    int max = sizeof(columns) / sizeof(int);
    for (j = 0; j <= max; ++j) // size of returns the size of THE pointer so need division
    {
        switch(columns[j])
        {
            case 1:
                fprintf(file,"User ID");
                break;
            case 2:
                fprintf(file,"First Name");
                break;
            case 3:
                fprintf(file,"Last Name");
                break;
            case 4:
                fprintf(file,"Country");
                break;
            case 5:
                fprintf(file,"Phone Number");
                break;
            case 6:
                fprintf(file,"Email Address");
                break;
            case 7:
                fprintf(file,"SIN");
                break;
            case 8:
                fprintf(file,"Password");
                break;
        }

        // If last one, do not print a comma
        if (j != max)
        {
            fprintf(file,",");
        }

    }
    fprintf(file, "\n");

    /****************************************
     * WRITING THE GENERATED DATA TO FILE
     ****************************************/

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