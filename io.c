// Libraries
#include <stdio.h>
#include <stdlib.h> // for malloc
#include <string.h>

// User-defined
#include "generate.h"
#include "io.h"


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
        buffer[countRows] = (char *) malloc(maxRows); // Assuming a maximum line length of 64 bytes


        // Exit the loop if there are no more line to read
        if (fgets(buffer[countRows], maxRows, file) == NULL) {
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
                case 1:
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
                case 2:
                    if (rowWritten==-1)
                    {
                        fprintf(file,"First Name");
                    }
                    else
                    {
                        char *randomFirstName = selectRandomName(arrayFirstName, MAX_NAMES);
                        fprintf(file, "%s", strtok(randomFirstName, "\n"));
                    }
                    break;
                case 3:
                    if (rowWritten==-1)
                    {
                        fprintf(file,"Last Name");
                    }
                    else
                    {
                        char *randomLastName = selectRandomName(arrayLastName, MAX_NAMES);
                        fprintf(file, "%s", strtok(randomLastName, "\n"));
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