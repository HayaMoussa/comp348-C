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

    // TODO: Teacher used fput? I used fprintf for it's formatting options.
    int rowWritten;
    for (rowWritten = -1; rowWritten < rowCount; ++rowWritten) // starts at -1 for row header.
    {
        // Looping through the "array" of columns saved in select_columns to generate data
        for (columnIndex = 0; columnIndex <= max; ++columnIndex) // size of returns the size of THE pointer so need division
        {
            switch (columns[columnIndex]) {
                case 1: // User ID
                    // This writes the header
                    if (rowWritten==-1)
                    {
                        fprintf(file,"User ID");
                    }
                    // This writes the data
                    else
                    {
                        fprintf(file, "%d", arrayID[rowWritten]);
                    }
                    break;
                case 2: // First Name
                    if (rowWritten==-1)
                    {
                        fprintf(file,"First Name");
                    }
                    else
                    {
                        fprintf(file, "NOPE");
                    }
                    break;
                case 3: // Last Name
                    if (rowWritten==-1)
                    {
                        fprintf(file,"Last Name");
                    }
                    else
                    {
                        fprintf(file, "NOPE");
                    }
                    break;
                case 4: // Country
                    if (rowWritten==-1)
                    {
                        fprintf(file,"Country");
                    }
                    else
                    {
                        fprintf(file, "NOPE");
                    }
                    break;
                case 5: // Phone Number
                    if (rowWritten==-1)
                    {
                        fprintf(file,"Phone Number");
                    }
                    else
                    {
                        fprintf(file, "NOPE");
                    }
                    break;
                case 6: // Email Address
                    if (rowWritten==-1)
                    {
                        fprintf(file,"Email Address");
                    }
                    else
                    {
                        fprintf(file, "NOPE");
                    }
                    break;
                case 7: // SIN
                    if (rowWritten==-1)
                    {
                        fprintf(file,"SIN");
                    }
                    else
                    {
                        fprintf(file, "NOPE");
                    }
                    break;
                case 8: // Password
                    if (rowWritten==-1)
                    {
                        fprintf(file,"Password");
                    }
                    else
                    {
                        fprintf(file, "NOPE");
                    }
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


// Write the actual line of data
//fprintf(file, "%s,%s,%s\n", columns[0], columns[1], columns[2]);