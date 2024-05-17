//
// Created by glede on 25/03/2024.
//

#include "CDataFrame.h"


CDataFrame* create_CDataFrame() {
    CDataFrame* df = (CDataFrame*)malloc(sizeof(CDataFrame));
    df->current_column = NULL;
    df->size = 0;
    return df;
}

void free_CDataFrame(CDataFrame* df) {
    CDataFrame* temp;
    temp = df;
    if (df->current_column)
    while (temp->next_column != NULL){
        free(temp->current_column);
        temp->current_column = temp->next_column;
    }
}
/**
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

void add_value(CDataFrame* df, int value, int column){

}

void print_CDataFrame(CDataFrame* df) {
    for (int i = 0; i < df->num_columns; i++) {
        printf("C%d\t", i+1);
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
    printf("References :\n");
    for (int i = 0; i < df->num_columns; i++) {
        printf("C%d : ", i+1);
        printf("%s\t", df->columns[i].name);
    }
}



**/
