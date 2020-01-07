#include "sort.h"

#include <iostream>
#define print(x) std::cout << #x << " = " << x << std::endl

void sortiere(int* a, unsigned N)
{
    for (unsigned i = 1; i <= N - 1; ++i)
    {
        int to_sort = a[i];
        int j       = i;
        while (j > 0 && a[j - 1] > to_sort)
        {
            a[j] = a[j - 1];
            j    = j - 1;
        }
        a[j] = to_sort;
    }
}
