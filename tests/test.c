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
    dataframe_t *df3 = NULL;

    df_write_csv(df, "test_basic.csv");
    df_info(df, 3);
    df3 = df_head(df, 2);
    df_write_csv(df3, "test_head.csv");
    df_free(df);
    df_free(df3);
    return 0;
}
