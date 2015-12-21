//
// Teddy.hh for rush in /home/audibe_l/rendu/cpp_santa
// 
// Made by Audibert Louis
// Login   <audibe_l@epitech.net>
// 
// Started on  Sat Jan 17 09:44:19 2015 Audibert Louis
// Last update Sat Jan 17 10:23:33 2015 Audibert Louis
//

#ifndef _TEDDY_HH_
# define _TEDDY_HH_

# include "Toy.hh"

class	Teddy : public Toy
{
private:

public:
  Teddy(std::string const &name);
  Teddy(Teddy const &);
  ~Teddy();

  virtual void isTaken() const;
};

#endif
