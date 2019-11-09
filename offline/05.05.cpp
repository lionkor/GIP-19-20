#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> input(9);
    for (std::size_t i = 0; i < 9; ++i)
    {
        do
        {
            std::cout << "Bitte geben Sie die " << i + 1 << ". Zahl ein: ? ";
            std::cin >> input[i];
        } while(input[i] < 1 || input[i] > 6);
    }

    std::size_t uniques = 0;
    for (std::size_t i = 0; i < 9; ++i)
    {
        if (std::find(input.begin(), input.end(), i) != input.end())
            ++uniques;
    }
    std::cout << "In der Eingabe kamen " << uniques << " unterschiedliche Zahlen vor."
              << std::endl;
}
