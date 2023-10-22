
/*********************************
 * generate.h
 */

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

// Forward declaration for struct UserData
struct UserData;
//#include "tablegen.h" // for struct

int generate_random_number(int max);
int generate_userID();
char *generate_element(char **arrayName, int max); // For first name, last name and country
char *generate_phone_number(char **arrayName, int max);
char *generate_email(char* first_name, char* last_name, char** email_suffixes, int max);
char *generate_SIN(struct UserData *users, int max);
char *generate_password(int min_length, int max_length);

#endif
