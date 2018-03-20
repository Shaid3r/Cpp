#include <iostream>

struct Base
{
  int algorithm(int x)
  {
    prologue();
    if (x > 42)
      x = downsize(x);
    x = crunch(x);
    epilogue();
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

struct Derived : Base
{
  int downsize(int x)
  {
    while (x > 42) x /= 2;
    return x;
  }

  void epilogue()
  {
  	std::cout << "We're done!\n";  // <- TO SIE NIE WYKONA NAWET JAK JESE NADPISANA FUNKCJA
  }	
};

int main()
{
  Derived d;
  std::cout << d.algorithm(420);
}