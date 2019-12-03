/*
Schreiben Sie ein C++ Programm, welches einen Kleinbuchstaben über
die Tastatur einliest und die Position des Buchstabens im Alphabet
berechnet und ausgibt. Die Positionszählung beginne bei 1 für das a.
*/

#include <iostream>

int main()
{
	char a_start = 'a';
	char input	 = '\0';

	std::cout << "Bitte geben Sie den Buchstaben ein: ? ";
	std::cin >> input;
	std::cout << "Der Buchstabe " << input << " hat die Position "
			  << int(input - a_start + 1) << " im Alphabet." << std::endl;
	return 0;
}
