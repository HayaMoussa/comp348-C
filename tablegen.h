#ifndef COMP348_TABLEGEN_H
#define COMP348_TABLEGEN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// For the row maximum in files
#define MAX_NAMES 1000
#define MAX_COUNTRIES 195

// Libraries
#include <stdio.h>
#include <stdlib.h> // for clear
#include <string.h> // for strtok
#include <time.h> // for srand time

// User-defined libraries
#include "generate.h"
#include "io.h"
#include "sort.h"

// To help with the readability of the code
#define USER_ID 1
#define FIRST_NAME 2
#define LAST_NAME 3
#define COUNTRY 4
#define PHONE_NUMBER 5
#define EMAIL 6
#define SIN 7
#define PASSWORD 8

// Define a struct to represent a row of data
struct UserData {
    int user_id;
    char *first_name;
    char *last_name;
    char *country;
    char *phone_number; // Format: "xxx-xxxx"
    char *email;
    char *sin;          // 9-digit SIN
    char *password;     // Password can be up to 16 characters
};

void show_menu1();
void show_menu2();
int count_array_elements(char **arrayName);
int select_columns(int *columns);
void free_memory(struct UserData *users,int rowCount);
void create_user(struct UserData *user);
void initialize_read_arrays();
void select_output_filename(char *filename, int max_length);
void select_row_count(int *rowCount);
void summarize(int *columns, int rowCount, char *filename, int count_columns);


#endif //COMP348_TABLEGEN_H
