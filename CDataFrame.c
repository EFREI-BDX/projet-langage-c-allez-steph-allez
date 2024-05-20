//
// Created by glede on 25/03/2024.
//

#include "CDataFrame.h"


CDataFrame* create_CDataFrame() {
    CDataFrame *df = (CDataFrame *) malloc(sizeof(CDataFrame));
    *df = NULL;
    return df;
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

// Opérations usuelles

void add_column(CDataFrame* df, Column* column) {
    Maillon* new_maillon = (Maillon*)malloc(sizeof(Maillon));
    new_maillon->current_column = column;
    new_maillon->next_maillon = NULL;
    if (*df == NULL) {
        *df = new_maillon;
    } else {
        Maillon* current = *df;
        while (current->next_maillon != NULL) {
            current = current->next_maillon;
        }
        current->next_maillon = new_maillon;
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

void add_value_at(CDataFrame* df, int column_index, int value) {
    Maillon* current = *df;
    int col_counter = 0;

    while (current != NULL) {
        if (col_counter == column_index) {
            add_value(current->current_column, value);  // Appel à la fonction add_value de la colonne actuelle
            return;
        }
        col_counter++;
        current = current->next_maillon;
    }

    printf("Colonne index hors limites.\n");
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

int contains_value(CDataFrame* df, int value) {
    Maillon* current = *df;
    while (current != NULL) {
        Column* column = current->current_column;
        for (int i = 0; i < column->logical_size; i++) {
            if (column->values[i] == value) {
                return 0;
            }
        }
        current = current->next_maillon;
    }
    return -1;
}

Column* get_column_by_index(CDataFrame* df, int col_index) {
    Maillon* temp = *df;
    int current_index = 0;
    while (temp != NULL) {
        if (current_index == col_index) {
            return temp->current_column;
        }
        current_index++;
        temp = temp->next_maillon;
    }
    return NULL;  // Return NULL if the index is out of bounds
}

void replace_value_at(CDataFrame* df, int column_index, int row_index, int new_value) {
    Maillon* current = *df;
    int col_counter = 0;
    while (current != NULL) {
        if (col_counter == column_index) {
            Column* column = current->current_column;
            if (row_index >= 0 && row_index < column->logical_size) {
                column->values[row_index] = new_value;
                return;
            } else {
                printf("Row index out of bounds for column '%s'.\n", column->title);
                return;
            }
        }
        col_counter++;
        current = current->next_maillon;
    }
    printf("Column index out of bounds.\n");
}

// Affichage

void print_CDataFrame(CDataFrame* df) {
    if (*df == NULL){
        printf("CDataFrame is empty.\n");
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

void print_row(CDataFrame* df, int row_index) {
    Maillon* current = *df;

    while (current != NULL) {
        Column* column = current->current_column;
        if (row_index < column->logical_size) {
            printf("%-15d", column->values[row_index]);  // Imprimer la valeur de la colonne à l'index de ligne
        } else {
            printf("%-15s", "");  // Laisser un espace vide si la colonne ne comprend pas de valeur sur la ligne donnée
        }
        current = current->next_maillon;
    }
    printf("\n");
}

void print_column_names(CDataFrame* df) {
    Maillon* current = *df;
    int column_index = 1;
    while (current != NULL) {
        printf("%d-%s\n", column_index, current->current_column->title);
        column_index++;
        current = current->next_maillon;
    }
}

// Analyses et statistiques :

int count_rows(CDataFrame* df) {
    Maillon* current = *df;
    int max_rows = 0;
    while (current != NULL) {
        if (current->current_column->logical_size > max_rows) {
            max_rows = current->current_column->logical_size;
        }
        current = current->next_maillon;
    }
    return max_rows;
}

int count_columns(CDataFrame* df) {
    Maillon* current = *df;
    int num_columns = 0;
    while (current != NULL) {
        num_columns++;
        current = current->next_maillon;
    }
    return num_columns;
}

int count_cells_with_value(CDataFrame* df, int value) {
    Maillon* current = *df;
    int count = 0;
    while (current != NULL) {
        Column* column = current->current_column;
        for (int i = 0; i < column->logical_size; i++) {
            if (column->values[i] == value) {
                count++;
            }
        }
        current = current->next_maillon;
    }
    return count;
}

int count_cells_lower_than(CDataFrame* df, int value) {
    Maillon* current = *df;
    int count = 0;
    while (current != NULL) {
        Column* column = current->current_column;
        for (int i = 0; i < column->logical_size; i++) {
            if (column->values[i] < value) {
                count++;
            }
        }
        current = current->next_maillon;
    }
    return count;
}

int count_cells_greater_than(CDataFrame* df, int value) {
    Maillon* current = *df;
    int count = 0;
    while (current != NULL) {
        Column* column = current->current_column;
        for (int i = 0; i < column->logical_size; i++) {
            if (column->values[i] > value) {
                count++;
            }
        }
        current = current->next_maillon;
    }
    return count;
}
