
#ifndef COMP348_IOO_H
#define COMP348_IOO_H
/*
extern int rowCount;
extern int arrayID[rowCount]; // Declare the global variable
*/

extern int *arrayID; // Declare a pointer to an int array

void read_file(char *filename, int maxRows, char **array);
//void read_file(char *filename, int maxRows, char **buffer);

void write_file(const char *filename, const int *columns, const struct UserData *users, int row_count, int count_columns);
#endif //COMP348_IOO_H



