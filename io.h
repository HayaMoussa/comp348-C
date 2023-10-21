
#ifndef COMP348_IOO_H
#define COMP348_IOO_H
/*
extern int rowCount;
extern int arrayID[rowCount]; // Declare the global variable
*/
// Libraries
#include <stdio.h>
#include <stdlib.h> // for malloc
#include <string.h>

// User-defined
#include "generate.h"
#include "io.h"
#include "tablegen.h"

extern int *arrayID; // Declare a pointer to an int array

void read_file(char *filename, int maxRows, char **array);

void write_file(const char *filename, const int *columns, struct UserData *users, int row_count, int count_columns);

#endif //COMP348_IOO_H



