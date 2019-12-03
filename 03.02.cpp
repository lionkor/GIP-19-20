#include <iostream>
// <climits> is probably not allowed
#include <climits>

int main()
{
	// if climits isn't allowed, replace INT_MIN and INT_MAX
	// with the values in the comments
	int largest { INT_MIN };  // -2147483646
	int smallest { INT_MAX }; //  2147483647
	int largest_position;
	int smallest_position;

	int current;

	for (int i = 1; i <= 5; ++i)
	{
		std::cout << "Bitte geben Sie die " << i << ". Zahl ein: ? ";
		std::cin >> current;

		if (current < smallest)
		{
			smallest		  = current;
			smallest_position = i;
		}
		if (current > largest)
		{
			largest			 = current;
			largest_position = i;
		}
	}

	std::cout << "Die " << smallest_position
			  << ". Zahl war die kleinste der eingegebenen Zahlen und "
			  << "lautet: " << smallest << std::endl;

	std::cout << "Die " << largest_position
			  << ". Zahl war die groesste der eingegebenen Zahlen und "
			  << "lautet: " << largest << std::endl;
}
