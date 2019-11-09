#include <iostream>
#include <string>

bool is_digit(char c) { return (c >= '0' && c <= '9'); }
int as_digit(char c) { return c - '0'; }

int main()
{
    int sudoku[9][9] { 0 };
    std::string eingabe[11] { " " };

    std::cout << "Bitte geben Sie das Sudoku ein:" << std::endl;

    for (unsigned i = 0; i < 11; ++i)
        std::getline(std::cin, eingabe[i]);

    // for each string in eingabe
    for (unsigned i = 0, array_x = 0; i < 11 && array_x < 9; ++i)
    {
        // skip strings that start with '-'
        if (eingabe[i][0] == '-')
            continue;

        for (unsigned array_y = 0, string_i = 0; array_y < 9 && string_i < 22; ++array_y)
        {
            // skip forward to next digit
            while (string_i < 22 && !is_digit(eingabe[i][string_i]))
                ++string_i;

            // insert digit into sudoku
            sudoku[array_x][array_y] = as_digit(eingabe[i][string_i]);

            // move to the next character
            ++string_i;
        }

        ++array_x;
    }

    std::cout << std::endl << "Das Sudoku lautet:" << std::endl;

    // print loop
    for (unsigned y = 0; y < 9; ++y)
    {
        for (unsigned x = 0; x < 9; ++x)
        {
            std::cout << ';' << sudoku[y][x];

            // every third "column" that isn't the last one
            if (!((x + 1) % 3) && x + 1 < 9)
            {
                std::cout << ";//";
            }
        }
        std::cout << std::endl;
        if (!((y + 1) % 3) && y + 1 < 9)
            std::cout << "=======//=======//=======" << std::endl;
    }

    return 0;
}
