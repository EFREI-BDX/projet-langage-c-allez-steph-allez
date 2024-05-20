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
/**

// Fonction pour ajouter une ligne
void add_row(CDataFrame* df, int* row_data);

**/
#endif //PROJET_LANGAGE_C_CDATAFRAME_H