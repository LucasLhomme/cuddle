/*
** EPITECH PROJECT, 2025
** G-AIA-200-LIL-2-1-cuddle-lucas.lhomme
** File description:
** tail
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dataframe.h"

static void copy_dataframe_tail_data(dataframe_t *dest, dataframe_t *src,
    int start_index, int data_size)
{
    dest->data = malloc(sizeof(void **) * data_size);
    for (int i = 0; i < data_size; i++) {
        dest->data[i] = malloc(sizeof(void *) * src->nb_columns);
        for (int j = 0; j < src->nb_columns; j++)
            dest->data[i][j] = src->data[start_index + i][j];
    }
}

dataframe_t *df_tail(dataframe_t *dataframe, int nb_rows)
{
    dataframe_t *df = malloc(sizeof(dataframe_t));
    int data_size = nb_rows > dataframe->nb_rows ?
    dataframe->nb_rows : nb_rows;
    unsigned int start_index = dataframe->nb_rows - data_size;

    if (!df)
        return NULL;
    df->nb_rows = data_size;
    copy_dataframe_metadata(df, dataframe, data_size);
    copy_dataframe_tail_data(df, dataframe, start_index, data_size);
    return df;
}
