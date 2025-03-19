/*
** EPITECH PROJECT, 2025
** bscuddle
** File description:
** cuddle
*/

#ifndef CUDDLE_H_
    #define CUDDLE_H_

    #include <stdio.h>
    #include <stdbool.h>

typedef enum {
    BOOL,
    INT,
    UINT,
    FLOAT,
    STRING,
    UNDEFINED
} column_type_t;

typedef struct {
    int nb_rows;
    int nb_columns;
    char **column_names;
    column_type_t *column_types;
    void ***data;
    char *sep;
} dataframe_t;

typedef bool (*type_check_t)(const char *value);

char **split_strtok(char *str, char *delim);

bool is_bool(const char *);
bool is_uint(const char *);
bool is_int(const char *);

void df_free(dataframe_t *df);
dataframe_t *df_init(FILE *file, char *separator);

dataframe_t *df_read_csv(char *filename, char *separator);
dataframe_t *df_head(dataframe_t *dataframe, int nb_rows);
int df_write_csv(dataframe_t *dataframe, const char *filename);

#endif /* !CUDDLE_H_ */
