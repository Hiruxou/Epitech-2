//
// opengl.cpp for  in /home/nicolaschr/rendu/cpp_nibbler/plugin
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Thu Mar 26 13:24:44 2015 Nicolas Charvoz
// Last update Sat Apr  4 20:11:00 2015 Nicolas Charvoz
//

#include "opengl.hpp"

OpenGLPlugin::OpenGLPlugin() {}

OpenGLPlugin::~OpenGLPlugin()
{
  _isOpen = false;
  glEnd();
  SDL_FreeSurface(_window);
  SDL_Quit();
}

void	OpenGLPlugin::windowInitializer(int sizeX, int sizeY,
				     int width, int height)
{
  _width = width;
  _height = height;
  _xRatio = sizeX/width;
  _yRatio = sizeY/height;
  _isOpen = true;
}

void	OpenGLPlugin::init(int width, int height)
{
  int ac = 1;
  char *av[1] = {(char*)"Something"};

  XInitThreads();
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    throw LibException("Initialization of SDL failed\n");
  _window = SDL_SetVideoMode(1920, 1080, 32, SDL_OPENGL);
  if (!_window)
    throw LibException("Initialization of SDL VideoMode failed\n");
  glutInit(&ac, av);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  SDL_WM_SetCaption("Nibbler Garcia_t Charvo_a Audibe_l OpenGL", NULL);
  gluPerspective(100, (double)SIZE_X/SIZE_Y, 1, ZFAR);
  gluLookAt(EYE_X, EYE_Y, EYE_Z, SIZE_X/2, SIZE_Y/2, VEC_X, VEC_Y, VEC_Z, 1);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_TEXTURE_2D);
  windowInitializer(SIZE_X, SIZE_Y, width, height);
}

void OpenGLPlugin::drawScore(const int score)
{
  std::stringstream	ss;

  ss << "Score: " << score;
  glRasterPos2i(-430, -50);
  glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
  glutBitmapString(GLUT_BITMAP_HELVETICA_18,
		   reinterpret_cast<unsigned const char*>(ss.str().c_str()));
  SDL_GL_SwapBuffers();
}

void OpenGLPlugin::draw(std::list<Coord> snake, std::list<Apple> &apple)
{
  unsigned int colorHead = 0x8DB600;
  unsigned int colorBody = 0x915C83;
  unsigned int colorApple = 0xFF0800;
  unsigned int colorAppleGold = 0xFFD700;

  unsigned int color = 0x915C83;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3ub(this->getColorInt(color, 'R'),
  	     this->getColorInt(color, 'G'),
  	     this->getColorInt(color, 'B'));

  glVertex3d(0, 0, 0);
  glVertex3d(0, 1, 0);
  glVertex3d(-1, 1, 0);
  glVertex3d(-1, 0, 0);
  for (std::list<Coord>::iterator it = snake.begin() ; it != snake.end() ; ++it)
    {
      if (it == snake.begin())
  	drawSquare((*it)._x, (*it)._y, colorHead);
      else
  	drawSquare((*it)._x, (*it)._y, colorBody);
    }
  for (std::list<Apple>::iterator it = apple.begin() ; it != apple.end() ; ++it)
    {
      if ((*it).getType() == BIG_APPLE)
	drawSquare((*it).getCoord()._x, (*it).getCoord()._y, colorAppleGold);
      else
	drawSquare((*it).getCoord()._x, (*it).getCoord()._y, colorApple);
    }
}

int OpenGLPlugin::getColorInt(int color, char comp) const
{
  if (comp == 'R')
    return ((color >> 16) & 255);
  if (comp == 'G')
    return ((color >> 8) & 255);
  if (comp == 'B')
    return (color & 255);
}

void		OpenGLPlugin::drawSquare(int x, int y, unsigned int color)
{
  int		xPos = SIZE_X / _width;
  int		yPos = SIZE_Y / _height;

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslated((x * SIZE_X / _width),
	       SIZE_Y - (SIZE_Y/_height) - (y * SIZE_Y / _height), 0);
  glBegin(GL_QUADS);
  glColor3ub(this->getColorInt(color, 'R'),
  	     this->getColorInt(color, 'G'),
  	     this->getColorInt(color, 'B'));

  glVertex3d(0,0,LARGE);
  glVertex3d(0,0,-LARGE);
  glVertex3d(SIZE_X/_width,0,-LARGE);
  glVertex3d(SIZE_X/_width,0,LARGE);

  glVertex3d(0,SIZE_Y/_height,LARGE);
  glVertex3d(0,SIZE_Y/_height,-LARGE);
  glVertex3d(0,0,-LARGE);
  glVertex3d(0,0,LARGE);
  glColor3ub(this->getColorInt(color + 50, 'R'),
  	     this->getColorInt(color + 50, 'G'),
  	     this->getColorInt(color + 50, 'B'));
  glVertex3d(xPos,SIZE_Y/_height,LARGE);
  glVertex3d(xPos,SIZE_Y/_height,-LARGE);
  glVertex3d(xPos,0,-LARGE);
  glVertex3d(xPos,0,LARGE);

  glVertex3d(SIZE_X/_width, (SIZE_Y/_height),LARGE);
  glVertex3d(SIZE_X/_width, (SIZE_Y/_height),-LARGE);
  glVertex3d(0, (SIZE_Y/_height),-LARGE);
  glVertex3d(0, (SIZE_Y/_height),LARGE);
  glColor3ub(this->getColorInt(color + 60, 'R'),
  	     this->getColorInt(color + 60, 'G'),
  	     this->getColorInt(color + 60, 'B'));
  glVertex3d(0,0,LARGE);
  glVertex3d(0, (SIZE_Y/_height),LARGE);
  glVertex3d(SIZE_X/_width, (SIZE_Y/_height),LARGE);
  glVertex3d(SIZE_X/_width, 0, LARGE);

  glEnd();
  glFlush();
  this->createCoins(x, y);
  this->createBorder(_width, _height);
}

