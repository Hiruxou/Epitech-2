//
// opengl.hpp for  in /home/nicolaschr/rendu/cpp_nibbler/plugin
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Thu Mar 26 13:23:21 2015 Nicolas Charvoz
// Last update Sat Apr  4 20:09:47 2015 Nicolas Charvoz
//

#ifndef OPENGL_HPP
# define OPENGL_HPP

# include <SDL/SDL.h>
# include <SDL/SDL_image.h>
# include <GL/glu.h>
# include <GL/gl.h>
# include <GL/freeglut.h>
# include <X11/Xlib.h>
# include <iostream>
# include <ostream>
# include <sstream>
# include <string>
# include <unistd.h>
# include "../../IDisplayModule.hh"
# include "../../LibException.hpp"
# include "../../struct.h"
# include "../../define.h"

# define SIZE_X 800
# define SIZE_Y 800
# define ZFAR 1300
# define EYE_X 400
# define EYE_Y -200
# define EYE_Z 560
# define VEC_X 0
# define VEC_Y 0
# define VEC_Z 0
# define LARGE 20
# define WALL_COLOR 0x003399
# define COINS_COLOR 0xFFFFFFFF

class OpenGLPlugin : public IDisplayModule {

public:
  OpenGLPlugin();
  ~OpenGLPlugin();
  virtual void init(int, int);
  virtual t_key getEvent();
  virtual void draw(std::list<Coord>, std::list<Apple>&);
  virtual void drawScore(const int);
  void windowInitializer(int, int, int, int);
  void drawSquare(int, int, unsigned int);
  int getColorInt(int, char) const;
  void createCoins(int, int);
  void drawBorder(int, int, unsigned int);
  void createBorder(int, int);

private:
  int _width;
  int _height;
  int _xRatio;
  int _yRatio;
  bool _isOpen;
  SDL_Surface *_window;
};

#endif
