//
// Reception.cpp for  in /home/nicolaschr/rendu/cpp_plazza/app
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Apr 15 16:03:47 2015 Nicolas Charvoz
// Last update Fri Apr 24 12:16:30 2015 Nicolas Charvoz
//

#include "Interface.hh"

Interface::Interface(float timeMul, int cooksPerKitchen, int timeReplace)
  : _timeMul(timeMul), _cooksPerKitchen(cooksPerKitchen),
    _timeReplace(timeReplace)
{
}

int Interface::showUI()
{
  Reception *r = new Reception(_timeMul, _cooksPerKitchen, _timeReplace);
  int ac = 0;
  char *av[1] = {(char*) "Something"};

  MyApplication app(ac, av);
  MyWidget widget(_timeMul, _cooksPerKitchen, _timeReplace, r, 0);

  widget.show();

  return app.exec();
}
