#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#include "../include/helper.h"

bool is_int(const char *s)
{
    size_t len = strlen(s);
    for (size_t i = 0; i < len; i++)
    {
        if (!isdigit(s[i]))
            return false;
    }

    return true;
}