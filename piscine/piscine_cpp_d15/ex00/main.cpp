//
// main.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d15/ex00
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Jan 20 19:42:51 2015 Nicolas Charvoz
// Last update Tue Jan 20 19:44:05 2015 Nicolas Charvoz
//

#include <iostream>
#include <string>
#include "ex00.hpp"

int main()
{
  int a = 2;
  int b = 3;

  ::swap(a, b);

  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
  std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
  std::cout << "add(a, b) = " << ::add(a, b) << std::endl;
  std::string c = "chaine1";
  std::string d = "chaine2";

  ::swap(c, d);

  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
  std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
  std::cout << "add(c, d) = " << ::add(c, d) << std::endl;
}
