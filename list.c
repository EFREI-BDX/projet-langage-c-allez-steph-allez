//
// Created by glede on 25/03/2024.
//

#include "list.h"

CDataFrame* create_CDataFrame() {
    CDataFrame* df = (CDataFrame*)malloc(sizeof(CDataFrame));
    df->columns = (Column*)malloc( sizeof(Column));
    df->num_columns = 0;
    df->num_rows = 0;
    return df;
}

void free_CDataFrame(CDataFrame* df) {
    for (int i = 0; i < df->num_columns; i++) {
        free(df->columns[i].name);
        free(df->columns[i].data);
    }
    free(df->columns);
    free(df);


void add_column(CDataFrame* df, char* name, int* data, int size) {
    if (df->num_columns == df->capacity){
        if (df->num_columns == 0){
            df->capacity += 1;
        }
        df->capacity *= 2;
        df->columns = (Column*)realloc(df->columns, df->capacity * sizeof(Column));
    }

    int index = df->num_columns;
    df->columns[index].name = strdup(name);
    df->columns[index].data = (int*)malloc(size * sizeof(int));
    df->columns[index].size = size;
    for (int i = 0; i < size; i++) {
        df->columns[index].data[i] = data[i];
    }
    df->num_columns++;
    if (size > df->num_rows){
        df->num_rows = size;
    }
}

void print_CDataFrame(CDataFrame* df) {
    for (int i = 0; i < df->num_columns; i++) {
        printf("%s\t", df->columns[i].name);
    }
    printf("\n");
    int max_rows = df->num_rows;
    for (int i = 0; i < max_rows; i++) {
        for (int j = 0; j < df->num_columns; j++) {
            if (i < df->columns[j].size) {
                printf("%d\t", df->columns[j].data[i]);
            } else {
                printf("\t");
            }
        }
        printf("\n");
    }
}




