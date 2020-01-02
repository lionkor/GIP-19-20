#include <iostream>

#include "sort.h"

void print_array(const int* a, const unsigned size)
{
    for (unsigned k = 0; k < size; k++)
    {
        std::cout << a[k] << (k < size - 1 ? ", " : "\n");
    }
}

int main()
{
    const int N   = 10;
    int       a[] = { 9, 3, 5, 2, 8, 6, 4, 3, 7, 8 };

    std::cout << "Vorher: ";
    print_array(a, N);

    sortiere(a, N);

    std::cout << "Nachher: ";
    print_array(a, N);

    return 0;
}
