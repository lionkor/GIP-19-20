#include <iostream>
#include <string>

bool is_digit(char c) { return (c >= '0' && c <= '9'); }
int as_digit(char c) { return c - '0'; }

void print_invalid(std::string what, unsigned where, unsigned numbers[8], bool& is_valid)
{
    for (unsigned i = 0; i < 8; ++i)
    {
        if (!numbers[i])
        {
            std::cout << what << " " << where << ": Zahl " << i+1 
                << " kommt nicht vor." << std::endl;
            is_valid = false;
        }
        else if (numbers[i] > 1)
        {
            std::cout << what << " " << where << ": Zahl " << i+1
                << " kommt mehrfach vor." << std::endl;
            is_valid = false;
        }
    }
}

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

    // In the following loops the arrays work like this:
    //  The array is of size 9.
    //  Each index 'i' holds the amount of times the number i+1 was seen in the sudoku. 
    //  Therefore, to increment the counter of a single number, the 'i-1'-th index is 
    //  incremented. 
    //
    // Example: We have an array that holds occurances of a number in a column:
    //    unsigned column[8] {0};
    //   Now we see a '5' in the sudoku, so we want to increase that counter:
    //    ++column[5 - 1];
    //   We increased the 5th index, 4, by 1. Now the array looks like this:
    //  
    //    i    : 0 1 2 3 4 5 6 7 8
    //    value: 0 0 0 0 1 0 0 0 0
    //
    //   number: 1 2 3 4 5 6 7 8 9  (i + 1)

    bool is_valid { true };

    // columns
    for (unsigned y = 0; y < 9; ++y)
    {
        unsigned column[8] { 0 };
        for (unsigned x = 0; x < 9; ++x)
        {
            ++column[sudoku[x][y] - 1];
        }
        print_invalid("Spalte", y, column, is_valid);
    }

    // rows
    for (unsigned y = 0; y < 9; ++y)
    {
        unsigned row[8] { 0 };
        for (unsigned x = 0; x < 9; ++x)
        {
            ++row[sudoku[y][x] - 1];
        }
        print_invalid("Zeile", y, row, is_valid);
    }

    // blocks
    for (unsigned block_n = 0; block_n < 9; ++block_n)
    {
        unsigned block[8] { 0 };
        for (int x = block_n/3*3; x < block_n/3*3+3; ++x)
        {
            for (int y = block_n%3*3; y < block_n%3*3+3; ++y)
            {
                ++block[sudoku[x][y] - 1];
            }
        }
        print_invalid("Block", block_n, block, is_valid);
    }

    if (is_valid)
        std::cout << "Das Sudoku ist gueltig." << std::endl;

    return 0;
}
