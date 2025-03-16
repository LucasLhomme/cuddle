/*
** EPITECH PROJECT, 2024
** c_proj_template
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "my_strings.h"

#include "dataframe.h"

static void df_fill(dataframe_t *df, char *line, int *is_header, char *sep)
{
    char **tokens = NULL;

    line[strcspn(line, "\n")] = 0;
    tokens = split_strtok(line, sep);
    if (*is_header) {
        df->nb_columns = my_strarray_len(tokens);
        df->column_names = tokens;
        df->column_types = malloc(sizeof(column_type_t) * df->nb_columns);
        for (int i = 0; i < df->nb_columns; i++)
            df->column_types[i] = STRING;
        *is_header = 0;
    } else {
        df->data = realloc(df->data, sizeof(void **) * (df->nb_rows + 1));
        df->data[df->nb_rows] = (void **)tokens;
        df->nb_rows++;
    }
}

dataframe_t *df_init(FILE *file, char *separator)
{
    dataframe_t *df = malloc(sizeof(dataframe_t));

    if (!df){
        if (file)
            fclose(file);
        return NULL;
    }
    df->nb_rows = 0;
    df->nb_columns = 0;
    df->column_names = NULL;
    df->column_types = NULL;
    df->data = NULL;
    df->sep = strdup(separator);
    return df;
}

dataframe_t *df_read_csv(char *filename, char *separator)
{
    FILE *file = NULL;
    dataframe_t *df = NULL;
    char *line = NULL;
    size_t len = 0;
    int is_header = 1;

    if (!separator)
        separator = ",";
    file = fopen(filename, "r");
    if (!file)
        return NULL;
    df = df_init(file, separator);
    if (!df)
        return NULL;
    while (getline(&line, &len, file) != -1)
        df_fill(df, line, &is_header, separator);
    free(line);
    fclose(file);
    return df;
}
