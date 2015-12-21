//
// ncurse.hpp for nibbler in /home/audibe_l/rendu/cpp_nibbler/plugin/NCurse
// 
// Made by Audibert Louis
// Login   <audibe_l@epitech.net>
// 
// Started on  Thu Mar 26 17:43:17 2015 Audibert Louis
// Last update Fri Apr  3 17:23:03 2015 Audibert Louis
//

#ifndef _NCURSE_H_
# define _NCURSE_H_

# include <ncurses.h>
# include <iostream>
# include <cstdlib>
# include "../../IDisplayModule.hh"
# include "../../struct.h"
# include "../../define.h"

class NcursePlugin : public IDisplayModule
{
private:
  WINDOW *window;
  int	 limitX;
  int	 limitY;

public:
  NcursePlugin();
  ~NcursePlugin();
  virtual void init(int, int);
  virtual t_key getEvent();
  virtual void draw(std::list<Coord>, std::list<Apple> &);
  virtual void drawScore(const int);

  void	initTerminal();
  void  xmvwaddch(WINDOW *win, int y, int x, const chtype ch) const;
  void	drawWalls(int width, int height);
};

#endif
