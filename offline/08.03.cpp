#include <iostream>
#include <string>

char* my_strconcat(const char* ptr1, const char* ptr2);

int main() {
    std::cout << "Bitte ersten Text eingeben (ggfs. mit Leerzeichen): ? ";
    std::string s1;
    std::getline(std::cin, s1);

    std::cout << "Bitte zweiten Text eingeben (ggfs. mit Leerzeichen): ? ";
    std::string s2;
    std::getline(std::cin, s2);

    std::cout << "Ergebnis my_strconcat(): " << my_strconcat(s1.data(), s2.data()) << std::endl;

    return 0;
}

std::size_t cstrlen(const char* str) {
    std::size_t s;
    for (s = 0; str[s] != 0; ++s)
        ;
    return s;
}

char* my_strconcat(const char* ptr1, const char* ptr2) {
    char*       res = new char[cstrlen(ptr1) + cstrlen(ptr2) + 1];
    std::size_t i;
    for (i = 0; ptr1[i] != 0; ++i) {
        res[i] = ptr1[i];
    }

    for (std::size_t k = 0; ptr2[k] != 0; ++k) {
        res[i + k] = ptr2[k];
    }

    res[cstrlen(ptr1) + cstrlen(ptr2)] = 0;
    return res;
}

