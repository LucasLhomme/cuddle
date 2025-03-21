/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** get_values
*/

#include <stdlib.h>
#include <string.h>

#include "dataframe.h"

static int my_strarray_index(void **array, void *value)
{
    if (!array)
        return -1;
    for (int i = 0; array[i]; i++) {
        if (strcmp(array[i], value) == 0)
            return i;
    }
    return -1;
}

static int df_get_column_index(dataframe_t *df, const char *column)
{
    for (int i = 0; i < df->nb_columns; i++) {
        if (!strcmp(df->column_names[i], column))
            return i;
    }
    return -1;
}

static void *df_get_value_by_index(dataframe_t *df, int row, int column)
{
    if (row < 0 || row >= df->nb_rows ||
        column < 0 || column >= df->nb_columns)
        return NULL;
    return strdup(df->data[row][column]);
}

void *df_get_value(dataframe_t *df, int row, const char *column)
{
    int column_index = df_get_column_index(df, column);

    if (column_index == -1)
        return NULL;
    return df_get_value_by_index(df, row, column_index);
}

void **df_get_values(dataframe_t *df, const char *column)
{
    int column_index = df_get_column_index(df, column);
    void **values = malloc(sizeof(void *) * (df->nb_rows + 1));

    if (!values)
        return NULL;
    for (int i = 0; i < df->nb_rows; i++)
        values[i] = df_get_value_by_index(df, i, column_index);
    values[df->nb_rows] = NULL;
    return values;
}

void **df_get_unique_values(dataframe_t *df, const char *column)
{
    int column_index = df_get_column_index(df, column);
    void **values = malloc(sizeof(void *) * (df->nb_rows + 1));
    int index = 0;

    if (!values)
        return NULL;
    for (int i = 0; i <= df->nb_rows; i++)
        values[i] = NULL;
    for (int i = 0; i < df->nb_rows; i++) {
        if (my_strarray_index(values, df->data[i][column_index]) == -1) {
            values[index] = df_get_value_by_index(df, i, column_index);
            index++;
        }
    }
    values[index] = NULL;
    return values;
}
