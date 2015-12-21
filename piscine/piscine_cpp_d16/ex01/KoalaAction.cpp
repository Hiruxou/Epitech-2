//
// KoalaAction.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d16/ex01
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Jan 21 20:40:21 2015 Nicolas Charvoz
// Last update Wed Jan 21 20:40:22 2015 Nicolas Charvoz
//

#include "KoalaAction.h"

KoalaAction::KoalaAction()
{
}

KoalaAction::~KoalaAction()
{
}

void KoalaAction::eat(const std::string &str)
{
  std::cout << "I eat: " << str << std::endl;
}

void KoalaAction::sleep(const std::string &str)
{
  std::cout << "I sleep, and dream of: " << str << std::endl;
}

void KoalaAction::goTo(const std::string &str)
{
  std::cout << "I go to: " << str << std::endl;
}

void KoalaAction::reproduce(const std::string &str)
{
  std::cout << "I attempt to reproduce with: " << str << std::endl;
}
