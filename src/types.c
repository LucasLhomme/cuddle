/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** types
*/

#include "dataframe.h"

bool is_bool(const char *value)
{
    return strcasecmp(value, "true") == 0 || strcasecmp(value, "false") == 0;
}

bool is_uint(const char *value)
{
    return my_str_isnum(value);
}

bool is_int(const char *value)
{
    return value[0] == '-' && my_str_isnum(value + 1);
}
