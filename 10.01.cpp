#include <iostream>
#include "10/binaerer_suchbaum.h"

using namespace Suchbaum;

int main()
{
    int         input = 0;
    BaumKnoten* head  = nullptr;

    ausgeben(head);

    while (true)
    {
        std::cout << "Naechster Wert (99 beendet): ? ";
        std::cin >> input;
        if (input == 99)
            break;
        einfuegen(head, input);
    }

    ausgeben(head);
}
