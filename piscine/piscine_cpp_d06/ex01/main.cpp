//
// main.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d06/ex01
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Mon Jan 12 10:27:14 2015 Nicolas Charvoz
// Last update Mon Jan 12 16:49:23 2015 Nicolas Charvoz
//

#include <cstdlib>
#include <iostream>

#define CELSIUS "Celsius"
#define FAR "Fahrenheit"

int		main(int ac, char **av)
{
  double temp;
  std::string param;
  (void)ac;
  (void)av;

  std::cin >> temp >> param;
  std::cout.precision(3);
  if (param == CELSIUS)
    {
      std::cout.width(16);
      std::cout << std::right << std::fixed << (temp * 9 / 5) + 32;
      std::cout.width(16);
      std::cout << std::right << std::fixed << FAR << std::endl;
    }
  else if (param == FAR)
    {
      std::cout.width(16);
      std::cout << std::right << std::fixed << 5.0 / 9.0 * (temp - 32);
      std::cout.width(16);
      std::cout << std::right << std::fixed << CELSIUS << std::endl;
    }
  return (0);
}
