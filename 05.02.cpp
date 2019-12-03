#include <iostream>

int main()
{
	int array[5] { 0 };
	for (unsigned i = 0; i < 5; ++i)
	{
		do
		{
			std::cout << "Bitte geben Sie die " << i + 1 << ". Zahl ein: ? ";
			std::cin >> array[i];
		} while (array[i] < 1 || array[i] > 9);
	}

	for (int row = 9; row > 0; --row)
	{
		std::cout << row;
		for (unsigned i = 0; i < 5; ++i)
		{
			if (array[i] == row)
				std::cout << '*';
			else if (array[i] > row)
				std::cout << '+';
			else
				std::cout << '.';
		}
		std::cout << std::endl;
	}
	std::cout << " 12345" << std::endl;
}
