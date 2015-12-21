//
// ncurse.cpp for nibbler in /home/audibe_l/rendu/cpp_nibbler/plugin/NCurse
//
// Made by Audibert Louis
// Login   <audibe_l@epitech.net>
//
// Started on  Thu Mar 26 17:47:05 2015 Audibert Louis
// Last update Sat Apr  4 18:07:22 2015 Audibert Louis
//

#include "ncurse.hpp"

NcursePlugin::NcursePlugin()
{

}

NcursePlugin::~NcursePlugin()
{
  std::cout << "Destructor called." << std::endl;
  wclear(window);
  endwin();
}

void	NcursePlugin::drawWalls(int width, int height)
{
  for (int x=0; x <= width; ++x)
    mvwaddch(window, height - 1, x - 1, ' ' | A_REVERSE);
  for (int y=0; y <= height; ++y)
    mvwaddch(window, y - 1, width - 1, ' ' | A_REVERSE);
}

void	NcursePlugin::init(int width, int height)
{
  initscr();
  window = newwin(150, 150, 0, 0);
  cbreak();
  initTerminal();
  drawWalls(width, height);
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);
  limitX = width;
  limitY = height;
}

void	NcursePlugin::initTerminal()
{
  if (keypad(window, true) == ERR)
    return;
    // throw Ncurse::libException(LIB, "Keypad activation failed", INIT);
  if (noecho() == ERR)
    return;
    // throw Ncurse::libException(LIB, "NoEcho mode activation failed", INIT);
  if (curs_set(0) == ERR)
    return;
  nodelay(window, true);
  wrefresh(window);
}

t_key	NcursePlugin::getEvent()
{
  int	c;

  c = wgetch(window);
  if (c == KEY_LEFT)
    return (RIGHT_KEY);
  if (c == KEY_RIGHT)
    return (LEFT_KEY);
  if (c == KEY_END)
    return (ESC_KEY);
  return (NONE);
}


void	NcursePlugin::xmvwaddch(WINDOW *win, int y, int x, const chtype ch) const
{
  if (mvwaddch(win, y, x, ch) == ERR)
    {
      std::cout << "mvwaddch planted" << std::endl;
      exit (-1);
    }
    // throw Ncurse::libException(LIB, "Can't move the block", WIN);
}

void	NcursePlugin::drawScore(const int Score)
{
  mvwprintw(window, limitY + 2, (limitX / 2) - 4, "Score: %d\n", Score);
  wrefresh(window);
}

void	NcursePlugin::draw(std::list<Coord> Snake, std::list<Apple> &Apples)
{
  werase(window);
  drawWalls(limitX + 1, limitY + 1);
  for (std::list<Coord>::iterator it=Snake.begin(); it != Snake.end(); ++it)
    {
      if ((*it)._y < limitY && (*it)._x < limitX)
	{
	  if (it == Snake.begin())
	    xmvwaddch(window, (*it)._y, (*it)._x, 'X');
	  else
	    xmvwaddch(window, (*it)._y, (*it)._x, 'N');
	}
   }
  for (std::list<Apple>::iterator it=Apples.begin(); it != Apples.end(); ++it)
    {
      if ((*it).getType() == BIG_APPLE)
	{
	  wattron(window, COLOR_PAIR(2));
	  xmvwaddch(window, (*it).getCoord()._y, (*it).getCoord()._x, 'O');
	  wattroff(window, COLOR_PAIR(2));
	}
      else
	{
	  wattron(window, COLOR_PAIR(1));
	  xmvwaddch(window, (*it).getCoord()._y, (*it).getCoord()._x, 'O');
	  wattroff(window, COLOR_PAIR(1));
	}
    }

}

extern "C" IDisplayModule * call()
{
  return (new NcursePlugin());
}