void		OpenGLPlugin::createCoins(int x, int y)
{
  int		xPos = SIZE_X / _width;
  int		yPos = SIZE_Y / _height;
  unsigned int color = COINS_COLOR;

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslated((x * SIZE_X / _width),
	       SIZE_Y - (SIZE_Y/_height) - (y * SIZE_Y / _height), 0);
  glBegin(GL_LINES);
  glColor3ub(this->getColorInt(color, 'R'),
  	     this->getColorInt(color, 'G'),
	     this->getColorInt(color, 'B'));

  glVertex3d(0,0,LARGE);
  glVertex3d(0, (SIZE_Y/_height),LARGE);
  glVertex3d(SIZE_X/_width, (SIZE_Y/_height),LARGE);
  glVertex3d(SIZE_X/_width, 0,LARGE);

  glVertex3d(0,0,LARGE);
  glVertex3d(SIZE_X/_width, 0,LARGE);
  glVertex3d(SIZE_X/_width, (SIZE_Y/_height),LARGE);
  glVertex3d(0, SIZE_Y/_height,LARGE);

  glVertex3d(0,0,LARGE);
  glVertex3d(0,0,0);
  glVertex3d(SIZE_X/_width,0,LARGE);
  glVertex3d(SIZE_X/_width,0,0);

  glVertex3d(0,SIZE_Y/_height,LARGE);
  glVertex3d(0,SIZE_Y/_height,0);

  glEnd();
}

void		OpenGLPlugin::drawBorder(int x, int y, unsigned int color)
{
  int		xPos = SIZE_X / _width;
  int		yPos = SIZE_Y / _height;

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity( );
  glTranslated((x * SIZE_X / _width),
	       SIZE_Y - (SIZE_Y/_height) - (y * SIZE_Y / _height), 0);
  glBegin(GL_QUADS);
  glColor3ub(this->getColorInt(color, 'R'),
  	     this->getColorInt(color, 'G'),
  	     this->getColorInt(color, 'B'));

  glVertex3d(0,0,LARGE);
  glVertex3d(0,0,-LARGE);
  glVertex3d(SIZE_X/_width,0,-LARGE);
  glVertex3d(SIZE_X/_width,0,LARGE);

  glColor3ub(this->getColorInt(color + 40, 'R'),
	     this->getColorInt(color + 40, 'G'),
	     this->getColorInt(color + 40, 'B'));

  glVertex3d(0,SIZE_Y/_height,LARGE);
  glVertex3d(0,SIZE_Y/_height,-LARGE);
  glVertex3d(0,0,-LARGE);
  glVertex3d(0,0,LARGE);

  glVertex3d(xPos,SIZE_Y/_height,LARGE);
  glVertex3d(xPos,SIZE_Y/_height,-LARGE);
  glVertex3d(xPos,0,-LARGE);
  glVertex3d(xPos,0,LARGE);

  glColor3ub(this->getColorInt(color + 100, 'R'),
  	     this->getColorInt(color + 100, 'G'),
  	     this->getColorInt(color + 100, 'B'));
  glVertex3d(SIZE_X/_width, (SIZE_Y/_height),LARGE);
  glVertex3d(SIZE_X/_width, (SIZE_Y/_height),-LARGE);
  glVertex3d(0, (SIZE_Y/_height),-LARGE);
  glVertex3d(0, (SIZE_Y/_height),LARGE);

  glVertex3d(0,0,LARGE);
  glVertex3d(0, (SIZE_Y/_height),LARGE);
  glVertex3d(SIZE_X/_width, (SIZE_Y/_height),LARGE);
  glVertex3d(SIZE_X/_width, 0, LARGE);

  glEnd();
}

void		OpenGLPlugin::createBorder(int x, int y)
{
  for (int i = -1; i <= x; i++)
    this->drawBorder(i, -2, WALL_COLOR);
  for (int j = -1; j <= y; j++)
    {
      this->drawBorder(-1, j, WALL_COLOR);
      this->drawBorder(x, j, WALL_COLOR);
    }
  for (int k = 0; k <= x; k++)
    this->drawBorder(k, y, WALL_COLOR);
}

t_key		OpenGLPlugin::getEvent()
{
  SDL_Event	event;

  SDL_PollEvent(&event);
  switch (event.type)
    {
    case SDL_QUIT:
      return ESC_KEY;
      break;
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym)
	{
	case SDLK_LEFT:
	  return RIGHT_KEY;
	  break;
	case SDLK_RIGHT:
	  return LEFT_KEY;
	  break;
	case SDLK_ESCAPE:
	  return ESC_KEY;
	  break;
	case SDLK_SPACE:
	  return SPACE_KEY;
	  break;
	}
      break;
    }
  SDL_GL_SwapBuffers();
  return NONE;
}

extern "C"	IDisplayModule	*call()
{
  return (new OpenGLPlugin());
}
