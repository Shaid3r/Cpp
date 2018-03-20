// W tym zadaniu należy zmodyfikować plik tak, aby program się wykonywał.
// 
// Wskazówka:
// Będzie tutaj przydatny std::iterator_traits z biblioteki standardowej.
// Ma on zdefiniowane następujące typy:
    // difference_type	Iterator::difference_type
    // value_type	Iterator::value_type
    // pointer	Iterator::pointer
    // reference	Iterator::reference
    // iterator_category	Iterator::iterator_category
//
// Można modyfikować ten plik, ale nie można zmieniać funkcji main()

#include <iostream>
#include <vector>
#include <array>
#include <type_traits>

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
    std::cout << "Suma vec: " << sum(vec) << std::endl;
    
    std::vector<int>::iterator it = vec.begin();
    std::vector<int>::iterator it_end = vec.end();

    std::cout << "Suma vec(iter): " << sum(it, it_end) << std::endl;

    std::array<double, 4> arr{1.5, 2.2, 3., 4.1};
    std::cout << "Suma arr: " << sum(arr) << std::endl;

    std::array<double, 4>::iterator itd = arr.begin();
    std::array<double, 4>::iterator itd_end = arr.end();
    
    std::cout << "Suma arr(iter): " << sum(itd, itd_end) << std::endl;
}
