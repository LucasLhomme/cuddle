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

typedef struct dataframe_shape_s {
    int nb_rows;
    int nb_columns;
} dataframe_shape_t;

typedef struct {
    int nb_rows;
    int nb_columns;
    char **column_names;
    column_type_t *column_types;
    void ***data;
    char *sep;
} dataframe_t;

typedef bool (*type_check_t)(const char *value);

char **split_strtok(char *, char *);

bool is_bool(const char *);
bool is_uint(const char *);
bool is_int(const char *);
bool is_float(const char *);

void df_free(dataframe_t *);
dataframe_t *df_init(FILE *, char *);

void *df_get_value(dataframe_t *, int, const char *);
void **df_get_values(dataframe_t *, const char *);
void **df_get_unique_values(dataframe_t *, const char *);

dataframe_t *df_read_csv(char *, char *);
dataframe_t *df_head(dataframe_t *, int);
int df_write_csv(dataframe_t *, const char *);
dataframe_t *df_tail(dataframe_t *, int);
void copy_dataframe_data(dataframe_t *, dataframe_t *, int);
void copy_dataframe_metadata(dataframe_t *, dataframe_t *, int);
void df_info(dataframe_t *);
dataframe_shape_t df_shape(dataframe_t *);

#endif /* !CUDDLE_H_ */
