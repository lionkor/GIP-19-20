#include <iostream>

int main()
{
    int start_time_hours;
    int start_time_minutes;
    int step_minutes;

    do
    {
        std::cout << "Bitte geben Sie die Stunden der Startuhrzeit ein: ";
        std::cin >> start_time_hours;
    } while (start_time_hours < 0 || start_time_hours > 23);

    do
    {
    std::cout << "Bitte geben Sie die Minuten der Startuhrzeit ein: ";
    std::cin >> start_time_minutes;
    } while (start_time_minutes < 0 || start_time_minutes > 59);

    std::cout << "Der erste Bus fährt also um " << start_time_hours << ":"
              << start_time_minutes << "Uhr ." << std::endl;
    
    do
    {
    std::cout << "Bitte geben Sie die Taktzeit in Minuten ein: ";
    std::cin >> step_minutes;
    } while (step_minutes < 0 || step_minutes > 180);

    int hours = start_time_hours;
    int minutes = start_time_minutes;
    
    while (!(minutes + step_minutes > 60 && hours >= 23))
    {
        minutes += step_minutes;
        if (minutes >= 60)
        {
            hours++;
            minutes = minutes - 60;
            std::cout << std::endl;
        }
        std::cout << hours << ":" << minutes << " ";
    }
    
    std::cout << std::endl;
}
