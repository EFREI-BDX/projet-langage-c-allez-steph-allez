#include <stdio.h>
#include "CDataFrame.h"

int main() {
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

    return 0;
}
