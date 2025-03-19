/*
** EPITECH PROJECT, 2025
** G-AIA-200-LIL-2-1-cuddle-lucas.lhomme
** File description:
** info_csv
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_strings.h"
#include "dataframe.h"

column_type_t detect_type(const char *value)
{
    int is_float = 0;

    for (int i = 0; value[i] != '\0'; i++) {
        if (value[i] == '.' && !is_float) {
            is_float = 1;
        } else if (!isdigit(value[i])) {
            return STRING;
        }
    }
    return is_float ? FLOAT : UINT;
}

void df_info(dataframe_t *dataframe)
{
    if (!dataframe)
        return;
    printf("%d columns:\n", dataframe->nb_columns);
    for (int i = 0; i < dataframe->nb_columns; i++) {
        printf("- %s: ", dataframe->column_names[i]);
        print_type(dataframe->column_types[i]);
    }
}