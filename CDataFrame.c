//
// Created by glede on 25/03/2024.
//

#include "CDataFrame.h"


CDataFrame* create_CDataFrame() {
    CDataFrame *df = (CDataFrame *) malloc(sizeof(CDataFrame));
    *df = NULL;
    return df;
}

void add_column(CDataFrame* df, Column* column) {
    Maillon* new_maillon = (Maillon*)malloc(sizeof(Maillon));
    new_maillon->current_column = column;
    new_maillon->next_maillon = NULL;

    if (*df == NULL) {
        *df = new_maillon;
    } else {
        Maillon* temp = *df;
        while (temp->next_maillon != NULL) {
            temp = temp->next_maillon;
        }
        temp->next_maillon = new_maillon;
    }
}
void remove_column(CDataFrame* df, char* title) {
    if (*df == NULL) return;

    Maillon* current = *df;
    Maillon* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->current_column->title, title) == 0) {
            if (prev == NULL) {
                // The column to remove is the first one
                *df = current->next_maillon;
            } else {
                // The column to remove is in the middle or end
                prev->next_maillon = current->next_maillon;
            }

            free(current->current_column->title);
            free(current->current_column->values);
            free(current->current_column);
            free(current);
            return;
        }
        prev = current;
        current = current->next_maillon;
    }
}

void add_row(CDataFrame* df, int* values) {
    Maillon* current = *df;
    int index = 0;

    while (current != NULL) {
        add_value(current->current_column, values[index]);
        current = current->next_maillon;
        index++;
    }
}

void remove_row(CDataFrame* df, int row_index) {
    Maillon* current = *df;

    while (current != NULL) {
        delete_value_at_index(current->current_column, row_index);
        current = current->next_maillon;
    }
}

void print_CDataFrame(CDataFrame* df) {
    if (*df == NULL){
        printf("Le CDataFrame est vide.\n");
    }

    Maillon* current = *df;
    int max_rows = 0;
    while (current != NULL) {
        if (current->current_column->logical_size > max_rows) {
            max_rows = current->current_column->logical_size;
        }
        current = current->next_maillon;
    }

    current = *df;
    while (current != NULL) {
        printf("%-15s", current->current_column->title);  // Adjust width as needed
        current = current->next_maillon;
    }
    printf("\n");

    for (int i = 0; i < max_rows; i++) {
        current = *df;
        while (current != NULL) {
            if (i < current->current_column->logical_size) {
                printf("%-15d", current->current_column->values[i]);
            } else {
                printf("%-15s", "");
            }
            current = current->next_maillon;
        }
        printf("\n");
    }
}

void print_column(CDataFrame* df, char* name) {
    Maillon* current = *df;

    while (current != NULL) {
        if (strcmp(current->current_column->title, name) == 0) {
            print_column_values(current->current_column);
            return;
        }
        current = current->next_maillon;
    }
    printf("Column with title '%s' not found.\n", name);
}

void rename_column(CDataFrame* df, char* name, char* new_name) {
    Maillon* current = *df;

    while (current != NULL) {
        if (strcmp(current->current_column->title, name) == 0) {
            free(current->current_column->title);
            current->current_column->title = strdup(new_name);
            return;
        }
        current = current->next_maillon;
    }
    printf("Column with title '%s' not found.\n", name);
}

void free_CDataFrame(CDataFrame* df) {
    Maillon* current = *df;
    Maillon* next;

    while (current != NULL) {
        next = current->next_maillon;
        free(current->current_column->title);
        free(current->current_column->values);
        free(current->current_column);
        free(current);
        current = next;
    }

    *df = NULL;
}

