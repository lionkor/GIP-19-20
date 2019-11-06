#include <iostream>

int main()
{
    double length;
    std::cout << "Bitte geben Sie die Seitenlaenge ein (in cm): ? ";
    std::cin >> length;
    
    std::cout << "Der Umfang des Quadrats betraegt (in cm): " << 4.0 * length << std::endl;
    std::cout << "Die Flaeche des Quadrats betraegt (in cm*cm): " << length * length << std::endl;
}
