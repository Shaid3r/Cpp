#include "part_one.h"
#include "part_two.h"
#include "part_three.h"
#include <iostream>
#include <string>

void part_one();
void part_two();
void part_three();

// Calego pliku nie wolno modyfikowac!
int main()
{
    part_one();
    part_two();
    part_three();
}

// Napisz prosta zmienna szablonowa
void part_one()
{
    std::cout << std::boolalpha << is_void_ptr<int *> << std::endl; // false
    std::cout << is_void_ptr<void *> << std::endl; // true
}

// Za pomoca szablonow oblicz w czasie kompilacji wartosc 10!
void part_two()
{
    constexpr std::size_t fact = factorial<10>;
    static_assert(fact == 3628800, "wrong factorial of 10");
    std::cout << fact << std::endl;
}

// Za pomoca szablonow ze zmienna liczba argumentow zaimplementuj prosta wersje funkcji
// safe_printf()
// Funkcja moze ale niekoniecznie musi sprawdzac przy wywolaniu czy podana liczba
// argumentow jest zgodna. Moze rownie dobrze zglosic blad dopiero podczas wypisywania
// wiadomosci
void part_three()
{
    safe_printf("Hello world!\n");
    // Hello world!

    safe_printf("Loading % output... 50%%\nLoading done.\n", std::string("next"));
    // Loading next output... 50%
    // Loading done.

    safe_printf("My name is %. I love %", "Kamil", "C++");
    safe_printf("%.\n", 14);
    // My name is Kamil. I love C++14.

    try
    {
        safe_printf("This is an example of too many arguments exception.\n"
                    "There should be % but we provided %.\n",
                    2, 3, "excessive_arg", 3.14);
    }
    catch (const std::string& e)
    {
        safe_printf("EXCEPTION MESSAGE: %\n", e);
    }

    try
    {
        safe_printf("This is an example of missing arguments exception.\n"
                    "There should be % but we provided %.\n",
                    2);
    }
    catch (const std::string& e)
    {
        safe_printf("EXCEPTION MESSAGE: %\n", e);
    }
}
