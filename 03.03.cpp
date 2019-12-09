#include <iostream>

int main()
{
	char first_input_c;
	char second_input_c;

	std::cout << "Bitte geben Sie die erste Ziffer ein: ? ";
	std::cin >> first_input_c;
	std::cout << "Bitte geben Sie die zweite Ziffer ein: ? ";
	std::cin >> second_input_c;

	int first_input	 = first_input_c - '0';
	int second_input = second_input_c - '0';

	if (first_input < 0 || first_input > 9)
	{
		std::cout << "Das Programm wurde durch Eingabe von " << first_input_c
				  << " beendet." << std::endl;
		return 1;
	}
	else if (second_input < 0 || second_input > 9)
	{
		std::cout << "Das Programm wurde durch Eingabe von " << second_input_c
				  << " beendet." << std::endl;
		return 1;
	}

	std::cout << first_input << " + " << second_input << " = "
			  << first_input + second_input << std::endl;
	return 0;
}
