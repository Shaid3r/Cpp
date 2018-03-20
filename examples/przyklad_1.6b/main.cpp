#include <iostream>

template <class Self>
struct Base
{
  Self& self() {
     return static_cast<Self&>(*this);
  }

  int algorithm(int x)
  {
    self().prologue();
    if (x > 42)
      x = self().downsize(x);
    x = self().crunch(x);
    self().epilogue();
    return x;
  }

  void prologue()
  {}

  int downsize(int x)
  { return x % 42; }

  int crunch(int x)
  { return -x; }

  void epilogue()
  {}
};

struct Derived : Base<Derived>
{
  int downsize(int x)
  {
    while (x > 42) x /= 2;
    return x;
  }

  void epilogue()
  { std::cout << "We're done!\n"; }
};

int main()
{
  Derived d;
  std::cout << d.algorithm(420);
}
