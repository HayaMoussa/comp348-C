/******************************************************************************
                                TableGen
                            Haya Moussa - 40245661
*******************************************************************************/

#include "tablegen.h"

// All data read and saved will be stored in this list
char **arrayFirstName;
char **arrayLastName;
char **arrayCountry;
int sortedBy;

int main(int argc, char **argv)
{
    // This is needed to run on Windows
    // setbuf(stdout, 0);

    // Lists to use for generation
    char *email_suffixes[] = {"hotmail.com", "gmail.com", "yahoo.com", NULL};
    int nbr_suffix = count_array_elements(email_suffixes);

    char *phone_area_array[] = {"398", "270", "925", "867", "209", "429", "908", "997", "444", "219", NULL};
    int nbr_phone_area = count_array_elements(phone_area_array);

    // Initialize the 'c' to the terminate character
    char proceed = '\0';

    do {
        // Declare string using malloc since we do not know how many columns will be entered by user
        int *columns = (int *) malloc(sizeof(int));

        // Declaration and initialization using automatic allocation (no free needed)
        int choice = 0;          // 1 or 2 for show_menu1(). Automatic allocation so no free needed
        int rowCount = 0;        // Provided by user input

        // Create a seed needed for every execution, necessary to generate random
        srand(time(NULL));

        // Call method to show menu
        show_menu1();

        // User input for main menu as an int
        fscanf(stdin, "%d", &choice);

        if (choice == 1)
        {
            // Show the columns options
            show_menu2();

            // User input for the columns to generate
            int count_columns = select_columns(columns);

            // User input for the number of columns generated in the files
            select_row_count(&rowCount);

            // User input for the name of the csv file
            char filename[MAX_FILE_NAME];                               // Assuming a fixed file name size
            select_output_filename(filename);

            // Allocate memory for the amount of user we will generate
            struct UserData *users = (struct UserData *) malloc(rowCount * sizeof(struct UserData *));

            // Prepare the arrays to receive data from file
            initialize_read_arrays();

            // Variables that act as booleans to avoid rereading from the .txt everytime
            int is_first_name_loaded = 0;
            int is_last_name_loaded = 0;
            int is_countries_loaded = 0;

            // Looping for each row desired
            for (int i = 0; i < rowCount; i++)
            {
                // Creating the memory for a user at that position in users
                create_user(&users[i]);

                for (int j = 0; j < count_columns; j++)
                {
                    if (columns[j] == USER_ID)
                    {
                        users[i].user_id = generate_userID();
                        //printf("User ID: %d\n", users[i].user_id);
                    }
                    else if (columns[j] == FIRST_NAME)
                    {
                        if (is_first_name_loaded == 0)
                        {
                            // Absolute path needed to run on Windows IDE
                            // read_file("C:\\Users\\Haya\\Documents\\Docker\\comp348\\first_names.txt", MAX_NAMES,arrayFirstName);

                            // Read file and save in array for linux
                            read_file("first_names.txt", MAX_NAMES, arrayFirstName);
                            is_first_name_loaded = 1;
                        }
                        // Fill the previous memory allocated using a generated first name
                        strcpy(users[i].first_name, generate_element(arrayFirstName, MAX_NAMES));

                        // printf("First Name: %s\n", users[i].first_name);
                    }
                    else if (columns[j] == LAST_NAME)
                    {
                        if (is_last_name_loaded == 0)
                        {
                            // Absolute path needed to run on Windows IDE
                            read_file("C:\\Users\\Haya\\Documents\\Docker\\comp348\\last_names.txt", MAX_NAMES,arrayLastName);

                            // Read file and save in array for linux
                            read_file("last_names.txt", MAX_NAMES, arrayLastName);
                            is_last_name_loaded = 1;
                        }
                        // Fill the previous memory allocated using a generated last name
                        strcpy(users[i].last_name, generate_element(arrayLastName, MAX_NAMES));
                        //printf("Last Name: %s\n", users[i].last_name); //not working
                    }

                    else if (columns[j] == COUNTRY)
                    {
                        if (is_countries_loaded == 0)
                        {
                            // Absolute path needed to run on Windows IDE
                            read_file("C:\\Users\\Haya\\Documents\\Docker\\comp348\\countries.txt", MAX_COUNTRIES,arrayCountry);

                            // Read file and save in array for linux
                            read_file("countries.txt", MAX_COUNTRIES, arrayCountry); //this works
                            is_countries_loaded = 1;
                        }
                        // Fill the previous memory allocated using a generated country
                        strcpy(users[i].country, generate_element(arrayCountry, MAX_COUNTRIES));
                        //printf("Country: %s\n", users[i].country); // not working
                    }

                    else if (columns[j] == PHONE_NUMBER)
                    {
                        strcpy(users[i].phone_number, generate_phone_number(phone_area_array, nbr_phone_area));
                        //printf("Phone Number: %s\n", users[i].phone_number); // working
                    }

                    else if (columns[j] == EMAIL)
                    {
                        strcpy(users[i].email, generate_email(users[i].first_name, users[i].last_name, email_suffixes, nbr_suffix)); //assume a max of 100 char
                        //printf("Email: %s\n", users[i].email); //half working
                    }

                    else if (columns[j] == SIN)
                    {
                        strcpy(users[i].sin, generate_SIN(users, rowCount));
                        //printf("SIN: %s\n", users[i].sin); //not working
                    }

                    else if (columns[j] == PASSWORD)
                    {
                        strcpy(users[i].password, generate_password(6, 16));
                        //printf("Password: %s\n", users[i].password); //working
                    }
                }
            }

            // Save first column into global variable to use it in sort.c
            sortedBy = columns[0];
            qsort(users, rowCount, sizeof(struct UserData), compare_data);

            // Write the file
            write_file(strcat(filename, ".csv"), columns, users, rowCount, count_columns);

            // TODO: Free memory is not working properly
            // free_memory(users, rowCount);

            // Summary test to show results
            summarize(columns, rowCount, filename, count_columns);
        }

        else if (choice == 2)
        {
            printf("Goodbye and thanks for using TableGen\n");
            break;
        }

        printf("\nPress 'c' or 'C' to continue ");
        scanf(" %c", &proceed);
    } while (proceed == 'c' || proceed == 'C'); // HAD TO CHANGE THIS FROM WHAT WAS GIVEN IN THE QUESTION...

    // Terminate program successfully
    return 0;
}

