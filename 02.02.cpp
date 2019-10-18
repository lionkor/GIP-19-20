/*
Schreiben Sie ein C++ Programm, welches eine Temperatur als double
Fließkomma-Eingabewert einliest und diese Temperatur dann von Celsius
in Fahrenheit umrechnet. 
*/

#include <iostream>

int main()
{
    double celsius{ 0 };
    std::cout << "Bitte geben Sie die Temperatur in Grad Celsius ein: ? ";
    std::cin >> celsius;
    double fahrenheit = celsius * 1.8 + 32.;
    std::cout << "Die Temperatur in Fahrenheit lautet: " << fahrenheit << std::endl;
    return 0;
}
