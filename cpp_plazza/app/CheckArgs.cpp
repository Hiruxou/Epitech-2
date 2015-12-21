//
// CheckArgs.cpp for  in /home/nicolaschr/rendu/cpp_plazza/app
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Apr 17 19:49:44 2015 Nicolas Charvoz
// Last update Fri Apr 17 19:51:50 2015 Nicolas Charvoz
//

#include "CheckArgs.hh"

CheckArgs::CheckArgs(int ac, char **av) : _ac(ac), _av(av)
{
}

bool CheckArgs::checkParams() const
{
  if (_ac < 4)
    {
      std::cout << "Usage: " << _av[0]
                << " [TimeMultiplier] [CookNumber] [StockIngredientReplace]"
                << std::endl;
      return false;
    }
  else if (_ac > 4)
    std::cout << "Only the first 3 parameters will be used. " << std::endl;
  return true;
}
