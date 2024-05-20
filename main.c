#include <stdio.h>
#include "CDataFrame.h"

int main() {
    CDataFrame* df = create_CDataFrame();
    int choice;
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
    printf("10. Ajouter une valeur a une colonne\n");
    printf("11. Renommer une colonne\n");
    printf("12. Verifier si une valeur existe dans le CDataFrame\n");
    printf("13. Remplacer une valeur dans une colonne\n");
    printf("14. Compter les cellules avec une valeur spécifique\n");
    printf("15. Compter les cellules avec des valeurs inférieures a une valeur\n");
    printf("16. Compter les cellules avec des valeurs supérieures a une valeur\n");
    printf("17. Quitter\n");
    while (1) {

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
                printf("Colonne ajoutee avec succes.\n");
                break;
            }
            case 2: {
                // Supprimer une colonne
                char title[100];
                printf("Entrez le titre de la colonne a supprimer : ");
                if (scanf("%99s", title) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                remove_column(df, title);
                printf("Colonne supprimee avec succes.\n");
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
                while (getchar() != '\n');
                add_row(df, values);
                free(values);
                printf("Ligne ajoutee avec succes.\n");
                break;
            }
            case 4: {
                // Supprimer une ligne
                int row_index;
                printf("Entrez l'index de la ligne a supprimer : ");
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
                printf("Entrez l'index de la ligne a afficher : ");
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
                printf("Entrez la valeur a ajouter : ");
                if (scanf("%d", &value) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                add_value_at(df, col_index, value);
                printf("Valeur ajoutée avec succes.\n");
                break;
            }
            case 11: {
                // Renommer une colonne
                char* col_name;
                char new_name[100];
                printf("Entrez l'index de la colonne a renommer : ");
                if (scanf("%s", col_name) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                printf("Entrez le nouveau nom de la colonne : ");
                if (scanf("%99s", new_name) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                rename_column(df, col_name, new_name);
                printf("Colonne renommee avec succes.\n");
                break;
            }
            case 12: {
                // Vérifier si une valeur existe dans le CDataFrame
                int value;
                printf("Entrez la valeur a rechercher : ");
                if (scanf("%d", &value) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                int found = contains_value(df, value);
                if (found) {
                    printf("Valeur trouvee.\n");
                } else {
                    printf("Valeur non trouvee.\n");
                }
                break;
            }
            case 13: {
                // Remplacer une valeur dans une colonne
                int col_index, row_index, new_value;
                printf("Entrez l'index de la colonne : ");
                if (scanf("%d", &col_index) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                printf("Entrez l'index de la ligne : ");
                if (scanf("%d", &row_index) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                printf("Entrez la nouvelle valeur : ");
                if (scanf("%d", &new_value) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                replace_value_at(df, col_index, row_index, new_value);
                printf("Valeur remplacee avec succes.\n");
                break;
            }
            case 14: {
                // Compter les cellules avec une valeur spécifique
                int value;
                printf("Entrez la valeur a compter : ");
                if (scanf("%d", &value) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                int count = count_cells_with_value(df, value);
                printf("Nombre de cellules avec la valeur %d : %d\n", value, count);
                break;
            }
            case 15: {
                // Compter les cellules avec des valeurs inférieures à une valeur
                int value;
                printf("Entrez la valeur seuil : ");
                if (scanf("%d", &value) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                int count = count_cells_lower_than(df, value);
                printf("Nombre de cellules avec une valeur inférieure a %d : %d\n", value, count);
                break;
            }
            case 16: {
                // Compter les cellules avec des valeurs supérieures à une valeur
                int value;
                printf("Entrez la valeur seuil : ");
                if (scanf("%d", &value) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                int count = count_cells_greater_than(df, value);
                printf("Nombre de cellules avec une valeur supérieure a %d : %d\n", value, count);
                break;
            }
            case 17: {
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
