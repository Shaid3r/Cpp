#include <iostream>

void process_all() { std::cout << "no more arguments to process\n"; }

template <typename T>
void process(T& t)
{
    static unsigned count = 0u;
    std::cout << "processing " << t << std::endl
              << "called " << ++count << " times\n\n";
}

template <typename First, typename... Rest>
void process_all(First first, Rest... rest)
{
    process(first);
    process_all(rest...);
}

int main()
{
    process_all(1, 2, "string", 3, 4 + 2.0, 'a', -1uLL);
    return 0;
}
