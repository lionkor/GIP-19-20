#include <iostream>

int main()
{
    int width, height;
    std::cout << "Bitte geben Sie die Breite des Parallelogramms ein: ? ";
    std::cin >> width;

    std::cout << "Bitte geben Sie die Hoehe des Parallelogramms ein: ? ";
    std::cin >> height;

    for (int y = 0; y < height; ++y)
    {
        for (int i = 0; i < y; ++i)
        {
            std::cout << '.';
        }
        for (int x = 0; x < width; ++x)
        {
            if (x == 0 || x == width - 1 || y == 0 || y == height - 1)
                std::cout << '*';
            else
                std::cout << '+';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
