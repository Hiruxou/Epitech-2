//
// sfml.cpp for nibbler in /home/audibe_l/rendu/cpp_nibbler/plugin
//
// Made by Audibert Louis
// Login   <audibe_l@epitech.net>
//
// Started on  Thu Mar 26 13:26:19 2015 Audibert Louis
// Last update Sat Apr  4 18:06:39 2015 Audibert Louis
//

#include "sfml.hpp"

SfmlPlugin::SfmlPlugin()
{

}

SfmlPlugin::~SfmlPlugin()
{
  std::cout << "Destructor called." << std::endl;
  window.Close();
}

void	SfmlPlugin::init(int width, int height)
{
  window.Create(sf::VideoMode((width * CASE_SIZE), (height * CASE_SIZE), 32),
				 "Nibbler Garcia_t Charvo_a Audibe_l SFML");
  window.SetFramerateLimit(60);
  window.Clear(sf::Color(105, 105, 105));
  this->initImg();
  this->setBlocks();
  this->setScore();
  window.Display();
}

void	SfmlPlugin::setScore()
{
  if (!font.LoadFromFile("./res/game_over.ttf"))
    {
      _Score.SetFont(font);
      _Score.SetSize(24);
      _Score.SetColor(sf::Color::Red);
    }
}

void	SfmlPlugin::initImg()
{
  if (!(this->_Img[S_BACKGROUND].LoadFromFile("./plugin/SFML/img/background.png")))
    return;
    // throw Sfml::libException(LIB, "./plugin/SFML/img/background.jpg is not found", IMGLOAD);
  if (!(this->_Img[S_BODY].LoadFromFile("./plugin/SFML/img/body.png")))
    return;
    // throw Sfml::libException(LIB, "../img/topi_ground.png is not found", IMGLOAD);
  if (!(this->_Img[S_HEAD].LoadFromFile("./plugin/SFML/img/head.png")))
    return;
    // throw Sfml::libException(LIB, "../img/trio_ground.png is not found", IMGLOAD);
  if (!(this->_Img[S_APPLE].LoadFromFile("./plugin/SFML/img/apple.png")))
    return;
  if (!(this->_Img[S_GOLDEN].LoadFromFile("./plugin/SFML/img/golden.png")))
    return;
    // throw Sfml::libException(LIB, "../img/pokeball_trans.png is not found", IMGLOAD);
}

void	SfmlPlugin::setBlocks()
{
  this->_Block[BACKGROUND].SetImage(this->_Img[S_BACKGROUND]);
  this->_Block[BODY].SetImage(this->_Img[S_BODY]);
  this->_Block[HEAD].SetImage(this->_Img[S_HEAD]);
  this->_Block[APPLE].SetImage(this->_Img[S_APPLE]);
  this->_Block[GOLDEN].SetImage(this->_Img[S_GOLDEN]);
}

t_key	SfmlPlugin::getEvent()
{
  sf::Event event;

  window.GetEvent(event);
  if (event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Key::Left)
    return (RIGHT_KEY);
  if (event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Key::Right)
    return (LEFT_KEY);
  if (event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Key::Space)
    return (SPACE_KEY);
  if ((event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Key::Escape) ||
      event.Type == sf::Event::Closed)
    return (ESC_KEY);
  window.Display();
  return (NONE);
}

void	SfmlPlugin::drawScore(const int Score)
{
  std::stringstream myScore;
  std::string  str;

  myScore << "Score: " << Score;
  this->_Score.SetText(myScore.str());
  window.Draw(this->_Score);
}


void	SfmlPlugin::draw(std::list<Coord> Snake, std::list<Apple> &Apples)
{
  window.Clear(sf::Color(105, 105, 105));
  for (std::list<Coord>::iterator it=Snake.begin(); it != Snake.end(); ++it)
    {
      if (it == Snake.begin())
	{
	  _Block[HEAD].SetPosition(sf::Vector2f(((*it)._x * CASE_SIZE), ((*it)._y) * CASE_SIZE));
	  window.Draw(_Block[HEAD]);
	}
      else
	{
	  _Block[BODY].SetPosition(sf::Vector2f(((*it)._x * CASE_SIZE), ((*it)._y) * CASE_SIZE));
	  window.Draw(_Block[BODY]);
	}
    }
  for (std::list<Apple>::iterator it=Apples.begin(); it != Apples.end(); ++it)
    {
      if ((*it).getType() == BIG_APPLE)
	{
	  _Block[GOLDEN].SetPosition(sf::Vector2f((*it).getCoord()._x * CASE_SIZE, (*it).getCoord()._y * CASE_SIZE));
	  window.Draw(_Block[GOLDEN]);
	}
      else
	{
	  _Block[APPLE].SetPosition(sf::Vector2f((*it).getCoord()._x * CASE_SIZE, (*it).getCoord()._y * CASE_SIZE));
	  window.Draw(_Block[APPLE]);
	}
    }
}

extern "C"  IDisplayModule * call()
{
  return (new SfmlPlugin());
}
