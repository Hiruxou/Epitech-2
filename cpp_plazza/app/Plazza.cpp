//
// Plazza.cpp for  in /home/nicolaschr/rendu/cpp_plazza/app
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Apr 15 16:06:28 2015 Nicolas Charvoz
// Last update Sun Apr 26 22:35:43 2015 Nicolas Charvoz
//

#include "Plazza.hh"

Plazza::Plazza(int ac, char **av) : _ac(ac),
				    _timeMul(atof(av[1])),
				    _cooksPerKitchen(atoi(av[2])),
				    _timeReplace(atoi(av[3]))
{
}

int Plazza::run()
{
  Interface interface(_timeMul, _cooksPerKitchen, _timeReplace);

  return interface.showUI();
}
