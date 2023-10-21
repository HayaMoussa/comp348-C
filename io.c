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
void read_file(char *filename, int maxRows, char **array)
{
    // TODO: Full windows path on my laptop needed!! C:\Users\Haya\Documents\Docker\comp348\countries.txt
    FILE *file = fopen(filename, "r");

    // Message error and exit function if that file does not exist
    if (file == NULL)
    {
        perror("Error opening the file");
        return;
    }

    int countRows;
    for (countRows = 0; countRows < maxRows; ++countRows
            )
    {
        // Create space for an array of characters for each row (index)
        array[countRows] = (char *) malloc(64); // Assuming a string of country, name, etc is never more thatn 64 bytes

        // TODO: WHY IS THIS NOT WORKING. NEW LINE ALWAYS SHOWING UP!
        // Remove the newline character from the end of the string
        char *newline = strtok(array[countRows], "\n");
        if (newline != NULL)
        {
            // Optionally remove carriage return character if present
            strtok(newline, "\r");
        }

        // Exit the loop if there are no more line to read
        if (fgets(array[countRows], maxRows, file) == NULL)
        {
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


void write_file(const char *filename, const int *columns, struct UserData *users, int row_count, int count_columns)
{
    // Open the file for writing and overwrite if needed
    FILE *file = fopen(filename, "wt");

    if (file == NULL)
    {
        perror("Error opening the file");
        return;
    }


    // Write the header row
    for (int i = 0; i < count_columns; i++)
    {
        if (columns[i] == USER_ID)
        {
            fprintf(file, "User ID");
        } else if (columns[i] == FIRST_NAME)
        {
            fprintf(file, "First Name");
        } else if (columns[i] == LAST_NAME)
        {
            fprintf(file, "Last Name");
        } else if (columns[i] == COUNTRY)
        {
            fprintf(file, "Country");
        } else if (columns[i] == PHONE_NUMBER)
        {
            fprintf(file, "Phone Number");
        } else if (columns[i] == EMAIL)
        {
            fprintf(file, "Email Address");
        } else if (columns[i] == SIN)
        {
            fprintf(file, "SIN");
        } else if (columns[i] == PASSWORD)
        {
            fprintf(file, "Password");
        }

        // Last element in header should not have a comma, but others should.
        if (i != count_columns-1)
        {
            fprintf(file, ",");
        }
    }
    
    fprintf(file,"\n");
    
    // Write the data rows
    for (int row = 0; row < row_count; row++)
    {
      for (int col = 0; col < count_columns; col++) 
      {
          if (columns[col] == USER_ID)
          {
              fprintf(file,"%d", users[row].user_id);
          }
          else if (columns[col] == FIRST_NAME)
          {
              fprintf(file,"%s", users[row].first_name);
          }
          else if (columns[col] == LAST_NAME)
          {
              fprintf(file,"%s", users[row].last_name);
          }
          else if (columns[col] == COUNTRY)
          {
              fprintf(file,"%s", users[row].country);
          }
          else if (columns[col] == PHONE_NUMBER)
          {
              fprintf(file,"%s", users[row].phone_number);
          }
          else if (columns[col] == EMAIL)
          {
              fprintf(file,"%s", users[row].email);
          }
          else if (columns[col] == SIN)
          {
              fprintf(file,"%s", users[row].sin);
          }
          else if (columns[col] == PASSWORD)
          {
              fprintf(file,"%s", "%s", users[row].password);
          }
          // Last element in row should not have a comma, but others should.
          if (col != count_columns-1)
          {
              fprintf(file, ",");
          }
      }
      fprintf(file, "\n");
    }
    
    // Close the file once writing is completed
    fclose(file);
}

