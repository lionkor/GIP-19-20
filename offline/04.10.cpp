#include <iostream>
#include <sstream>

int main()
{
	std::string input;
	std::cout << "Bitte Text eingeben (ggfs. mit Leerzeichen): ? ";
	std::getline(std::cin, input);

	std::stringstream output;

	for (auto& c : input)
	{
		if (isalpha(c))
		{
			if (islower(c))
				output << c << c;
			else if (isupper(c))
				output << c << c << c;
		}
		else if (isspace(c))
			output << '_';
		else if (c == '!' || c == '?')
			;
		else if (isdigit(c))
			output << '.';
		else
			output << c;
	}

	std::cout << "Der Text nach der Umwandlung: " << output.str() << std::endl;
}
