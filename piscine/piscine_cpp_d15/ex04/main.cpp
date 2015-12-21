//
// main.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d15/ex04
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Jan 20 20:30:38 2015 Nicolas Charvoz
// Last update Tue Jan 20 20:30:39 2015 Nicolas Charvoz
//

#include <iostream>
#include "ex04.hpp"

int main()
{
  std::cout << "1 == 0 ? " << equal(1, 0) << std::endl;
  std::cout << "1 == 1 ? " << equal(1, 1) << std::endl;

  Tester<int> iT;
  std::cout << "41 == 42 ? " << iT.equal(41, 42) << std::endl;
  std::cout << "42 == 42 ? " << iT.equal(42, 42) << std::endl;
  return 0;
}
