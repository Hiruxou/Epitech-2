//
// sfml.hpp for nibbler in /home/audibe_l/rendu/cpp_nibbler/plugin
//
// Made by Audibert Louis
// Login   <audibe_l@epitech.net>
//
// Started on  Thu Mar 26 13:24:47 2015 Audibert Louis
// Last update Sat Apr  4 12:02:10 2015 Audibert Louis
//

#ifndef _SFML_H_
# define _SFML_H_

# include <SFML/Graphics.hpp>
# include <SFML/Window.hpp>
# include <iostream>
# include <sstream>
# include <map>
# include <cstdlib>
# include "../../IDisplayModule.hh"
# include "../../struct.h"
# include "../../define.h"

enum e_img
  {
    S_BACKGROUND,
    S_BODY,
    S_HEAD,
    S_APPLE,
    S_GOLDEN
  };

enum e_sprite
  {
    BACKGROUND,
    BODY,
    HEAD,
    APPLE,
    GOLDEN
  };

class SfmlPlugin : public IDisplayModule
{
private:
  sf::RenderWindow window;
  std::map<e_img, sf::Image> _Img;
  std::map<e_sprite, sf::Sprite> _Block;
  sf::Font	font;
  sf::String	_Score;
  sf::String	_GameOver;

public:
  SfmlPlugin();
  ~SfmlPlugin();
  virtual void init(int, int);
  virtual t_key getEvent();
  virtual void draw(std::list<Coord>, std::list<Apple>&);
  virtual void drawScore(const int);

  void	initImg();
  void	setBlocks();
  void	setScore();
};

#endif
