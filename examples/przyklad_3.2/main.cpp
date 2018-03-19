#include <iostream>

template<typename T>
struct my_trait {
    static const bool isReference = false;
//    enum {isReference = false};
};

template<typename T>
struct my_trait<T &> {
    static const bool isReference = true;
//    enum {isReference = true};
};

int main() {
    std::cout << std::boolalpha;
    std::cout << my_trait<int &>::isReference << std::endl; // true
    std::cout << my_trait<int>::isReference << std::endl; // false
}
