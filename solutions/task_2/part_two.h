#include <cstddef>

template <std::size_t N>
constexpr std::size_t factorial = N * factorial<N - 1>;

template <>
constexpr std::size_t factorial<1> = 1;

template <>
constexpr std::size_t factorial<0> = 1;
