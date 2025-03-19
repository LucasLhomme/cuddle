/*
** EPITECH PROJECT, 2025
** G-AIA-200-LIL-2-1-cuddle-lucas.lhomme
** File description:
** info_csv
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "my_strings.h"
#include "dataframe.h"

void df_info(dataframe_t *dataframe)
{
    const char *type_names[] = {"bool", "int", "unsigned int",
        "float", "string", "undefined"};
    const char *type_str;

    if (!dataframe)
        return;
    printf("%i columns:\n", dataframe->nb_columns);
    for (int i = 0; i < dataframe->nb_columns; i++) {
        type_str = type_names[dataframe->column_types[i]];
        if (!dataframe->column_names[i])
            return;
        printf("- %s: %s\n", dataframe->column_names[i],
            type_str);
    }
    return;
}
