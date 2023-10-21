/******************************************************************************
                                TableGen
                            Haya Moussa - 40245661
*******************************************************************************/

#include "tablegen.h"

// Saved list
// Create an instance of the UserData struct using pointers
struct UserData* user_data;

// All data read and saved will be stored in this list
char **arrayFirstName;
char **arrayLastName;
char **arrayCountry;

// Arrays generated, not read so not needed. We will use the struct array instead.
// Lists to write with (defining uninitialized)
//int *arrayID;

//char **arrayUserID;
//char **arrayPhoneNumber;
//char **arrayEmail;
//char **arraySIN;
//char **arrayPassword;

int main(int argc, char **argv) {

    // TODO: remove this before submitting
    setbuf(stdout, 0);

    // Create a seed needed for every execution, necessary to generate random
    srand(time(NULL));

    // Lists to use for generation
    char *email_suffixes[] = {"hotmail.com", "gmail.com", "yahoo.com", NULL};
    int nbr_suffix = count_array_elements(email_suffixes);

    char *phone_area_array[] = {"398", "270", "925", "867", "209", "429", "908", "997", "444", "219", NULL};
    int nbr_phone_area = count_array_elements(phone_area_array);


    // Declaration and initialization (automatic allocation = no free needed)
    int choice = 0;          // 1 or 2 for show_menu1(). Automatic allocation so no free needed
    int rowCount = 0;        // User input

    // Declare string using malloc since we do not know how many columns will be entered by user
    int *columns = (int *)malloc(sizeof(int)); // NEED TO ALLOCATE END OF STRING!! +1?

    // Call method to show menu
    show_menu1();
    
	// User input for main menu as an int
    fscanf(stdin,"%d", &choice);

    if (choice == 1) {
        show_menu2();

        // User input for the columns to generate
        select_columns(columns);

        // User input for the number of columns generated in the files
        printf("Enter row count (1 < n < 1M):");
        scanf("%d", &rowCount);

        // Create an instance of the struct
        struct UserData *users = (struct UserData*)malloc(rowCount * sizeof(struct UserData));

        // User input for the name of the csv file
        printf("Enter output file name (no suffix):");
        char filename[256]; // Assuming a maximum file name size of 255 characters
        if (fscanf(stdin, "%255s", filename) == 1) { // limit to 255 characters
            printf("File name entered: %s\n", filename);
        }

        for (int i = 0; i < rowCount; i++) {
        {
            // Allocate memory for each properties of the struct
            // user_data[i].user_id will use automatic allocation
            users[i].first_name = (char*)malloc(MAX_NAMES);
            users[i].last_name = (char*)malloc(MAX_NAMES);
            users[i].country = (char*)malloc(MAX_COUNTRIES);
            users[i].phone_number = (char*)malloc(10);          // Phone number format: "xxx-xxxx" + null terminator
            users[i].sin = (char*)malloc(10);                   // SIN format: "xxxxxxxxx" + null terminator
            users[i].password = (char*)malloc(17);              // Assuming a max password length of 16 + null terminator
            users[i].email = (char*)malloc(100);                // Assuming a max email length of 99 + null terminator

            // Allocate memory for the array where read elements will be saved. Use constant for nbr of lines in each file.
            arrayFirstName = (char **)malloc(sizeof(char *) * MAX_NAMES);
            arrayLastName = (char **)malloc(sizeof(char *) * MAX_NAMES);
            arrayCountry = (char **)malloc(sizeof(char *) * MAX_COUNTRIES);

            // Initialize each element to NULL (important to terminate the array)
            for (int i = 0; i < MAX_NAMES; i++) {
                arrayFirstName[i] = NULL;
                arrayLastName[i] = NULL;
            }
            // Initialize each element to NULL (important to terminate the array)
            for (int i = 0; i < MAX_COUNTRIES; i++) {
                arrayCountry[i] = NULL;
            }

            // Read the files
            // We pass a reference to the array variable to give the function the ability to change the value of the array in the MAIN and update things.
            read_file("C:\\Users\\Haya\\Documents\\Docker\\comp348\\first_names.txt", MAX_NAMES, arrayFirstName);
            read_file("C:\\Users\\Haya\\Documents\\Docker\\comp348\\last_names.txt", MAX_NAMES, arrayLastName);
            read_file("C:\\Users\\Haya\\Documents\\Docker\\comp348\\countries.txt", MAX_NAMES, arrayCountry);


            // TODO: GOOD MORNING. FIX THIS HERE. DO NOT FORGET TO CREATE A FREE FUNCTION.
            users[i].user_id = generate_userID();
            users[i].first_name = generate_element(arrayFirstName, MAX_NAMES);
            users[i].last_name = generate_element(arrayLastName, MAX_NAMES);
            users[i].country = generate_element(arrayCountry, MAX_COUNTRIES);
            users[i].phone_number = generate_phone_number(phone_area_array, nbr_phone_area);
            //users[i].sin = generate_SIN(arraySIN, rowCount);
            users[i].password = generate_password(6, 16);
            users[i].email = generate_email(users[i].first_name, users[i].last_name, email_suffixes, nbr_suffix);

            // Print or use the generated data as needed
            printf("User ID: %d\n", users[i].user_id); //working
            printf("First Name: %s\n", users[i].first_name); //working
            printf("Last Name: %s\n", users[i].last_name); //not working
            printf("Country: %s\n", users[i].country); // not working
            printf("Phone Number: %s\n", users[i].phone_number); // working
            //printf("SIN: %s\n", users[i].sin); //not working
            printf("Password: %s\n", users[i].password); //working
            printf("Email: %s\n", users[i].email); //half working
        }

        // TODO: Put free memory at the right place
        free_memory(users,rowCount);


                /*
                    switch (columns[i]) {
                        case USER_ID:
                        {
                            printf("UserID");
                        }
                        case FIRST_NAME:
                        {
                            printf("UserID");
                        }
                        case LAST_NAME:
                        {
                            printf("UserID");
                        }
                        case COUNTRY:
                        {
                            printf("UserID");
                        }
                        case PHONE_NUMBER:
                        {
                            printf("UserID");
                        }
                        case EMAIL:
                        {
                            printf("UserID");
                        }
                        case SIN:
                        {
                            printf("UserID");
                        }
                        case PASSWORD:
                        {
                            printf("UserID");
                        }
                    }
                    */
        }

        /*
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
         */

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
    /*
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

    */

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

void free_memory(struct UserData *users, int rowCount) {
    // Free memory for struct arrays
    for (int i = 0; i < rowCount; i++) {
        free(users[i].first_name);
        free(users[i].last_name);
        free(users[i].country);
        free(users[i].phone_number);
        free(users[i].sin);
        free(users[i].password);
        free(users[i].email);
    }
    free(users); // Free the memory for the array of struct

    // Free memory for name arrays
    for (int i = 0; i < MAX_NAMES; i++) {
        free(arrayFirstName[i]);
        free(arrayLastName[i]);
    }
    free(arrayFirstName);
    free(arrayLastName);

    // Free memory for country array
    for (int i = 0; i < MAX_COUNTRIES; i++) {
        free(arrayCountry[i]);
    }
    free(arrayCountry);
}

int count_array_elements(char **arrayName){
    int nbr_elements = 0;
    while (arrayName[nbr_elements] != NULL) {
        nbr_elements++;
    }
    return nbr_elements;
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