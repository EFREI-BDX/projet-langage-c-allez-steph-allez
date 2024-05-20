//
// Created by glede on 25/03/2024.
//

#ifndef PROJET_LANGAGE_C_CDATAFRAME_H
#define PROJET_LANGAGE_C_CDATAFRAME_H

#include "column.h"

// Structure pour représenter le CDataFrame
typedef struct {
    Column* current_column;
    struct Maillon* next_maillon;
} Maillon;

typedef Maillon* CDataFrame;

CDataFrame* create_CDataFrame();
void free_CDataFrame(CDataFrame* df);

//Opérations usuelles
void add_column(CDataFrame* df, Column* column);
void remove_column(CDataFrame* df, char* title);
void add_value_at(CDataFrame* df, int column_index, int value);
void add_row(CDataFrame* df, int* values);
void remove_row(CDataFrame* df, int row_index);
void rename_column(CDataFrame* df, char* name, char* new_name);
int contains_value(CDataFrame* df, int value);
void replace_value_at(CDataFrame* df, int column_index, int row_index, int new_value);

// Affichage
void print_CDataFrame(CDataFrame* df);
void print_column(CDataFrame* df, char* name);
void print_row(CDataFrame* df, int row_index);
void print_column_names(CDataFrame* df);


// Analyses et statistiques
int count_rows(CDataFrame* df);
int count_columns(CDataFrame* df);
int count_cells_with_value(CDataFrame* df, int value);
int count_cells_lower_than(CDataFrame* df, int value);
int count_cells_greater_than(CDataFrame* df, int value);

#endif //PROJET_LANGAGE_C_CDATAFRAME_H