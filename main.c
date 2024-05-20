#include <stdio.h>
#include "CDataFrame.h"

int main() {
    CDataFrame* df = create_CDataFrame();
/**
    CDataFrame* df = create_CDataFrame();

    Column* col1 = create_column("Column 1");
    add_value(col1, 10);
    add_value(col1, 20);
    add_value(col1, 30);

    Column* col2 = create_column("Column 2");
    add_value(col2, 100);
    add_value(col2, 200);

    Column* col3 = create_column("Column 3");
    add_value(col3, 1000);
    add_value(col3, 2000);

    add_column(df, col1);
    add_column(df, col2);
    add_column(df, col3);

    remove_column(df, "Column 2");
    remove_row(df, 0);
    int row[3] = {25, 50, 30};
    add_row(df, row);
    rename_column(df, "Column 3", "Last column");
    replace_value_at(df, 0,0, 69);
    print_CDataFrame(df);
    print_column(df, "Last column");
    print_row(df, 0);
    int booleens;
    booleens = contains_value(df, 2000);
    printf("%d\n", booleens);
    print_column_names(df);
    int a, b, c, d, e;
    a = count_rows(df);
    b = count_columns(df);
    c = count_cells_with_value(df, 30);
    d = count_cells_greater_than(df, 55);
    e = count_cells_lower_than(df, 55);
    printf("%d\t%d\t%d\t%d\t%d\t", a, b, c, d, e);
    free_CDataFrame(df);
**/
    int choice;
    printf("\nMenu:\n");
    printf("1. Ajouter une colonne\n");
    printf("2. Supprimer une colonne\n");
    printf("3. Ajouter une valeur\n");
    printf("4. Supprimer une ligne\n");
    printf("5. Afficher le nombre de lignes\n");
    printf("6. Afficher le nombre de colonnes\n");
    printf("7. Afficher les noms de colonnes\n");
    printf("8. Afficher le CDataFrame\n");
    printf("9. Quitter\n");
    while (1) {
        rewind(stdin);
        printf("Entrez votre choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                // Ajouter une colonne
                char title[100];
                rewind(stdin);
                printf("Entrez le titre de la colonne : ");
                scanf("%s", title);
                Column* column = create_column(title);
                add_column(df, column);
                printf("Colonne ajoutée avec succès.\n");
                break;
            }
            case 2: {
                // Supprimer une colonne
                char title[100];
                rewind(stdin);
                printf("Entrez le titre de la colonne à supprimer : ");
                scanf("%s", title);
                remove_column(df, title);
                printf("Colonne supprimée avec succès.\n");
                break;
            }
            case 3: {
                // Ajouter une ligne
                printf("Entrez l'indice de la colonne : \n");
                int index;
                scanf("%d", &index);
                int size;
                printf("Entrez le nombre de valeurs que vous voulez :\n");
                rewind(stdin);
                scanf("%d", &size);
                int number;
                for (int i; i < size; i++){
                    printf("Saisir la valeur %d : \n", i+1);
                    rewind(stdin);
                    scanf("%d", &number);
                    add_value_at(df, index, number);
                }
                break;
            }
            case 4: {
                // Supprimer une ligne
                // Code pour saisir l'index de la ligne et appeler remove_row
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
                // Quitter
                printf("Au revoir !\n");
                free_CDataFrame(df);
                return 0;
            }
            default: {
                printf("Choix invalide. Veuillez entrer un nombre entre 1 et 9.\n");
                break;
            }
        }
    }

    return 0;
}
