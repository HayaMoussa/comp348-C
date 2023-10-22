
/*********************************
 * io.h
 */
#ifndef COMP348_IOO_H
#define COMP348_IOO_H

// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// User-defined
#include "generate.h"
#include "io.h"
#include "tablegen.h"

void read_file(char *filename, int maxRows, char **array);

void write_file(const char *filename, const int *columns, struct UserData *users, int row_count, int count_columns);

#endif



