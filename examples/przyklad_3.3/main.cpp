#include<type_traits>

template<typename T,
        typename= typename std::enable_if<std::is_enum<T>::value, void>::type>
void 
foo(T) {}

template<typename T>
typename std::enable_if<std::is_enum<T>::value, void>::type
bar(T) {}

template<typename T>
void 
func(T, typename std::enable_if<std::is_enum<T>::value, void**>::type= nullptr) {}

enum Enum1 {A, B};
enum class Enum2 { C, D};

int main() {
    foo(A);
    foo(Enum2::C);
    // foo(1); // błąd kompilacji - "no matching function for call to 'foo(int)'"

    bar<>(A); // <> kompilator sam wydedukuje co tutaj wpisac
    bar(Enum2::C);

    func(A);
    func(Enum2::C);
}