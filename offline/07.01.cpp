#include <iostream>
#include <algorithm>
#include <string>

std::string padded(const std::string& to_pad, std::size_t amount) {
    std::string str;
    for (std::size_t i = 0; i < amount; ++i)
        str += '#'; // padding char won't change
    return str + to_pad;
}

int main() {
    std::vector<std::string> strings;
    std::size_t              max_len { 0 };
    for (int i = 0; i < 4; ++i) {
        std::string s;
        std::cout << "Textzeile = ? ";
        std::getline(std::cin, s);
        if (s.empty())
            break;
        if (s.size() > max_len)
            max_len = s.size();
        strings.push_back(s);
    }

    for (const std::string& s : strings)
        std::cout << padded(s, max_len - s.size()) << std::endl;
}

