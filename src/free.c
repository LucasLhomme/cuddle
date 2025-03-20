/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_free
*/

#include <stdlib.h>

#include "dataframe.h"

static void free_line(void **line)
{
    for (int i = 0; line[i]; i++) {
        if (line[i]) {
            free(line[i]);
            line[i] = NULL;
        }
    }
    free(line);
    line = NULL;
}

void free_data(void ***data)
{
    for (int i = 0; data[i]; i++) {
        for (int j = 0; data[i][j]; j++)
            free(data[i][j]);
        free(data[i]);
    }
    free(data);
}

void df_free(dataframe_t *df)
{
    for (int i = 0; i < df->nb_rows; i++) {
        if (!df->data[i])
            free_line(df->data[i]);
    }
    free_data(df->data);
    free(df->sep);
    for (int i = 0; i < df->nb_columns; i++) {
        if (df->column_names[i]) {
            free(df->column_names[i]);
            df->column_names[i] = NULL;
        }
    }
    free(df->column_names);
    if (df->column_types) {
        free(df->column_types);
        df->column_types = NULL;
    }
    free(df);
}
