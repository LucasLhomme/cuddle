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

column_type_t detect_type(const char *value) {
    int is_float = 0;
    int start = 0;

    if (value[0] == '-')
        start = 1;
    for (int i = start; value[i] != '\0'; i++) {
        if (value[i] == '.' && !is_float) {
            is_float = 1;
        } else if (!isdigit(value[i])) {
            if (strcasecmp(value, "true") == 0 || strcasecmp(value, "false") == 0)
                return BOOL;
            return STRING;
        }
    }
    if (start == 1 && is_float == 0){
        return INT;
    }
    return is_float ? FLOAT : UINT;
}

void df_info(dataframe_t *dataframe)
{
    const char *type_names[] = {"bool", "int", "unsigned int", "float", "string", "undefined"};
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
