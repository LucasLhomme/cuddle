/*
** EPITECH PROJECT, 2025
** G-AIA-200-LIL-2-1-cuddle-lucas.lhomme
** File description:
** info_csv
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "dataframe.h"

void print_type(int type)
{
    const char *types[] = { "bool", "int", "unsigned int",
        "float", "string", "unknown" };

    printf("%s\n", (type >= BOOL && type <= STRING) ? types[type] : types[5]);
}

void df_info(dataframe_t *dataframe, int nb_rows)
{
    int rows_to_print = (nb_rows > dataframe->nb_rows) ?
    dataframe->nb_rows : nb_rows;

    if (!dataframe || nb_rows <= 0)
        return;
    printf("%d rows:\n", rows_to_print);
    for (int i = 0; i < rows_to_print; i++) {
        printf("- %s: ", dataframe->column_names[i]);
        print_type(dataframe->column_types[i]);
    }
}
