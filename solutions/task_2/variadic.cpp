#include "part_one.h"
#include "part_two.h"
#include "part_three.h"
#include <iostream>
#include <string>

void part_one();
void part_two();
void part_three();

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
    static_assert(fact == 3628800, "wrong factorial of 10 value");
    std::cout << fact << std::endl;
}

// Za pomoca szablonow ze zmianna liczba argumentow zaimplementuj prosta wersje funkcji
// safe_printf()
void part_three()
{
    safe_printf("Hello %! Today we have % of %.\n"
                "Those are my favourite numbers: %, %, %. %%Bye!%%\n",
                "world", 20, "March", 1, 2.5, 10u);
    // Hello world! Today we have 20 of March.
    // Those are my favourite numbers: 1, 2.5, 10. %Bye!%
}
