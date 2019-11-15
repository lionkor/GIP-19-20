#include <iostream>
#include "wortspiegel.h"

std::string left_padded(std::string str, int amount)
{
    std::string padding;
    for (int i = 0; i < amount; ++i)
        padding += ' ';
    return padding + str;
}

int main()
{
    std::cout << "Bitte geben Sie den Text ein: ? ";
    
    std::string text;
    std::getline(std::cin, text);
    
    unsigned pos = 0;
    
    do
    {
        std::cout << std::endl
                  << text
                  << std::endl
                  << left_padded("*", pos)
                  << std::endl
                  << "Befehl (l: links, r: rechts, s: spiegeln, q: Ende) ?-";
        char option;
        std::cin >> option;
        
        switch (option)
        {
        case 'l': 
            pos = int(pos) - 1 < 0 ? 0 
                                   : pos - 1;
            break;
        case 'r':
            ++pos;
            break;
        case 's':
            wortspiegel(text, pos);
            break;
        case 'q':
            return 0;
        }
    } while (pos != text.size());
}
