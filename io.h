
#ifndef COMP348_IOO_H
#define COMP348_IOO_H
/*
extern int rowCount;
extern int arrayID[rowCount]; // Declare the global variable
*/

extern int *arrayID; // Declare a pointer to an int array
extern char *firstNames;

void read_file(char *filename, int maxRows, char **buffer);

void write_file(char *filename, int *columns, int rowCount);

#endif //COMP348_IOO_H



