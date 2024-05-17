//
// Created by louis on 17/05/2024.
//

#ifndef PROJET_LANGAGE_C_COLUMN_H
#define PROJET_LANGAGE_C_COLUMN_H
#define PHYSICAL_SIZE 64
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int value;
    struct Data* next_value;
} Data;

typedef struct {
    char* title;
    int physical_size;
    int logical_size;
    int* values;
} Column;

Column* create_column(char* title);

void add_value(Column* column, int value);
void delete_column(Column** column);

void print_column(Column* column);


#endif //PROJET_LANGAGE_C_COLUMN_H
