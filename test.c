/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** test
*/

#include "dataframe.h"

int main(void)
{
    dataframe_t *df = df_read_csv("test.csv", ",");

    df_write_csv(df, "test2.csv");
    df_free(df);
    return 0;
}
