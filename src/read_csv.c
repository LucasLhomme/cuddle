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

static column_type_t determine_type(column_type_t current_type,
    column_type_t new_type)
{
    if (current_type == UNDEFINED || current_type == new_type)
        return new_type;
    return STRING;
}

static column_type_t check_value_type(char *value,
    type_check_t *type_checks, column_type_t *types, size_t type_count)
{
    for (size_t j = 0; j < type_count; j++) {
        if (type_checks[j](value))
            return types[j];
    }
    return UNDEFINED;
}

static column_type_t find_column_type(dataframe_t *df, int column)
{
    column_type_t type = UNDEFINED;
    char *value = NULL;
    type_check_t type_checks[] = {is_bool, is_uint, is_int, is_float};
    column_type_t types[] = {BOOL, UINT, INT, FLOAT};
    size_t type_count = sizeof(type_checks) / sizeof(type_check_t);
    column_type_t detected = UNDEFINED;

    for (int i = 0; i < df->nb_rows; i++) {
        value = (char *)df->data[i][column];
        if (value == NULL)
            continue;
        detected = check_value_type(value, type_checks, types, type_count);
        if (detected == UNDEFINED)
            return STRING;
        type = determine_type(type, detected);
        if (type == STRING)
            return STRING;
    }
    return type;
}

static void get_types(dataframe_t *df)
{
    for (int i = 0; i < df->nb_columns; i++)
        if (df->column_types[i] == UNDEFINED)
            df->column_types[i] = find_column_type(df, i);
}

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
            df->column_types[i] = UNDEFINED;
        *is_header = 0;
    } else {
        df->data = realloc(df->data, sizeof(void **) * (df->nb_rows + 2));
        if (!df->data)
            return;
        df->data[df->nb_rows] = (void **)tokens;
        df->nb_rows++;
        df->data[df->nb_rows] = NULL;
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
    get_types(df);
    free(line);
    fclose(file);
    return df;
}
