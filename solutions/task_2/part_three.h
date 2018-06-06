#include <iostream>
#include <string>

void safe_printf(const char *s)
{
    while (*s)
    {
        if (*s == '%')
        {
            if (*(s + 1) == '%')
                ++s;
            else
                throw std::string("invalid format string: missing arguments");
        }
        std::cout << *s++;
    }
}

template <typename T, typename... Args>
void safe_printf(const char *s, const T& value, Args... args)
{
    while (*s)
    {
        if (*s == '%')
        {
            if (*(s + 1) == '%')
            {
                ++s;
            }
            else
            {
                std::cout << value;
                safe_printf(s + 1, args...);
                return;
            }
        }
        std::cout << *s++;
    }
    throw std::string("invalid format string: too many arguments provided");
}
