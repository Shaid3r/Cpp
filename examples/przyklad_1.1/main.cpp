#include <iostream>
#include "stack.h"

int main() {
    Stack<std::string> stringsStack;
    std::string stringPoped;

    Stack<int> intStack;
    int intPoped;

    stringsStack.push("Coś");
    intStack.push(1);
    stringsStack.push("Inne");
    intStack.push(2);
    stringsStack.push("Kolejne");
    intStack.push(3);   
    stringsStack.push("Jeszcze inne");
    intStack.push(4);


    while (intStack.pop(intPoped)) {
    	std::cout << intPoped << std::endl;
    }

	std::cout << "------------------------------\n";

    while (stringsStack.pop(stringPoped)) { 
    	std::cout << stringPoped << std::endl;
    }

    return 0;
}