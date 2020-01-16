#include <iostream>
#include <string>
#include <vector>
#include <cstring>

struct T_Morse_Data {
    char        letter;
    std::string morse_code;
};
const std::vector<T_Morse_Data> morse_data = {
    { 'a', ".-" },
    { 'b', "-..." },
    { 'c', "-.-." },
    { 'd', "-.." },
    { 'e', "." },
    { 'f', "..-." },
    { 'g', "--." },
    { 'h', "...." },
    { 'i', ".." },
    { 'j', ".---" },
    { 'k', "-.-" },
    { 'l', ".-.." },
    { 'm', "--" },
    { 'n', "-." },
    { 'o', "---" },
    { 'p', ".--." },
    { 'q', "--.-" },
    { 'r', ".-." },
    { 's', "..." },
    { 't', "-" },
    { 'u', "..-" },
    { 'v', "...-" },
    { 'w', ".--" },
    { 'x', "-..-" },
    { 'y', "-.--" },
    { 'z', "--.." },
    { '0', "-----" },
    { '1', ".----" },
    { '2', "..---" },
    { '3', "...--" },
    { '4', "....-" },
    { '5', "....." },
    { '6', "-...." },
    { '7', "--..." },
    { '8', "---.." },
    { '9', "----." },
    { ' ', "///" },
    { '.', ".-.-.-" },
    { ',', "--..--" },
    { ':', "---..." },
    { '?', "..--.." },
    { '-', "-....-" },
    { '/', "-..-." },
    { '@', ".--.-." },
    { '=', "-...-" }
};


int main() {
    std::cout << "Bitte Text eingeben (ggfs. mit Leerzeichen): ? ";
    std::string input;
    std::getline(std::cin, input);

    for (const char& c : input) {
        for (const auto& morse_code : morse_data) {
            if (std::tolower(c) == morse_code.letter)
                std::cout << morse_code.morse_code << "#";
        }
    }
    std::cout << std::endl;
}

