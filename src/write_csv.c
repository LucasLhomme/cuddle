/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** write_csv
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "dataframe.h"

static void write_row(FILE *file, dataframe_t *dataframe, int row)
{
    for (int j = 0; j < dataframe->nb_columns; j++) {
        fprintf(file, "%s", (char *)dataframe->data[row][j]);
        if (j < dataframe->nb_columns - 1)
            fprintf(file, "%s", dataframe->sep);
    }
    if (row < dataframe->nb_rows - 1)
        fprintf(file, "\n");
}

int df_write_csv(dataframe_t *dataframe, const char *filename)
{
    FILE *file = fopen(filename, "w");

    if (!dataframe)
        return 84;
    if (!file)
        return 84;
    for (int i = 0; i < dataframe->nb_columns; i++) {
        fprintf(file, "%s", dataframe->column_names[i]);
        if (i < dataframe->nb_columns - 1)
            fprintf(file, "%s", dataframe->sep);
    }
    fprintf(file, "\n");
    for (int i = 0; i < dataframe->nb_rows; i++)
        write_row(file, dataframe, i);
    fclose(file);
    return 0;
}
