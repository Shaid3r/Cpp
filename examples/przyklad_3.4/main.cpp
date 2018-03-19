#include<iostream>

struct Test {
    typedef int foo;
};

template <typename T> 
void f(typename T::foo) {
    std::cout << "Definicja #1" << std::endl;
}

template <typename T> 
void f(T) {
    std::cout << "Definicja #2" << std::endl;
}

int main() {
    f<Test>(10); // Wywola #1.
    f<int>(10);  // Wywola #2.
}