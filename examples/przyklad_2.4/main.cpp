#include <iostream>
#include <vector>

template <typename... Args>
void print_all(Args&&... args)
{
    (std::cout << ... << args) << std::endl;
}

template <typename... Args>
bool all(Args&&... args)
{
    return (... && args);
}

template <typename... Args>
auto sum_double(Args&&... args)
{
    return ((args * 2) + ...);
}

template<typename T, typename... Args>
void push_back_vec(std::vector<T>& v, Args&&... args)
{
    (v.push_back(args), ...);
}

int main()
{
    print_all(1, 3, 5, "str");        // 135str

    if (all(10, 5, true, false))
        std::cout << "All true" << std::endl;
    else
        std::cout << "Some false" << std::endl;

    auto sum = sum_double(1, 2, 3.0); // sum = 12.0

    std::vector<int> v;
    push_back_vec(v, 2, 4, 6, 8, 10);
    for (const auto& val : v)
        std::cout << val << " ";
    std::cout << std::endl;

    return 0;
}
