#include <stdio.h>
#include "CDataFrame.h"

int main() {
    CDataFrame* df = create_CDataFrame();
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Ajouter une colonne\n");
        printf("2. Supprimer une colonne\n");
        printf("3. Ajouter une ligne\n");
        printf("4. Supprimer une ligne\n");
        printf("5. Afficher le nombre de lignes\n");
        printf("6. Afficher le nombre de colonnes\n");
        printf("7. Afficher les noms de colonnes\n");
        printf("8. Afficher le CDataFrame\n");
        printf("9. Afficher une ligne\n");
        printf("10. Ajouter une valeur à une colonne\n");
        printf("11. Quitter\n");
        printf("Entrez votre choix : ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                // Ajouter une colonne
                char title[100];
                printf("Entrez le titre de la colonne : ");
                if (scanf("%99s", title) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                Column* column = create_column(title);
                add_column(df, column);
                printf("Colonne ajoutée avec succès.\n");
                break;
            }
            case 2: {
                // Supprimer une colonne
                char title[100];
                printf("Entrez le titre de la colonne à supprimer : ");
                if (scanf("%99s", title) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                remove_column(df, title);
                printf("Colonne supprimée avec succès.\n");
                break;
            }
            case 3: {
                // Ajouter une ligne
                int num_columns = count_columns(df);
                int* values = (int*)malloc(num_columns * sizeof(int));
                for (int i = 0; i < num_columns; i++) {
                    printf("Entrez la valeur pour la colonne %d : ", i + 1);
                    if (scanf("%d", &values[i]) != 1) {
                        while (getchar() != '\n');
                        free(values);
                        continue;
                    }
                }
                while (getchar() != '\n'); // Vider le tampon après la saisie des valeurs
                add_row(df, values);
                free(values);
                printf("Ligne ajoutée avec succès.\n");
                break;
            }
            case 4: {
                // Supprimer une ligne
                int row_index;
                printf("Entrez l'index de la ligne à supprimer : ");
                if (scanf("%d", &row_index) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                remove_row(df, row_index);
                printf("Ligne supprimée avec succès.\n");
                break;
            }
            case 5: {
                // Afficher le nombre de lignes
                printf("Nombre de lignes : %d\n", count_rows(df));
                break;
            }
            case 6: {
                // Afficher le nombre de colonnes
                printf("Nombre de colonnes : %d\n", count_columns(df));
                break;
            }
            case 7: {
                // Afficher les noms de colonnes
                print_column_names(df);
                break;
            }
            case 8: {
                // Afficher le CDataFrame
                print_CDataFrame(df);
                break;
            }
            case 9: {
                // Afficher une ligne
                int row_index;
                printf("Entrez l'index de la ligne à afficher : ");
                if (scanf("%d", &row_index) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                print_row(df, row_index);
                break;
            }
            case 10: {
                // Ajouter une valeur à une colonne
                int col_index, value;
                printf("Entrez l'index de la colonne : ");
                if (scanf("%d", &col_index) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                printf("Entrez la valeur à ajouter : ");
                if (scanf("%d", &value) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                add_value_at(df, col_index, value);
                printf("Valeur ajoutée avec succès.\n");
                break;
            }
            case 11: {
                // Quitter
                printf("Au revoir !\n");
                free_CDataFrame(df);
                return 0;
            }
            default: {
                printf("Choix invalide. Veuillez entrer un nombre entre 1 et 11.\n");
                while (getchar() != '\n');  // Vider le tampon en cas de saisie invalide
                break;
            }
        }
    }
    return 0;
}
