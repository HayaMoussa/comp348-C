// Libraries
#include <stdio.h>
#include <stdlib.h> // for malloc

#include <string.h>

// User-defined
#include "generate.h"
#include "io.h"


/***
 *
 * @param filename
 * @param maxRows
 * @param ***array:
 *          array: pointer to memory location of the string. String is saved as an array of char.
 *          *array: gives the string stored in that memory location
 *          array[i] : access to individual element of the string, so access to a character.
 *
 *          **array: Gives you a mega-list of all names, countries, etc. This is a list similar to a "page" that saves all the individual strings from the previous "level" (countries, first name, etc.) in one space
 *          *array[countRows]: access to a particular name, country, etc within the page.
 */
void read_file(char *filename, int maxRows, char **array) {
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
        array[countRows] = (char *) malloc(64); // Assuming a string of country, name, etc is never more thatn 64 bytes

        // TODO: WHY IS THIS NOT WORKING. NEW LINE ALWAYS SHOWING UP!
        // Remove the newline character from the end of the string
        char *newline = strtok(array[countRows], "\n");
        if (newline != NULL) {
            // Optionally remove carriage return character if present
            strtok(newline, "\r");
        }

        // Exit the loop if there are no more line to read
        if (fgets(array[countRows], maxRows, file) == NULL) {
            break;
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



void write_file(const char *filename, const int *columns, const struct UserData *users, int row_count, int count_columns) {
    // Open the file for writing and overwrite if needed
    FILE *file = fopen(filename, "wt");

    if (file == NULL) {
        perror("Error opening the file");
        return;
    }

    // Write the header row
    for (int i = -1; i <= count_columns; i++) {
        int col = ;
        if (i != 0) {
            fprintf(file, ",");
        }
        switch (columns[i] && i == -1) {
            case USER_ID:
                fprintf(file, "User ID");
                break;
            case FIRST_NAME:
                fprintf(file, "First Name");
                break;
            case LAST_NAME:
                fprintf(file, "Last Name");
                break;
            case COUNTRY:
                fprintf(file, "Country");
                break;
            case PHONE_NUMBER:
                fprintf(file, "Phone Number");
                break;
            case EMAIL:
                fprintf(file, "Email Address");
                break;
            case SIN:
                fprintf(file, "SIN");
                break;
            case PASSWORD:
                fprintf(file, "Password");
                break;
        }
    }
    fprintf(file, "\n");

    // Write the data rows
    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < count_columns; j++) {
            int col = columns[j];
            if (j != 0) {
                fprintf(file, ",");
            }
            switch (col) {
                case USER_ID:
                    fprintf(file, "%d", users[i].user_id);
                    break;
                case FIRST_NAME:
                    fprintf(file, "%s", users[i].first_name);
                    break;
                case LAST_NAME:
                    fprintf(file, "%s", users[i].last_name);
                    break;
                case COUNTRY:
                    fprintf(file, "%s", users[i].country);
                    break;
                case PHONE_NUMBER:
                    fprintf(file, "%s", users[i].phone_number);
                    break;
                case EMAIL:
                    fprintf(file, "%s", users[i].email);
                    break;
                case SIN:
                    fprintf(file, "%s", users[i].sin);
                    break;
                case PASSWORD:
                    fprintf(file, "%s", users[i].password);
                    break;
            }
        }
        fprintf(file, "\n");
    }

    // Close the file once writing is completed
    fclose(file);
}
