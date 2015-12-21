//
// main.cpp for  in /home/nicolaschr/rendu/cpp_plazza
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Apr 15 14:53:11 2015 Nicolas Charvoz
// Last update Fri Apr 17 19:56:51 2015 Nicolas Charvoz
//

#include "Plazza.hh"
#include "CheckArgs.hh"

int		main(int ac, char **av)
{
  Plazza	*plazza;
  CheckArgs checkArgs(ac, av);

  if (!(checkArgs.checkParams()))
    return (0);
  plazza = new Plazza(ac, av);
  plazza->run();
  return (0);
}
