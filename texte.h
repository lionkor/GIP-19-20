#ifndef TEXTE_H
#define TEXTE_H

#include <string>

std::string trim(std::string s, char c = ' ');
void		split(std::string input, char c, std::string& left, std::string& right);

#endif // TEXTE_H
