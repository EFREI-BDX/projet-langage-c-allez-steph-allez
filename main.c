#include <stdio.h>
#include "list.h"

int main() {
    // Exemple d'utilisation
    CDataFrame* df = create_CDataFrame(3);

    int col1_data[] = {1, 2, 3};
    int col2_data[] = {4, 5, 6};
    int col3_data[] = {7, 8, 9};

    add_column(df, "Column 1", col1_data, 3);
    add_column(df, "Column 2", col2_data, 3);
    add_column(df, "Column 3", col3_data, 3);

    print_CDataFrame(df);

    free_CDataFrame(df);

    return 0;
}
