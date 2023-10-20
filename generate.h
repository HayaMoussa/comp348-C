// TODO: Remove global function, no need.
//extern int *columns;

// Include guards
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

extern int *arrayID; // Declare a pointer to an int array
extern char *arrayFirstName;

/* Prototypes for the functions */
void test(int *columns);

void generate_userID(int rowCount);

void generate_firstName(int rowCount);

void generate_lastName();

void generate_country();

void generate_phoneNumber();

void generate_email();

void generate_SIN();

void generate_password();

int generate_randomNumber(int min, int max);
#endif
