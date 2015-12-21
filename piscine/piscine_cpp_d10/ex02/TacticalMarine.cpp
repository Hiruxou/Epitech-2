//
// TacticalMarine.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex02
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 16:45:27 2015 Nicolas Charvoz
// Last update Fri Jan 16 16:45:40 2015 Nicolas Charvoz
//

#include "TacticalMarine.hh"

TacticalMarine::TacticalMarine() {
  speak("Tactical Marine ready for battle");
}

TacticalMarine::TacticalMarine(TacticalMarine const & marine) {
  (void) marine;

  speak("Tactical Marine ready for battle");
}

TacticalMarine::~TacticalMarine() {
  speak("Aaargh ...");
}

void TacticalMarine::speak(std::string message) const {
  std::cout << message << std::endl;
}

ISpaceMarine * TacticalMarine::clone() const {
  return new TacticalMarine(*this);
}

void TacticalMarine::battleCry() const {
  speak("For the holy PLOT !");
}

void TacticalMarine::rangedAttack() const {
  speak("* attacks with bolter *");
}

void TacticalMarine::meleeAttack() const {
  speak("* attacks with chainsword *");
}
