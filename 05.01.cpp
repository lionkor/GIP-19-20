#include <iostream>

double sum(double* array, unsigned size)
{
    double total { 0.0 };
    for (unsigned i = 0; i < size; ++i)
        total += array[i];
    return total;
}

int main()
{
    double last_three[3] { 0.0 };
    unsigned index = 0;

    double total { 0.0 };
    double input;

    while (true)
    {
        do
        {
            std::cout << "Bitte geben Sie den neuen letzten Verbrauchswert ein: ? ";
            std::cin >> input;
        } while (input < 0.0 || input >= 100.0);

        if (input == 0.0)
            break;

        last_three[index] = input;

        index = index == 2 ? 0 : index + 1;

        std::cout << "Der bisherige Gesamtverbrauch betraegt " << (total += input)
                  << std::endl
                  << "Der Durchschnitt der letzten drei Verbrauchswerte betraegt "
                  << sum(last_three, 3) / 3.0 << std::endl;
    }
}
