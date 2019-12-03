#include <cctype>
#include <algorithm>
#include <iostream>

bool contains_non_alpha(std::string str)
{
	bool has_invalid = false;
	for (auto& c : str)
	{
		if (!isalpha(c))
		{
			has_invalid = true;
			break;
		}
	}
	return has_invalid;
}

int main()
{
	std::string input;
	do
	{
		std::cout << "Text: ? ";
		std::getline(std::cin, input);
	} while (contains_non_alpha(input));

	std::string reversed = input;
	std::reverse(reversed.begin(), reversed.end());

	if (input == reversed)
	{ std::cout << "Das eingegebene Wort ist ein Palindrom." << std::endl; }
	else
	{
		std::cout << "Das eingegebene Wort ist KEIN Palindrom." << std::endl;
	}
}
