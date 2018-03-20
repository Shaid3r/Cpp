#include <iostream>
#include "array.h"
#include <vector>

int main() {
    Array<std::string, 3> stringArray;
	Array<int, 2> intArray;

	stringArray[0] = "Coś";
	intArray[0] = 1;
	stringArray[1] = "Inne";
	intArray[1] = 2;
	stringArray[2] = "Następne";



	for (int i = 0; i < 3; ++i)
		std::cout << stringArray[i] << std::endl;

	std::cout << "------------------------------\n";


	for (int i = 0; i < 2; ++i)
		std::cout << intArray[i] << std::endl;

    return 0;
}