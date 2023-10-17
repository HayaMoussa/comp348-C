/******************************************************************************
                                TableGen
                            Haya Moussa - 40245661
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h> // for clear
#include <string.h> // for strtok

// Method signatures, todo: fix manual inclusion?
void show_menu1();
void show_menu2();
void show_array();

int main(int argc, char **argv) {

    int choice = 0;      // 1 or 2 for show_menu1(). Automatic allocation so no free needed
    int count = 0;       // Initialize a count to keep track of the number of integers read
    char *inputColumns = NULL;      // Declare a pointer to store the "raw" char gotten from scanf.
    int *columns = NULL;            // Declare a pointer to store the casted integers used for manipulations

    // TODO: remove this before submitting
    setbuf(stdout, 0);

    // Call method to show menu
    show_menu1(choice);
    
	// User input for main menu as an int
	scanf("%d", &choice);

    if (choice == 1) {
        show_menu2();

        // Allocate memory for user input. 8 + 7 commas maximum.
        inputColumns = (char *) malloc(sizeof(int) * 16);  // Allocate memory for user input

        // User input of the columns
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
    else if (choice == 2)
    {
        printf ("Goodbye and thanks for using TableGen\n");
    }

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
void show_menu2(int choice) {
    system("clear");
    printf("Column Options\n");
    printf("--------------\n");
    
    printf("1. User ID            5. Phone Number\n");
    printf("2. First name         6. Email address\n");
    printf("3. Last name          7. SIN\n");
    printf("4. Country            8. Password\n\n");

    printf("Enter column list (comma separated, no spaces):");
}



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