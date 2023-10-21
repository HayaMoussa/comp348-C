// Include guards
#ifndef COMP348_GENERATE_H
#define COMP348_GENERATE_H

#define MAX_NAMES 1000
#define MAX_COUNTRIES 195
#define MAX_FILE_NAME 255

// Libraries
#include <stdio.h>
#include <stdlib.h> //for rand()
#include <string.h>

#include "tablegen.h"

// Global variables
extern int *arrayID; // Declare a pointer to an int array
extern char **arrayFirstName;
extern char **arrayLastName;
extern char **arrayCountry;

int generate_random_number(int max);

int generate_userID();

char *generate_element(char **arrayName, int max); // For first name, last name and country

char *generate_phone_number(char **arrayName, int max);

char *generate_email(char* first_name, char* last_name, char** email_suffixes, int max);

char *generate_SIN(struct UserData *users, int max);

char *generate_password(int min_length, int max_length);

#endif





/* Prototypes for the functions */
/*void test(int *columns);

void generate_userID(int rowCount);

char *selectRandomElement(char **names, int count);

void generate_lastName();

void generate_country();

void generate_phoneNumber();

void generate_email();

void generate_SIN();

void generate_password();

*/