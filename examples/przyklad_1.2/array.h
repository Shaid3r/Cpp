#pragma once

#include <iostream>
#include <cstdlib>

template <class T, int n>
class Array
{
    private:
        T ar[n];
    public:
        Array() {};
        Array(const T & v);
        virtual T & operator[](int i);
        virtual T operator[](int i) const;
};

template <class T, int n>
Array<T, n>::Array(const T & v)
{
    for (int i = 0; i < n; i++)
        ar[i] = v;
}

template <class T, int n>
T & Array<T, n>::operator[](int i)
{
    if (i < 0 || i >= n)
    {
        std::cerr << "Błąd zakresu tablicy: " << i
            << " jest poza zakresem\n";
        std::exit(EXIT_FAILURE);
    }
    return ar[i];
}

template <class T, int n>
T Array<T, n>::operator[](int i) const
{
    if (i < 0 || i >= n)
    {
        std::cerr << "Błąd zakresu tablicy: " << i
            << " jest poza zakresem\n";
        std::exit(EXIT_FAILURE);
    }
    return ar[i];
}
