#include <stdio.h>
#include "CDataFrame.h"

int main() {
    // Exemple d'utilisation
    //CDataFrame* df = create_CDataFrame(3);

    int col1_data[3] = {1011, 98, 1056};
    int col2_data[4] = {100, 101, 102, 103};
    int col3_data[5] = {104, 105, 106,107, 108};
    int col4_data[4] = {109, 110, 111, 112};
/**
    add_column(df, "Column 1", col3_data, 5);
    add_column(df, "Column 2", col2_data, 4);
    add_column(df, "Column 3", col1_data, 3);
    for(int i = 0; i < 10; i++){
        add_column(df, "Column test", col4_data, 4);
    }
    print_CDataFrame(df);
    free_CDataFrame(df);
**/;
    Column* column = create_column("Colonne 1");
    for (int i = 0; i<10; i++){
        add_value(column, i);
    }
    print_column(column);
    delete_value_at_index(column, 5);
    print_column(column);
    return 0;
}
