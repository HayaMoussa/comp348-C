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
    int *columns = NULL; // Declare a pointer to store integers. Free needed after since dynamic allocation.
    int count = 0;       // Initialize a count to keep track of the number of integers read
    char *inputColumns;   // todo: should this be char?

    setbuf(stdout, 0);
    // Call method to show menu
    show_menu1(choice);
    
	// User input 
	scanf("%d", &choice);

    if (choice == 1)
    {
        show_menu2();
        
            /******************************
             * READING COLUMN LIST
             * *************************/

            columns = (int *)malloc(sizeof(int)); // NEED TO ALLOCATE END OF STRING!! +1

            // scanf returns 1 if digit or comma found, last one will not have a comma and that is ok!
            scanf("%s,", inputColumns); //4 in string is char 52 in ascii. noice!

            // Searches for the first character which is not ',', todo: char *
            char *token = strtok( inputColumns, ",");
        
        while (token != NULL) {
            
                // Return an int value corresponding to the contents of str is returned. TODO: CAST INT HERE?
                    inputColumns = (int *) strtol(token, NULL, 10);
                
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

