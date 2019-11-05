#include <cctype>
#include <iostream>
#include <string>

int main()
{
    std::string text;
    std::size_t stride;

    std::cout << "Bitte geben Sie den zu verschluesselnden Text ein: ";
    std::getline(std::cin, text);

    std::cout << "Bitte geben Sie die Anzahl Verschiebepositionen ein (als positive "
                 "ganze Zahl): ";
    std::cin >> stride;

    for (std::size_t i = 0; i < text.size(); ++i)
    {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        {
            for (std::size_t step = 0; step < stride; ++step)
            {
                text[i]++;
                if (text[i] > 'Z' && text[i] < 'a')
                    text[i] = 'A';
                else if (text[i] > 'z')
                    text[i] = 'a';
            }
        }
    }

    std::cout << text << std::endl;
}
