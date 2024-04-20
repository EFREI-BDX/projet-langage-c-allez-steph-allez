//
// Created by glede on 25/03/2024.
//

#include "list.h"

void init_colonne(Colonne *colonne,const char *title, size_t size){
    colonne->title = strdup(title);
    colonne->data = malloc(size * sizeof(int));
    colonne->size = size;

}

void free_colonne(Colonne * colonne) {
    free(colonne ->title);
    free(colonne->data);
}

CDataframe* init_cdataframe(size_t num_colonne, size_t max_size){
    CDataframe *dataframe = malloc(sizeof(CDataframe));
    dataframe->colonne = malloc(num_colonne * sizeof(Colonne));
    dataframe->num_colonne = num_colonne;
    dataframe->max_size = max_size;

    for (size_t i=0; i< num_colonne;i++){
        char title[20];
        sprintf(title,"Colonne %zu", i+1);
        init_colonne(&(dataframe->colonne[i]), title, max_size);
    }

    return dataframe;


}

