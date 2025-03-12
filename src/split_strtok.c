/*
** EPITECH PROJECT, 2025
** test_minishell
** File description:
** split_strtok
*/

#include "my_strings.h"

#include <string.h>
#include <stdlib.h>

char **split_strtok(char *str, char *delim)
{
    int count = 0;
    int i = 0;
    char *temp = my_strdup(str);
    char **tab = NULL;
    char *token = strtok(temp, delim);

    for (; token; count++)
        token = strtok(NULL, delim);
    free(temp);
    tab = malloc(sizeof(char *) * (count + 1));
    if (!tab)
        return NULL;
    token = strtok(str, delim);
    for (; token; i++) {
        tab[i] = my_strdup(token);
        token = strtok(NULL, delim);
    }
    tab[i] = NULL;
    return tab;
}
