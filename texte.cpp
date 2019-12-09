#include "texte.h"

std::string trim(std::string s, char c)
{
	std::size_t start = 0;
	while (start < s.size() && s.at(start) == c)
		++start;

	std::size_t end = s.size();
	while (end > 0 && s.at(end - 1) == c)
		--end;

	std::string result { "" };

	for (std::size_t i = start; i < end; ++i)
	{
		result += s.at(i);
	}

	return result;
}


void split(std::string input, char c, std::string& left, std::string& right)
{
	left		  = "";
	std::size_t i = 0;
	for (; i < input.size(); ++i)
	{
		if (input.at(i) == c) break;
		left += input.at(i);
	}
	++i; // jump over c

	right = "";
	for (; i < input.size(); ++i)
	{
		right += input.at(i);
	}
}
