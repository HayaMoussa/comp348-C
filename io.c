// Libraries
#include <stdio.h>
#include "io.h"

#include <string.h>


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

void write_file(char *filename, int *columns, int rowCount) {
    // Open the file for writing and overwrite if needed
    FILE *file = fopen(filename, "wt");

    /************************
     * HEADER GENERATION
     ************************/
    // Looping through the "array" of columns saved in select_columns to generate header
    int columnIndex;       // For loop of column values
    int max = sizeof(columns) / sizeof(int);
    for (columnIndex = 0; columnIndex <= max; ++columnIndex) // size of returns the size of THE pointer so need division
    {
        switch(columns[columnIndex])
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
        if (columnIndex != max)
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

    // TODO: Maybe the loops need to be switched.
    // Looping through the "array" of columns saved in select_columns to generate data

    // TODO: Teacher used fput? I used fprintf for it's formatting options.
    int rowWritten;
    for (rowWritten = 0; rowWritten < rowCount; ++rowWritten)
    {
        for (columnIndex = 0; columnIndex <= max; ++columnIndex) // size of returns the size of THE pointer so need division
        {
            switch (columns[columnIndex]) {
                case 1: // User ID
                    fprintf(file, "%d", arrayID[rowWritten]);
                    break;
                case 2: // First Name
                    break;
                case 3: // Last Name
                    break;
                case 4: // Country
                    break;
                case 5: // Phone Number
                    fprintf(file, "Phone Number");
                    break;
                case 6: // Email Address
                    break;
                case 7: // SIN
                    fprintf(file, "SIN");
                    break;
                case 8: // Password
                    break;
            }

            // If last one, do not print a comma
            if (columnIndex != max) {
                fprintf(file, ",");
            }
        }
        fprintf(file, "\n");
    }

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