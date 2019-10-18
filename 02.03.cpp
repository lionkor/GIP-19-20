/*
Schreiben Sie ein C++ Programm, welches eine Länge als double
Fließkomma-Eingabewert einliest und diese Länge dann von Metern in Fuß
umrechnet. 
*/

#include <iostream>

int main()
{
    double meter{ 0 };
    std::cout << "Bitte geben Sie die Laenge in Metern ein: ? ";
    std::cin >> meter;
    double fuss = meter * 3.2808;
    std::cout << "Die Laenge in Fuss lautet: " << fuss << std::endl;
    return 0;
}
