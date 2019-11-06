#include <iostream>

int main()
{
    std::cout << "Bitte geben Sie das Zeichen ein: ? ";
    char c;
    std::cin >> c;

    switch (c)
    {
        case 'j':
        case 'J':
            std::cout << "Es handelt sich um eine Ja Eingabe." << std::endl;
            break;
        case 'n':
        case 'N':
            std::cout << "Es handelt sich um eine Nein Eingabe." << std::endl;
            break;
        default:
            std::cout << "Es handelt sich um eine sonstige Eingabe." << std::endl;
            break;
    }
}
