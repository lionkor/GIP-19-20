#include <iostream>
#include <string>

std::string trimme(std::string s)
{
    std::size_t begin = 0;
    for (; begin < s.size() && s.at(begin) == '+'; ++begin)
        ;

    std::size_t end = s.size() - 1;
    for (; end >= begin && s.at(end) == '+'; --end)
        ;

    if (begin > end)
        return "";

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
