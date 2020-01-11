#include <iostream>
#include <algorithm>
#include <string>

void q(std::string& output, std::string_view query) {
    std::cout << query;
    std::getline(std::cin, output);
}

std::string padded(const std::string& to_pad, std::size_t amount) {
    std::string str;
    for (std::size_t i = 0; i < amount; ++i)
        str += '#'; // padding char won't change
    return str + to_pad;
}

int main() {
    std::string strings[4];
    std::size_t max_len { 0 };
    for (int i = 0; i < 4; ++i) {
        q(strings[i], "Textzeile = ? ");
        if (strings[i].size() > max_len)
            max_len = strings[i].size();
    }
    for (int i = 0; i < 4; ++i) {
        std::cout << padded(strings[i], max_len - strings[i].size()) << std::endl;
    }
}

