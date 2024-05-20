//
// Created by glede on 25/03/2024.
//

#ifndef PROJET_LANGAGE_C_CDATAFRAME_H
#define PROJET_LANGAGE_C_CDATAFRAME_H

#include "column.h"



// Structure pour représenter le CDataFrame



// Structure pour représenter le CDataFrame
typedef struct {
    Column* current_column;
    struct Maillon* next_maillon;
} Maillon;

typedef Maillon* CDataFrame;

CDataFrame* create_CDataFrame();
void add_column(CDataFrame* df, Column* column);
void remove_column(CDataFrame* df, char* title);
void add_row(CDataFrame* df, int* values);
void remove_row(CDataFrame* df, int row_index);
void free_CDataFrame(CDataFrame* df);
void print_CDataFrame(CDataFrame* df);
void print_column(CDataFrame* df, char* name);
void rename_column(CDataFrame* df, char* name, char* new_name);
int contains_value(CDataFrame* df, int value);
void replace_value(CDataFrame* df, int old_value, int new_value);

#endif //PROJET_LANGAGE_C_CDATAFRAME_H