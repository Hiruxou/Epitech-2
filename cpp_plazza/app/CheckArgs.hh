//
// CheckArgs.hh for  in /home/nicolaschr/rendu/cpp_plazza/app
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Apr 17 19:48:39 2015 Nicolas Charvoz
// Last update Fri Apr 17 19:50:42 2015 Nicolas Charvoz
//

#ifndef CHECKARGS_HH_
# define CHECKARGS_HH_

#include "Plazza.hh"

class CheckArgs {

public:
  CheckArgs(int, char**);
  bool checkParams() const;

private:

  int _ac;
  char **_av;
};

#endif
