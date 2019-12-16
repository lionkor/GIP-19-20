#include "suchen.h"
#include <iostream>

typedef unsigned long size_t;

size_t string_size(const char* str)
{
    size_t count = 0;
    while (*str != 0)
    {
        ++str;
        ++count;
    }
    return count;
}

bool matches(const char* begin, const char* token)
{
    for (size_t i = 0; token[i] != 0; ++i)
    {
        if (begin[i] != token[i])
            return false;
    }
    return true;
}

int zeichenkette_suchen(const char* text, const char* token)
{
    for (size_t i = 0; i < string_size(text); ++i)
    {
        if (matches(&text[i], token))
            return i;
    }
    return -1;
}
