//
// Created by glede on 25/03/2024.
//

#ifndef PROJET_LANGAGE_C_LIST_H
#define PROJET_LANGAGE_C_LIST_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure pour représenter une colonne
typedef struct {
    char* name;
    int* data;
    int size;
} Column;

// Structure pour représenter le CDataFrame
typedef struct {
    Column* columns;
    int num_columns;
    int num_rows;
} CDataFrame;

// Fonction pour créer un nouveau CDataFrame
CDataFrame* create_CDataFrame(int num_columns);

// Fonction pour libérer un CDataFrame
void free_CDataFrame(CDataFrame* df);

// Fonction pour ajouter une colonne
void add_column(CDataFrame* df, char* name, int* data, int size);

// Fonction pour ajouter une ligne
void add_row(CDataFrame* df, int* row_data);

// Fonction pour afficher un CDataFrame
void print_CDataFrame(CDataFrame* df);

#endif //PROJET_LANGAGE_C_LIST_H