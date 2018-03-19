// Zadanie polega na implementacji własnych klas type_traits
// is_pointer sprawdza czy przekazany typ jest wskaźnikiem
// rank zwraca głębokość tabeli
//
// Nie można używać <type_traits> ani modyfikować tego pliku!

#include <iostream>
#include "type_traits.h"

class A {};

int main() {
    std::cout << std::boolalpha; // Powoduje wyświetlanie booli jako true/false
    std::cout << is_pointer<A>::value << std::endl; // false
    std::cout << is_pointer<A *>::value << std::endl; // true
    std::cout << is_pointer<A &>::value << std::endl; // false
    std::cout << is_pointer<int>::value << std::endl; // false
    std::cout << is_pointer<int *>::value << std::endl; // true
    std::cout << is_pointer<int **>::value << std::endl; // true
    std::cout << is_pointer<int[10]>::value << std::endl; // false
    std::cout << is_pointer<std::nullptr_t>::value << std::endl; // false

    std::cout << "\nWymiar <int> wynosi: " << rank<int>::value << std::endl; // 0
    std::cout << "Wymiar <int[5]> wynosi: " << rank<int[5]>::value << std::endl; // 1
    std::cout << "Wymiar <int[5][5]> wynosi: " << rank<int[5][5]>::value << std::endl; // 2
}

/*
Wynik:
false
true
false
false
true
true
false
false

Wymiar <int> wynosi: 0
Wymiar <int[5]> wynosi: 1
Wymiar <int[5][5]> wynosi: 2
*/