/***
 * Function to prompt user for a file name for the .csv file.
 * @param filename string entered by user
 */
void select_output_filename(char *filename)
{
    printf("Enter output file name (no suffix): ");
    scanf("%s", filename);
}

/***
 * Function to prompt user for how many users they want.
 * @param rowCount how many rows to generate in .csv file
 */
void select_row_count(int *rowCount)
{
    printf("Enter row count (1 < n < 1M): ");
    scanf("%d", rowCount);
}

/***
 * Function that allocates memory for each property of a user and fills it will null characters.
 * @param user
 */
void create_user(struct UserData *user)
{
    // Access member of a struct to allocate memory SAME AS (*user).first_name (dereference and access it's member)
    user->first_name = (char *) malloc(MAX_NAMES);
    user->last_name = (char *) malloc(MAX_NAMES);
    user->country = (char *) malloc(MAX_COUNTRIES);
    user->phone_number = (char *) malloc(10);    // Phone number format: "xxx-xxxx" + null terminator
    user->sin = (char *) malloc(10);             // SIN format: "xxxxxxxxx" + null terminator
    user->password = (char *) malloc(17);        // Assuming a max password length of 16 + null terminator
    user->email = (char *) malloc(100);          // Assuming a max email length of 99 + null terminator

    // Initialize the allocated properties with null characters
    if (user->first_name)
    {
        user->first_name[0] = '\0';
    }
    if (user->last_name)
    {
        user->last_name[0] = '\0';
    }
    if (user->country)
    {
        user->country[0] = '\0';
    }
    if (user->phone_number)
    {
        user->phone_number[0] = '\0';
    }
    if (user->sin)
    {
        user->sin[0] = '\0';
    }
    if (user->password)
    {
        user->password[0] = '\0';
    }
    if (user->email)
    {
        user->email[0] = '\0';
    }
}

/***
 * Function to allocate memory for the lists that will be read from the txt files
 * @param void
 * @return void
 */
void initialize_read_arrays()
{
    // Allocate memory for the array where read elements will be saved. Use constant for nbr of lines in each file.
    arrayFirstName = (char **) malloc(sizeof(char *) * MAX_NAMES);
    arrayLastName = (char **) malloc(sizeof(char *) * MAX_NAMES);
    arrayCountry = (char **) malloc(sizeof(char *) * MAX_COUNTRIES);

    // Initialize each element to NULL (important to terminate the array)
    for (int i = 0; i < MAX_NAMES; i++)
    {
        arrayFirstName[i] = NULL;
        arrayLastName[i] = NULL;
    }

    // Initialize each element to NULL (important to terminate the array)
    for (int i = 0; i < MAX_COUNTRIES; i++)
    {
        arrayCountry[i] = NULL;
    }
}


