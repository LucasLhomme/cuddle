/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** head
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dataframe.h"

void copy_dataframe_metadata(dataframe_t *dest,
    dataframe_t *src, int nb_rows)
{
    dest->nb_rows = nb_rows;
    dest->nb_columns = src->nb_columns;
    dest->sep = strdup(src->sep);
    dest->column_names = malloc(sizeof(char *) * (src->nb_columns + 1));
    for (int i = 0; i < src->nb_columns; i++)
        dest->column_names[i] = strdup(src->column_names[i]);
    dest->column_names[src->nb_columns] = NULL;
    dest->column_types = malloc(sizeof(int) * (src->nb_columns));
    memcpy(dest->column_types, src->column_types,
        sizeof(int) * src->nb_columns);
}

void copy_dataframe_data(dataframe_t *dest,
    dataframe_t *src, int nb_rows)
{
    dest->data = malloc(sizeof(void **) * (nb_rows + 1));
    for (int i = 0; i < nb_rows; i++) {
        dest->data[i] = malloc(sizeof(void *) * (src->nb_columns + 1));
        for (int j = 0; j < src->nb_columns; j++)
            dest->data[i][j] = strdup(src->data[i][j]);
        dest->data[i][src->nb_columns] = NULL;
    }
    dest->data[nb_rows] = NULL;
}

dataframe_t *df_head(dataframe_t *dataframe, int nb_rows)
{
    dataframe_t *df = malloc(sizeof(dataframe_t));
    int data_size = nb_rows > dataframe->nb_rows ?
    dataframe->nb_rows : nb_rows;

    if (!df)
        return NULL;
    copy_dataframe_metadata(df, dataframe, data_size);
    copy_dataframe_data(df, dataframe, data_size);
    return df;
}
