//
// LittlePony.hh for rush2 in /home/audibe_l/rendu/cpp_santa
// 
// Made by Audibert Louis
// Login   <audibe_l@epitech.net>
// 
// Started on  Sat Jan 17 09:27:52 2015 Audibert Louis
// Last update Sat Jan 17 10:22:56 2015 Audibert Louis
//

#ifndef _LITTLEPONY_HH_
# define _LITTLEPONY_HH_

# include "Toy.hh"

class	LittlePony : public Toy
{
private:

public:
  LittlePony(std::string const &name);
  LittlePony(LittlePony const &);
  ~LittlePony();

  virtual void isTaken() const;
};

#endif
