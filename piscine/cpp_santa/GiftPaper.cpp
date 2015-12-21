//
// GiftPaper.cpp for rush2 in /home/audibe_l/rendu/cpp_santa
//
// Made by Audibert Louis
// Login   <audibe_l@epitech.net>
//
// Started on  Sat Jan 17 10:38:47 2015 Audibert Louis
// Last update Sun Jan 18 00:18:39 2015 Nicolas Charvoz
//

#include "GiftPaper.hh"

GiftPaper::GiftPaper(std::string const &name): Wrap(name, GIFTPAPER)
{
}

GiftPaper::GiftPaper(GiftPaper const &paper): Wrap(paper._name, GIFTPAPER)
{

}

GiftPaper::~GiftPaper()
{

}

void GiftPaper::wrapMeThat(Object *content)
{
  if (this->_content == NULL)
    {
      this->_content = content;
      std::cout << "[Elf wrapping the gift] : *tuuuut tuuut tuut*"
		<< std::endl;
    }
  else
    std::cerr << "\033[31m\033[1m[Elf wrapping the gift] : Cannot Wrap: I'm not empty.\033[0m" << std::endl;
}
