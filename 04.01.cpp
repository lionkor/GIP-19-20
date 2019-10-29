#include <iostream>

int main()
{
    bool guessed { false };
    int range_top { 100 };
    int range_bottom { 1 };

    std::cout << "Merken Sie sich eine Zahl zwischen 1 (inklusive) und 100 (exklusive)"
              << "\n\n";

    while (!guessed)
    {
        int guess = int(double(range_top) / 2.0 + double(range_bottom) / 2.0);
        char answer;
        std::cout << "Aktueller Ratebereich: " << range_bottom << " bis " << range_top
                  << std::endl;
        std::cout << "Ist " << guess << " ihre Zahl?" << std::endl
                  << "(j) ja: gleich," << std::endl
                  << "(k) nein: meine Zahl ist kleiner," << std::endl
                  << "(g) nein: meine Zahl ist groesser." << std::endl
                  << "? ";
        std::cin >> answer;

        if (answer == 'j')
            guessed = true; // Alternatively: break;
        else if (answer == 'k')
            range_top = guess;
        else if (answer == 'g')
            range_bottom = guess + 1;
    }
}
