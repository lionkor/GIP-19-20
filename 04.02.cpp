#include <iostream>
#include <string>

int main()
{
    std::string text;
    int stride;

    std::cout << "Bitte geben Sie den zu verschluesselnden Text ein: ";
    std::getline(std::cin, text);

    std::cout << "Bitte geben Sie die Anzahl Verschiebepositionen ein (als positive "
                 "ganze Zahl): ";
    std::cin >> stride;

    for (std::size_t i = 0; i < text.size(); ++i)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            if (text[i] + stride > 'Z')
                text[i] = char('A' - 1 + (text[i] + stride - 'Z')); // -1, because 'Z' + 1 = 'A'
            else
                text[i] += stride;
        }
        else if (text[i] >= 'a' && text[i] <= 'z')
        {
            if (text[i] + stride > 'z')
                text[i] = char('a' - 1 + (text[i] + stride - 'z'));
            else
                text[i] += stride;
        }
    }

    std::cout << text << std::endl;
    system("pause");
}
