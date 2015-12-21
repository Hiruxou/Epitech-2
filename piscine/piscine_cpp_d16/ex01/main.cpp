//
// main.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d16/ex01
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Jan 21 20:40:35 2015 Nicolas Charvoz
// Last update Wed Jan 21 20:40:36 2015 Nicolas Charvoz
//

#include <iostream>
#include <cstdlib>
#include "DomesticKoala.h"
#include "KoalaAction.h"

int main()
{
  KoalaAction action;
  DomesticKoala *dk = new DomesticKoala(action);
  dk->learnAction('<', &KoalaAction::eat);
  dk->learnAction('>', &KoalaAction::goTo);
  dk->learnAction('#', &KoalaAction::sleep);
  dk->learnAction('X', &KoalaAction::reproduce);
  dk->doAction('>', "{EPITECH.}");
  dk->doAction('<', "a DoubleCheese");
  dk->doAction('X', "a Seagull");
  dk->doAction('#', "The end of the C++ pool, and an Astek burning on a stake");
  return 0;
}
