
#ifndef COMP348_IOO_H
#define COMP348_IOO_H
/*
extern int rowCount;
extern int arrayID[rowCount]; // Declare the global variable
*/

void read_file(char *filename, int maxRows, char buffer[maxRows]);

void write_file(char *filename, int *columns, int rowCount);

#endif //COMP348_IOO_H



