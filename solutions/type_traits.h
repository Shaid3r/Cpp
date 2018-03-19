#pragma once

template<typename T>
struct is_pointer{
    static const bool value = false;
};

template<typename T>
struct is_pointer<T*>{
    static const bool value = true;
};

template<typename T, std::size_t N = 0>
struct rank {
    enum {value = 0};
};

template<typename T, std::size_t N>
struct rank<T[N]> {
    enum {value = 1 + rank<T>::value };
};