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

    df_write_csv(df, "test2.csv");
    dataframe_t *df2 = df_head(df, 2);
    df_write_csv(df2, "test3.csv");
    df_free(df);
    df_free(df2);
    return 0;
}
