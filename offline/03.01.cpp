#include <iostream>
#include <cctype>

int main()
{
	std::cout << "Bitte geben Sie das Zeichen ein: ? ";
	char c;
	std::cin >> c;

	if (isalpha(c) && islower(c))
	{ std::cout << "Es wurde ein Kleinbuchstabe (a-z) eingegeben." << std::endl; }
	else
	{
		std::cout << "KEIN Kleinbuchstabe (a-z)." << std::endl;
	}
}
