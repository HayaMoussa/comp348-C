// TODO: Remove global function, no need.
//extern int *columns;

// Include guards
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#define MAX_NAMES 1000
#define MAX_COUNTRIES 195

extern int *arrayID; // Declare a pointer to an int array
extern char **arrayFirstName;
extern char **arrayLastName;
extern char **arrayCountry;


/* Prototypes for the functions */
void test(int *columns);

void generate_userID(int rowCount);

char *selectRandomElement(char **names, int count);

void generate_lastName();

void generate_country();

void generate_phoneNumber();

void generate_email();

void generate_SIN();

void generate_password();

#endif
