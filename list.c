//
// Created by glede on 25/03/2024.
//

#include "list.h"

CDataFrame* create_CDataFrame(int num_columns) {
    CDataFrame* df = (CDataFrame*)malloc(sizeof(CDataFrame));
    df->columns = (Column*)malloc(num_columns * sizeof(Column));
    df->num_columns = num_columns;
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
    int index = df->num_columns;
    df->columns[index].name = strdup(name);
    df->columns[index].data = (int*)malloc(size * sizeof(int));
    df->columns[index].size = size;
    for (int i = 0; i < size; i++) {
        df->columns[index].data[i] = data[i];
    }
    df->num_columns++;
}

void print_CDataFrame(CDataFrame* df) {
    for (int i = 0; i < df->num_columns; i++) {
        printf("%s\t", df->columns[i].name);
    }
    printf("\n");

    int max_rows = 0;
    for (int i = 0; i < df->num_columns; i++) {
        if (df->columns[i].size > max_rows) {
            max_rows = df->columns[i].size;
        }
    }

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




