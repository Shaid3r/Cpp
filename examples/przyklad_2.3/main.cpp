#include <iostream>
#include <array>

template <typename First, typename... Rest>
void print_args(First first, Rest... rest)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

int main()
{
    std::array<double, 10> arr;

    print_args(1, 'a', 2.5, "templates are cool", arr);
    print_args<char>(1, 'a', 2.5, "templates are cool", arr);
    print_args<char, int, unsigned>(1, 'a', 2.5, "templates are cool", arr);
    //print_args<char, int, const double *>(1, 'a', 2.5, "templates are cool", arr);

    return 0;
}
