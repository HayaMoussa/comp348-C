/******************************************************************************
                                TableGen
                            Haya Moussa - 40245661
*******************************************************************************/

// Libraries
#include <stdio.h>
#include <stdlib.h> // for clear
#include <string.h> // for strtok
#include <time.h> // for srand time


// User-defined
#include "generate.h"
#include "io.h"

// Method signatures, todo: fix manual inclusion?
void show_menu1();
void show_menu2();
void select_columns();
void select_outputName();

//TODO: Remove this constant if not used
#define MAX_NAMES 1000
#define MAX_COUNTRIES 195

//TODO: Remove this if no global variable used
//extern int rowCount;

// Lists to write with (defining uninitialized)
int *arrayID;
char **arrayFirstName;
char **arrayLastName;
char **arrayCountry;

int main(int argc, char **argv) {
    // TODO: remove this before submitting
    setbuf(stdout, 0);

    // Create a seed for every execution used to generate random
    srand(time(NULL));
    /*
    // Generate a random number
    int rdm = generate_randomNumber(0,100);
    printf("%d", rdm);
     */

    int choice = 0;      // 1 or 2 for show_menu1(). Automatic allocation so no free needed
    int rowCount = 0;
    // Declare string outputFile = NULL using malloc since we do not know length of name
    int *columns = (int *)malloc(sizeof(int)); // NEED TO ALLOCATE END OF STRING!! +1

    // TODO: DO I NEED THIS
    //char *outputFile = (char *)malloc(sizeof(char));  // NEED TO ALLOCATE END OF STRING!! +1;



    // Call method to show menu
    show_menu1(choice);
    
	// User input for main menu as an int
    fscanf(stdin,"%d", &choice);

    if (choice == 1) {
        show_menu2();

        // User input for the columns to generate
        select_columns(columns);

        // User input for the number of columns generated in the files
        printf("Enter row count (1 < n < 1M):");
        scanf("%d", &rowCount);

        // User input for the name of the csv file
        printf("Enter output file name (no suffix):");
        char filename[256]; // Assuming a maximum file name size of 255 characters
        if (fscanf(stdin, "%255s", filename) == 1) { // limit to 255 characters
            printf("File name entered: %s\n", filename);
        }

        // Looping through the "array" of columns saved in select_columns to generate
        int i;       // For loop of column values
        for (i = 0; columns[i] != -1; ++i)
        {
            switch(columns[i])
            {
                // Source to add own scope to case: https://stackoverflow.com/questions/61708267/jump-bypasses-variable-initialization-in-switch-statement
                case 1: {
                    printf("User ID");

                    // Automatic allocation would not work here since global variables cannot have a variable length. E.g.int arrayID[rowCount]
                    // Need to dynamically allocate space - Free needed here
                    arrayID = (int *) malloc(rowCount * sizeof(int)); // Dynamically allocate memory
                    generate_userID(rowCount); //arrayID will be filled by function, global variable
                    break;
                }

                case 2: {
                    // Need to dynamically allocate space - Free needed later
                    arrayFirstName = (char **) malloc(MAX_NAMES * sizeof(char *)); // Dynamically allocate memory
                    for (int i = 0; i < MAX_NAMES; i++) {
                        arrayFirstName[i] = (char *)malloc(256); // No name should be more than 256 characters
                    }

                    // TODO: For windows
                    read_file("C:\\Users\\Haya\\Documents\\Docker\\comp348\\first_names.txt", MAX_NAMES, arrayFirstName);

                    // TODO: For Linux
                    // read_file("first_names.txt", MAX_NAMES, arrayFirstName);
                    break;
                }

                case 3:
                    // Need to dynamically allocate space - Free needed later
                    arrayLastName = (char **) malloc(MAX_NAMES * sizeof(char *)); // Dynamically allocate memory
                    for (int i = 0; i < MAX_NAMES; i++) {
                        arrayLastName[i] = (char *)malloc(256); // No name should be more than 256 characters
                    }

                    // TODO: For windows
                    read_file("C:\\Users\\Haya\\Documents\\Docker\\comp348\\last_names.txt", MAX_NAMES, arrayLastName);

                    // TODO: For Linux
                    // read_file("last_names.txt", MAX_NAMES, arrayLastName);
                    break;

                    // TODO: WHY DOES IT NOT ENTER THIS? I CANT HAVE 4 COLUMNS :(
                case 4:
                    // Need to dynamically allocate space - Free needed later
                    arrayCountry = (char **) malloc(MAX_COUNTRIES * sizeof(char *)); // Dynamically allocate memory
                    for (int i = 0; i < MAX_COUNTRIES; i++) {
                        arrayCountry[i] = (char *)malloc(256); // No name should be more than 256 characters
                    }

                    // TODO: For windows
                    read_file("C:\\Users\\Haya\\Documents\\Docker\\comp348\\countries.txt", MAX_COUNTRIES, arrayCountry);

                    // TODO: For Linux
                    // read_file("countries.txt", MAX_COUNTRIES, arrayCountry);
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
        }

        //select_outputName();

        // TODO: Add this to other columns
        //read_file("C:\\Users\\Haya\\Documents\\Docker\\comp348\\countries.txt", rowCount);

        // Adding the .csv suffix when writing file
        //write_file(strcat(filename, ".csv"), columns);

        // TODO: WRITE TO FILE
        // Adding the .csv suffix when writing file
        write_file(strcat(filename, ".csv"), columns, rowCount);

    }
    else if (choice == 2)
    {
        printf ("Goodbye and thanks for using TableGen\n");
    }


    /************************************
     * FREE MEMORY
     ***********************************/
    // Free the space for previous malloc
    free(arrayID);

    // todo: fix these free
    int i;
    for (i = 0; columns[i] != -1; ++i)
    {
        switch(columns[i])
        {
            case 1:
            {
                // Free the allocated memory for each string array when you are done
                for (int i = 0; i < MAX_NAMES; i++) {
                    free(arrayFirstName[i]);
                }

                // Free the memory for the main array
                free(arrayFirstName);
            }

            case 2:
            {
                // Free the allocated memory for each string array when you are done
                for (int i = 0; i < MAX_NAMES; i++) {
                    free(arrayFirstName[i]);
                }

                // Free the memory for the main array
                free(arrayFirstName);
            }

            case 3: {
                // Free the allocated memory for each string array when you are done
                for (int i = 0; i < MAX_NAMES; i++) {
                    free(arrayLastName[i]);
                }

                // Free the memory for the main array
                free(arrayLastName);
            }
            case 4: {
                // Free the allocated memory for each string array when you are done
                for (int i = 0; i < MAX_COUNTRIES; i++) {
                    free(arrayCountry[i]);
                }

                // Free the memory for the main array
                free(arrayCountry);
            }
        }
    }
    free(columns);



    // Terminate program successfully
    return 0;
}

/**
 * Shows the option to start generating or exiting the program when it is first executed
 * @param void
 * @return void
 */
void show_menu1() {
    printf("TableGen Menu\n");
	printf("-------------\n");
	printf("1. Generate new table\n");
    printf("2. Exit\n");
	printf("\n");
	printf("Selection: ");
}

/**
 * Shows the column options for generating
 * @param void
 * @return void
 */
void show_menu2() {
    system("clear");
    printf("Column Options\n");
    printf("--------------\n");
    
    printf("1. User ID            5. Phone Number\n");
    printf("2. First name         6. Email address\n");
    printf("3. Last name          7. SIN\n");
    printf("4. Country            8. Password\n\n");

    printf("Enter column list (comma separated, no spaces):");
}

void select_columns(int *columns) {
    int count = 0;                  // Initialize a count to keep track of the number of integers read, starts at 0
    char *inputColumns = NULL;      // Declare a pointer to store the "raw" char gotten from scanf.
    //int *columns = NULL;           // Declare a pointer to store the casted integers used for manipulations - acts as main array

    // Allocate memory for user input. 8 + 7 commas maximum.
    inputColumns = (char *) malloc(sizeof(int) * 16);  // Allocate memory for user input

    // User input of the columns // TODO: Should I put this back to c?
    scanf("%s", inputColumns);

    // Use strtok to return a pointer to the first CHARACTER of the first token.
    char *token = strtok(inputColumns, ",");

    // Loop until the last token
    while (token != NULL) {
        // Convert to a long int the token found by strtok
        int columnValue = (int) strtol(token, NULL, 10);

        // Increase the size of the array with the number of digits entered by the user
        columns = (int *) realloc(columns, (count + 1) * sizeof(int));

        // Set the digit entered at the index
        columns[count] = columnValue;

        // Increment to keep track of the indexes for future tokens
        count++;

        // Repeat loop
        token = strtok(NULL, ",");
    }

    // Deallocation needed due to malloc (dynamic)
    free(inputColumns);  // Deallocate user input memory
}

// TODO: void summarize()


/*   if (choice == 1)
    {
        // Show column choices
        show_menu2();

        *//******************************
         * READING COLUMN LIST
         * *************************//*

        columns = (int *)malloc(sizeof(int)); // NEED TO ALLOCATE END OF STRING!! +1
        inputColumns = (char *)malloc(sizeof(int) * 16); // Allocate memory for user input 15


        // scanf returns 1 if digit or comma found, last one will not have a comma and that is ok!
        scanf("%s,", inputColumns); //4 in string is char 52 in ascii. noice!

        // Searches for the first character which is not ',', todo: char *
        char *token = strtok( inputColumns, ",");


        while (token != NULL) {

            // Return an int value corresponding to the contents of str is returned. TODO: CAST INT HERE?
            //inputColumns = (int) strtol(token, NULL, 10);
            int columnValue = (int)strtol(token, NULL, 10);


            // Need realloc to re-size array if not first column. +1 for \0.
            columns = (int *)realloc(columns, (count + 1) * sizeof(int));

            // Assign the value entered to the correct index in the array
            columns[count] = inputColumns;

            // Increment for next loop
            count++;

            // NULL to continue tokenizing the same string from where it left off in the previous call.
            // https://en.cppreference.com/w/c/string/byte/strtok
            token = strtok(NULL, ",");
        }

        // Deallocation for first malloc
        free(columns);

    }*/

/*
*  Next time I work todo
*     - See why columns doesn't have a malloc in the main as the tokens entered are currently lost
*     - Commit
*     - Create a switch for the different options
*     - Commit
* */