#include "generate.h"
//#include "io.h"


int generate_random_number(int max) {
    int randomIndex = rand() % max;
    return randomIndex;
}

int generate_userID() {
    static int ID = 0;  // Keep previous value using a static variable
    ID++;
    return ID;
}

/***
 * For first name, last name and country
 * @param arrayName
 * @param max
 * @return
 */
char *generate_element(char **arrayName, int max) {
    int random_index = generate_random_number(max);
    char *element = strdup(arrayName[random_index]);

    if (element != NULL) {
        // Remove newline characters if present
        char *newline = strchr(element, '\n');
        if (newline != NULL) {
            *newline = '\0';
        }
    }

    return element;

}

char *generate_phone_number(char **arrayName, int max) {
    // Generate a random number to get from the 3 digits array
    int random_index = generate_random_number(max);

    // Generate a random number to get 4 digits
    int random_four_digits = generate_random_number(10000);

    // Allocate memory for 3 digits, '-', 4 digits, and null terminator to end string
    char* phone_number = (char*)malloc(12);
    if (phone_number) {
        sprintf(phone_number, "%s-%04d", arrayName[random_index], random_four_digits);
    }
    return phone_number;
}

// Function to generate an email address
char *generate_email(char* first_name, char* last_name, char** email_suffixes, int max) {
    // Fixed buffer for email
    char* email = (char*)malloc(max);

    // Generate a random index for the email suffix
    int random_index_suffix = generate_random_number(max);

    // Format the email address
    sprintf(email, "%c%s@%s", first_name[0], last_name, email_suffixes[random_index_suffix]);

    return email;
}

char *generate_SIN(struct UserData *users, int max) {

    // Allocate memory for 9 digits + null terminator
    char *sin = (char*)malloc(10);

    // Initialize the sin array with null characters
    for (int i = 0; i < 10; i++) {
        sin[i] = '\0';
    }

    while (1) {
        // GENERATE A SIN
        for (int i = 0; i < 9; i++) {
            // Generate a random digit between 0 and 9
            int random_digit = generate_random_number(10);  // Generate a random digit between 0 and 9

            // Generate the ACII character (zero is the same as doing +48)
             sin[i] = '0' + random_digit;
        }

        // Add the null at the last position to complete the string
        sin[9] = '\0';  // Null-terminate the string

        // TODO: ADD UNIQUENESS CHECKING
        /*
        // CHECK UNIQUENESS OF GENERATED SIN
        int is_unique = 1;
        for (int i = 0; i < max; i++) {
            if (strcmp(sin, users[i].sin) == 0) { // strcmp will return 0 if matching string in array, so not unique
                is_unique = 0;
                break;
            }
        }

        if (is_unique == 1 ) // still unique, we can return, otherwise restart with infinite loop
        {
            return sin;
        }
         */
        return sin;
    }
}


// Function to generate a random password
char *generate_password(int min_length, int max_length) {
    // Hardcode the allowed ASCII character
    const char printable_characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+[]{}|;:'\".<>?/"; // Define the set of printable characters

    // Generate a random password length that is greater than the minimum length, but less than the max
    int password_length = min_length + generate_random_number(max_length - min_length + 1);

    // Allocate memory for the password
    char* password = (char*)malloc(password_length + 1);

    for (int i = 0; i < password_length; i++) {
        // Set a character for each position of the password list (-1 since array of printable characters starts at 0)
        password[i] = printable_characters[generate_random_number(sizeof(printable_characters) - 1)];
    }

    // Add the null terminating string
    password[password_length] = '\0';


    return password;
}



