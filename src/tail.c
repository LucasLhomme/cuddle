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

dataframe_t *df_tail(dataframe_t *dataframe, int nb_rows)
{
    dataframe_t *df = malloc(sizeof(dataframe_t));
    int data_size = nb_rows > dataframe->nb_rows ?
    dataframe->nb_rows : nb_rows;

    if (!df)
        return NULL;
    df->nb_rows = data_size;
    copy_dataframe_metadata(df, dataframe, data_size);
    copy_dataframe_data(df, dataframe, data_size);
    return df;
}
