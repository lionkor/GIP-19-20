// Datei: main.cpp

#include <iostream>

#define CATCH_CONFIG_RUNNER
#include "catch.h"

int main()
{
	int result = Catch::Session().run();

	std::cout << "Resultatwert: " << result << std::endl;

	system("PAUSE");
	return 0;
}
