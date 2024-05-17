//
// Created by glede on 25/03/2024.
//

#ifndef PROJET_LANGAGE_C_CDATAFRAME_H
#define PROJET_LANGAGE_C_CDATAFRAME_H

#include "column.h"



// Structure pour représenter une colonne


// Structure pour représenter le CDataFrame
typedef struct {
    Column* current_column;
    int size;
    struct CDataFrame* next_column;
} CDataFrame;


CDataFrame* create_CDataFrame();

/**

// Fonction pour libérer un CDataFrame
void free_CDataFrame(CDataFrame* df);

// Fonction pour ajouter une colonne
void add_column(CDataFrame* df, char* name, int* data, int size);

// Fonction pour ajouter une ligne
void add_row(CDataFrame* df, int* row_data);

// Fonction pour afficher un CDataFrame
void print_CDataFrame(CDataFrame* df);
**/
#endif //PROJET_LANGAGE_C_CDATAFRAME_H