/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** test
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dataframe.h"

int main(void)
{
    dataframe_t *df = df_read_csv("test.csv", ";");
    dataframe_t *df2 = NULL;
    dataframe_t *df3 = NULL;

    df_write_csv(df, "test_basic.csv");
    df2 = df_tail(df, 2);
    df_write_csv(df2, "test_tail.csv");
    df3 = df_head(df, 2);
    df_write_csv(df3, "test_head.csv");
    df_free(df);
    df_free(df2);
    return 0;
}
