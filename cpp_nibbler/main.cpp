//
// main.cpp for main in /home/garcia_t/rendu/cpp_nibbler
//
// Made by antoine garcia
// Login   <garcia_t@epitech.net>
//
// Started on  Wed Mar 11 14:29:05 2015 antoine garcia
// Last update Sat Apr  4 12:43:07 2015 Antoine Garcia
//

#include "IDisplayModule.hh"
#include <iostream>
#include <sstream>
#include <string>
#include "define.h"
#include "DLLoader.hpp"
#include "Game.hh"

int	main(int ac, char **av)
{
  int	width;
  int	height;

  if (ac != 4)
    {
      std::cerr << "[Usage] : ./nibbler width height library" << std::endl;
      return (-1);
    }
  std::istringstream str1(av[1]);
  str1 >> width;
  std::istringstream str2(av[2]);
  str2 >> height;
  if (width < MIN_W || height < MIN_H || width > 60 || height > 60)
    {
      std::cerr << "Height and width must be > 10 and < 60" << std::endl;
      return (-1);
    }
  try
    {
      DLLoader<IDisplayModule*> loader(av[3]);
      Game game(width, height, loader.getInstance());
      game.run();
    }catch(std::exception &e)
    {
      std::cout << e.what() << std::endl;
    }
  return (0);
}
