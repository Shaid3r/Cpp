#include <iostream>
#include <vector>
#include <array>

template<typename Container>
typename Container::value_type sum(Container s) {
    typedef typename Container::value_type elements_type;
    elements_type total = elements_type();

    for (unsigned int i = 0; i < s.size(); ++i)
        total += s[i];

    return total;
}

int main() {
    std::vector<int> vec{1, 2, 3};
    std::cout << "Suma vectora: " << sum(vec) << std::endl;

    std::array<double, 4> arr{1.5, 2.2, 3., 4.1};
    std::cout << "Suma array'a: " << sum(arr) << std::endl;
}
