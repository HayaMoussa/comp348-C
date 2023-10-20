// Libraries
#include <stdio.h>
#include <stdlib.h> // for malloc
#include "io.h"

#include <string.h>


void read_file(char *filename, int maxRows, char **buffer) {
    // TODO: Full windows path on my laptop needed!! C:\Users\Haya\Documents\Docker\comp348\countries.txt
    FILE *file = fopen(filename, "r");

    // Message error and exit function if that file does not exist
    if (file == NULL) {
        perror("Error opening the file");
        return;
    }

    int countRows;
    for (countRows = 0; countRows < maxRows; ++countRows) {
        // Create space for an array of characters for each row (index)
        buffer[countRows] = (char *) malloc(64); // Assuming a maximum line length of 64 bytes

        //TODO: Should I realloc?

        // Exit the loop if there are no more line to read
        if (fgets(buffer[countRows], 255, file) == NULL) {
            break; // Exit the loop if there are no more lines
        }

        /*
         // TODO: This is for testing
        // Remove the newline character from the end of the string
        fprintf(stdout, "%s", strtok(buffer[countRows], "\n"));//  strtok(buffer[countRows], "\n");

        // Print comma if not last element
        if (countRows!=(maxRows-1)) {
            fprintf(stdout,",");
        }
         */
    }

    fclose(file);
}

void write_file(char *filename, int *columns, int rowCount) {
    // Open the file for writing and overwrite if needed
    FILE *file = fopen(filename, "wt");

    // Looping through the "array" of columns saved in select_columns to generate header
    int columnIndex;        // For loop of column values
    int rowWritten;         // For loop of rows (includes header)

    // How many columns to loop
    int max = sizeof(columns) / sizeof(int);

    // TODO: Teacher used fput? I used fprintf for it's formatting options.
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
                        fprintf(file, "%s", arrayFirstName[rowWritten]);
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