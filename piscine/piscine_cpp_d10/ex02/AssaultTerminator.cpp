//
// AssaultTerminator.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex02
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 16:39:53 2015 Nicolas Charvoz
// Last update Fri Jan 16 16:40:17 2015 Nicolas Charvoz
//

#include "AssaultTerminator.hh"

AssaultTerminator::AssaultTerminator() {
  speak("* teleports from space *");
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const & marine) {
  (void) marine;
  speak("* teleports from space *");
}

AssaultTerminator::~AssaultTerminator() {
  speak("I'll be back ...");
}

void AssaultTerminator::speak(std::string message) const {
  std::cout << message << std::endl;
}

ISpaceMarine * AssaultTerminator::clone() const {
  return new AssaultTerminator(*this);
}

void AssaultTerminator::battleCry() const {
  speak("This code is unclean. PURIFY IT !");
}

void AssaultTerminator::rangedAttack() const {
  speak("* does nothing *");
}

void AssaultTerminator::meleeAttack() const {
  speak("* attacks with chainfists *");
}