/**
 * Shows the option to start generating or exiting the program when it is first executed
 * @param void
 * @return void
 */
void show_menu1()
{
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
void show_menu2()
{
    system("clear");
    printf("Column Options\n");
    printf("--------------\n");

    printf("1. User ID            5. Phone Number\n");
    printf("2. First name         6. Email address\n");
    printf("3. Last name          7. SIN\n");
    printf("4. Country            8. Password\n\n");

    printf("Enter column list (comma separated, no spaces):");
}


/*
void free_memory(struct UserData *users, int rowCount)
{
    // Free memory for struct arrays
    for (int i = 0; i < rowCount; i++)
    {
        free(users[i].first_name);
        free(users[i].last_name);
        free(users[i].country);
        free(users[i].phone_number);
        free(users[i].sin);
        free(users[i].password);
        free(users[i].email);

        // Set the pointers to NULL after freeing
        users[i].first_name = NULL;
        users[i].last_name = NULL;
        users[i].country = NULL;
        users[i].phone_number = NULL;
        users[i].sin = NULL;
        users[i].password = NULL;
        users[i].email = NULL;
    }
    free(users); // Free the memory for the array of struct

    // Free memory for name arrays
    for (int i = 0; i < MAX_NAMES; i++)
    {
        free(arrayFirstName[i]);
        free(arrayLastName[i]);
    }
    free(arrayFirstName);
    free(arrayLastName);

    // Free memory for country array
    for (int i = 0; i < MAX_COUNTRIES; i++)
    {
        free(arrayCountry[i]);
    }
    free(arrayCountry);
}
 */

/**
 * Flexible function to count how many arrays without having to use sizeof() and calculations
 * @param arrayName array for which you would like to return the nbr of element
 * @return nbr_elements contained in array
 */
int count_array_elements(char **arrayName)
{
    int nbr_elements = 0;
    while (arrayName[nbr_elements] != NULL)
    {
        nbr_elements++;
    }
    return nbr_elements;
}

/**
 * Function that splits
 * @param columns : ints entered by user for which they would like to generate data
 * @return count : how many columns entered by user
 */
int select_columns(int *columns)
{
    int count = 0;                  // Initialize a count to keep track of the number of integers read, starts at 0
    char *inputColumns = NULL;      // Declare a pointer to store the "raw" char gotten from scanf.

    // Allocate memory for user input. 8 + 7 commas maximum. char are smaller than ints but let's allocate extra space.
    // Note: I THINK IT CRASHES WHEN YOU ENTER MORE COLUMSN BECAUSE OF THIS HERE, the realloc might not always work?
    inputColumns = (char *) malloc(sizeof(int) * 16);  // Allocate memory for user input

    // User input of the columns
    scanf("%s", inputColumns);

    // Use strtok to return a pointer to the first CHARACTER of the first token.
    char *token = strtok(inputColumns, ",");

    // Loop until the last token
    while (token != NULL)
    {
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

    return count;
}

/***
 * Function that shows a summary of what was entered by the user.
 * @param columns int columns entered by user
 * @param rowCount how many rows asked by user
 * @param filename filename picked by user (with .csv extension that was added)
 * @param count_columns how many columns entered
 */
void summarize(int *columns, int rowCount, char *filename, int count_columns) {
    printf("Summary of properties:\n");
    printf("  Columns: ");
    for (int j = 0; j < count_columns; j++)
    {
        if (j == count_columns-1){
            printf("%d",columns[j]);
        }
        else {
            printf("%d,",columns[j]);
        }
    }
    printf("\n  Row count: %d\n", rowCount);

    // remove the extension added earlier
    if (strlen(filename) > 4) {
        // Need to replace the last 4 characters with a null terminator
        filename[strlen(filename) - 4] = '\0';
    }

    printf("  File name: %s\n\n",filename);
    printf("Table written successfully to %s\n",filename);

}

/* TODO: What is left
 * test thing for all options (more than 3 rows does not work...) write read me
 * free things
 * figure out why qsort will not work in file
 * put linux file thingy
*/