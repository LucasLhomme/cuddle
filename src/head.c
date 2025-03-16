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

dataframe_t *df_head(dataframe_t *dataframe, int nb_rows)
{
    dataframe_t *df = malloc(sizeof(dataframe_t));
    int data_size = nb_rows > dataframe->nb_rows ? 
        dataframe->nb_rows : nb_rows;

    if (!df)
        return NULL;
    df->nb_rows = data_size;
    df->nb_columns = dataframe->nb_columns;
    df->sep = strdup(dataframe->sep);
    df->column_names = malloc(sizeof(char *) * dataframe->nb_columns);
    for (int i = 0; i < dataframe->nb_columns; i++)
        df->column_names[i] = strdup(dataframe->column_names[i]);
    df->column_types = malloc(sizeof(int) * dataframe->nb_columns);
    memcpy(df->column_types, dataframe->column_types,
        sizeof(int) * dataframe->nb_columns);
    df->data = malloc(sizeof(void **) * data_size);
    for (int i = 0; i < nb_rows; i++) {
        df->data[i] = malloc(sizeof(void *) * dataframe->nb_columns);
        for (int j = 0; j < dataframe->nb_columns; j++)
            df->data[i][j] = dataframe->data[i][j];
    }
    return df;
}
