/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** types
*/

#include <ctype.h>
#include <string.h>
#include <strings.h>
#include "my_strings.h"

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

bool is_float(const char *value)
{
    const char *dot = strchr(value, '.');

    if (value[0] == '-')
        value++;
    if (!dot || dot != strrchr(value, '.'))
        return false;
    for (int i = 0; value[i]; i++) {
        if (value[i] == '.')
            continue;
        if (!isdigit(value[i]))
            return false;
    }
    return true;
}
