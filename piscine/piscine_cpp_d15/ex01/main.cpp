//
// main.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d15/ex01
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Jan 20 19:51:14 2015 Nicolas Charvoz
// Last update Tue Jan 20 19:53:48 2015 Nicolas Charvoz
//

#include "ex01.hpp"

class toto
{
private:
  toto &operator=(const toto&) {return *this;}
  toto(const toto &){}
public:
  bool operator==(const toto&) const {return true;}
  bool operator>(const toto&) const {return false;}
  bool operator<(const toto&) const {return false;}
  toto(){}
};

int		main()
{
  toto a, b;

  std::cout << compare(a, b) <<std::endl;
  std::cout << compare(1, 2) <<std::endl;

  std::cout << compare<const char*>("chaineZ", "chaineA42")
	    <<std::endl;

  const char *s1 = "42", *s2 = "lulz";

  std::cout << compare(s1, s2) <<std::endl;

  return (0);
}
