//
// GiftPaper.hh for rush2 in /home/audibe_l/rendu/cpp_santa
//
// Made by Audibert Louis
// Login   <audibe_l@epitech.net>
//
// Started on  Sat Jan 17 10:38:43 2015 Audibert Louis
// Last update Sat Jan 17 23:04:06 2015 Nicolas Charvoz
//

#ifndef _GIFTPAPER_HH_
# define _GIFTPAPER_HH_

# include "Wrap.hh"
# include <iostream>

class	GiftPaper : public Wrap
{
private:

public:
  GiftPaper(std::string const &name = "");
  GiftPaper(GiftPaper const &);
  ~GiftPaper();

  virtual void wrapMeThat(Object *);

};

#endif
