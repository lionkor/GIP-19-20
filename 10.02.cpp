#define CATCH_CONFIG_RUNNER
#include "10.02.dir/catch.h"
#include <iostream>

#include "10.02.dir/suchen.h"

int main()
{
    if (Catch::Session().run())
    {
        return 1;
    }

    std::cout << "Bitte geben Sie den Text ein: ";
    std::string input;
    std::getline(std::cin, input);
    std::string token;
    std::cout << "Bitte geben Sie die zu suchende Zeichenkette ein: ";
    std::getline(std::cin, token);

    int pos = zeichenkette_suchen(input.c_str(), token.c_str());

    if (pos == -1)
    {
        std::cout << "Die Zeichenkette '" << token << "'  ist NICHT in dem Text '"
                  << input << "' enthalten." << std::endl;
    }
    else
    {
        std::cout << "Die Zeichenkette '" << token << "' ist in dem Text '" << input
                  << "' enthalten." << std::endl
                  << "Sie started ab Zeichen " << pos << " (bei Zaehlung ab 0)."
                  << std::endl;
    }

    return 0;
}

