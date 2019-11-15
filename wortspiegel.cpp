#include "wortspiegel.h"
#include <iostream>

bool is_alpha(/*const*/ char& c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int find_begin_of_word(std::string& text, int pos)
{
    if (!is_alpha(text.at(pos))) return pos + 0;
    int offset_from_pos = 0;
    std::cout << "pos            : " << pos << std::endl;
    while (pos + offset_from_pos - 1 >= 0
           && is_alpha(text.at(pos + offset_from_pos - 1)))
    {
        std::cout << "offset from pos: " << offset_from_pos
            << std::endl;
        --offset_from_pos;
    }
    return pos + offset_from_pos;
}

int find_end_of_word(std::string& text, int begin)
{
    if (!is_alpha(text.at(begin))) return begin + 0;
    int offset_from_begin = 0;
    std::cout << "begin            : " << begin << std::endl;
    while (begin + offset_from_begin < text.size() 
           && is_alpha(text.at(begin + offset_from_begin)))
    {
        std::cout << "offset from begin: " << offset_from_begin
            << std::endl;
        ++offset_from_begin;
    }
    return begin + offset_from_begin;
}

void swap(char& first, char& second)
{
    char tmp = first;
    first = second;
    second = tmp;
}

int abs(int x)
{
    return x < 0 ? -x : x;
}

void wortspiegel(std::string &text, int pos)
{
    int begin = find_begin_of_word(text, pos);
    int end = find_end_of_word(text, begin);

    std::cout << "begin: " << begin << "(" << text.at(begin) << ")" << std::endl;
    std::cout << "end  : " << end   << "(" << text.at(end - 1)   << ")" << std::endl;

    for (int i = 0; i < (end - begin) / 2; ++i)
    {
        std::cout << "i: " << i << std::endl;
        swap(text.at(begin + i), text.at(end - 1 - i));
    }
}