/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** test
*/

#include <stdio.h>
#include <stdlib.h>

#include "dataframe.h"

int main(void)
{
    dataframe_t *df = df_read_csv("test.csv", ",");
    dataframe_shape_t shape = df_shape(df);
    dataframe_t *df2 = df_tail(df, 3);
    dataframe_t *df3 = df_head(df, 3);
    void *value = df_get_value(df, 0, "City");
    void **values = df_get_values(df, "City");
    void **unique_values = df_get_unique_values(df, "City");

    df_info(df);
    printf ("Shape: %d rows, %d columns\n", shape.nb_rows, shape.nb_columns) ;
    df_write_csv(df, "test_basic.csv");
    df_write_csv(df2, "test_tail.csv");
    df_write_csv(df3, "test_head.csv");
    printf("Value: %s\n", (char *)value);
    for (int i = 0; values[i]; i++)
        printf("Value %d: %s\n", i, (char *)values[i]);
    for (int i = 0; unique_values[i]; i++)
        printf("Unique value %d: %s\n", i, (char *)unique_values[i]);
    df_free(df);
    df_free(df2);
    df_free(df3);
    free(value);
    for (int i = 0; values[i]; i++)
        free(values[i]);
    free(values);
    for (int i = 0; unique_values[i]; i++)
        free(unique_values[i]);
    free(unique_values);
    return 0;
}
