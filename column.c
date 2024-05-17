//
// Created by louis on 17/05/2024.
//

#include "column.h"
Column* create_column(char* title){
    Column* column = (Column*) malloc(sizeof(Column));
    column->title = strdup(title);
    column->physical_size = 64;
    column->logical_size = 0;
    column->values = (int*) malloc(PHYSICAL_SIZE*sizeof(int));
    return column;
}

void add_value(Column* column, int value){
    if (column->physical_size == column->logical_size){
        column->values = (int*) realloc(column->values, PHYSICAL_SIZE*sizeof(int));
        column->physical_size += PHYSICAL_SIZE;
    }
    int index = column->logical_size;
    column->values[index] = value;
    column->logical_size++;
}

void delete_value_at_index(Column* column, int index){
    if (index < column->logical_size){
        int temp = index;
        while (temp < column->logical_size-1){
            column->values[temp] = column->values[temp+1];
            temp++;
        }
        column->logical_size --;
    }
}

void print_column(Column* column){
    printf("%s\n", column->title);
    for (int i = 0; i < column->logical_size; i++){
        printf("%d\n", column->values[i]);
    }
};