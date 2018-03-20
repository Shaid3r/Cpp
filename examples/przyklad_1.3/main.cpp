#include <iostream>
#include "array.h"
#include "stack.h"

int main() {
    Array<Stack<int>, 3> intStackArray;
    int poped;

    intStackArray[0].push(1);
    intStackArray[0].push(2);
    intStackArray[0].push(3);
    intStackArray[1].push(10);
    intStackArray[1].push(20);
    intStackArray[1].push(30);
    intStackArray[2].push(100);
    intStackArray[2].push(200);
    intStackArray[2].push(300);



    for (int i = 0; i < 3; ++i) {
    	while(intStackArray[i].pop(poped))
    		std::cout << poped << " ";
    	std::cout << std::endl;
    }



    return 0;
}