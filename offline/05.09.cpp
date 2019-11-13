#include <iostream>
#include <string>

std::string trimme(std::string s)
{
    std::size_t begin = 0;
    while (s.at(begin) == '+' && begin < s.size())
        ++begin;

    std::size_t end = s.size() - 1;
    while (s.at(end) == '+' && end >= 0 && end < s.size())
        --end;

    std::string final;

    for (std::size_t i = begin; i <= end; ++i)
    {
        final += s.at(i);
    }

    return final;
}

int main()
{
    std::string s = "";
    std::cout << "Bitte geben Sie die Textzeile ein: ? ";
    getline(std::cin, s);
    std::cout << "Vorher: " << s << std::endl;
    std::cout << "Nachher: " << trimme(s) << std::endl;
    system("PAUSE");
    return 0;
}
