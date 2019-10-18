/*
Schreiben Sie ein C++ Programm, welches die Umrechnungen der vorigen
drei Aufgaben in einem einzigen Programm zusammenfasst. 
*/

#include <iostream>

int main()
{
    double input{ 0 };
    std::cout << "Ihre Eingabe: ? ";
    std::cin >> input;

    std::cout << "Ihre Auswahl der Umwandlung:" << std::endl <<
        "1 - Celsius in Fahrenheit" << std::endl <<
        "2 - Meter in Fuss" << std::endl <<
        "3 - Euro in US Dollar" << std::endl;

    int ch{ 0 };
    std::cin >> ch;

    double ergebnis = ((input * 1.8 + 32.) * ((ch - 2) * (ch - 3) / 2.)) + 
        ((input * 3.2808) * ((ch - 1) * (ch - 3) / -1.)) + 
        ((input * 1.2957) * ((ch - 1) * (ch - 2) / 2.));
    std::cout << "Das Ergebnis lautet: " << ergebnis << std::endl;
    return 0;
}
