/*
** EPITECH PROJECT, 2025
** G-AIA-200-LIL-2-1-cuddle-lucas.lhomme
** File description:
** shape_csv
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dataframe.h"

dataframe_shape_t df_shape(dataframe_t *dataframe)
{
    dataframe_shape_t df = {0};

    if (dataframe == NULL)
        return (dataframe_shape_t){0};
    df.nb_columns = dataframe->nb_columns;
    df.nb_rows = dataframe->nb_rows;
    return df;
}
