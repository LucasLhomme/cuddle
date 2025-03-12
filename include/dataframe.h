/*
** EPITECH PROJECT, 2025
** bscuddle
** File description:
** cuddle
*/

#ifndef CUDDLE_H_
    #define CUDDLE_H_

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
} dataframe_t;

char **split_strtok(char *str, char *delim);

void df_free(dataframe_t *df);
dataframe_t *df_read_csv(char *filename, char *separator);

#endif /* !CUDDLE_H_ */
