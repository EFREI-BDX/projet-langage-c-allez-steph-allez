#include <stdio.h>
#include "list.h"

int main() {
    // Exemple d'utilisation
    CDataFrame* df = create_CDataFrame(3);



    
    int col1_data[3] = {97, 98, 99};
    int col2_data[3] = {100, 101, 102};
    int col3_data[3] = {103, 104, 105};

    add_column(df, "Column 1", col1_data, 3);
    add_column(df, "Column 2", col2_data, 3);
    add_column(df, "Column 3", col3_data, 3);
    print_CDataFrame(df);

    free_CDataFrame(df);

    return 0;
}
