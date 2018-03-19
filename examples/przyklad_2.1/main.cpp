#include <iostream>
#include <string>

template <std::string * temp>
void f()
{
    std::cout << *temp << std::endl;
}

template <std::string & temp>
void g()
{
    std::cout << temp << std::endl;
    temp += " oraz poprzez referencje";
}

std::string str; // obiekt musi byc globalny i miec lacznosc zewnetrzna

int main()
{
    str = "mozna modyfikowac wartosc lokalnie";

    f<&str>();
    g<str>();

    std::cout << str << std::endl;

    return 0;
}
