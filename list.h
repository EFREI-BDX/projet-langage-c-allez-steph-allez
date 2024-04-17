//
// Created by glede on 25/03/2024.
//

#ifndef PROJET_LANGAGE_C_LIST_H
#define PROJET_LANGAGE_C_LIST_H


typedef struct {
    char *title;
    int *data;
    size_t size;
} Colonne;

typedef struct {
    Colonne *colonne;
    size_t num_colonne;
    size_t max_size;
} CDataframe;

void init_colonne(Colonne *colonne, const char *title,size_t size);
void free_colonne(Colonne *colonne);
CDataframe* init_cdataframe(size_t num_colonne,size_t max_size);
void free_cdataframe(CDataframe *dataframe);

#endif //PROJET_LANGAGE_C_LIST_H