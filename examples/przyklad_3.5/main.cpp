#include <type_traits>

template<bool Condition, typename T = void>
struct enable_if {
    // Brak 'type', więc próba użycia spowoduje fail substitution
};

// częściowa specjalizacja, kiedy Condition == true
template<typename T>
struct enable_if<true, T> {
    using type = T;
};

template<typename T,
        typename= typename enable_if<std::is_enum<T>::value, void>::type>
void foo(T) {}

enum Enum1 {A, B};
enum class Enum2 { C, D};

int main() {
    foo<>(A);
    foo(Enum2::C);
    // foo(1); // błąd kompilacji
}