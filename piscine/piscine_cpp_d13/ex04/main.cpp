#include <iostream>
#include "Toy.h"
#include "Woody.h"
#include "Buzz.h"

int main()
{
  Toy a(Toy::BASIC_TOY, "REX", "rex.txt");
  std::cout << a;
  a << "\\o/";
  std::cout << a;
}
