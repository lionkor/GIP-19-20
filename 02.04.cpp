/*
Schreiben Sie ein C++ Programm, welches eine Geldmenge als double
Fließkomma-Eingabewert einliest und diese Geldmenge dann von Euro in
US Dollar umrechnet. 
*/

#include <iostream>

int main()
{
    double euro{ 0 };
    std::cout << "Bitte geben Sie die Geldmenge in Euro ein: ? ";
    std::cin >> euro;
    double dollar = euro * 1.2957;
    std::cout << "Die Geldmenge in US Dollar lautet: " << dollar << std::endl;
    return 0;
}
