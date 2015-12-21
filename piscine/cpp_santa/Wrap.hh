//
// Wrap.hh for Wrap in /home/garcia_t/cpp_santa
//
// Made by antoine garcia
// Login   <garcia_t@epitech.net>
//
// Started on  Sat Jan 17 10:38:28 2015 antoine garcia
// Last update Sat Jan 17 23:09:29 2015 Nicolas Charvoz
//

#ifndef WRAP_HH__
#define WRAP_HH__

#include "Object.hh"

class	Wrap : public Object
{
protected:
  bool	_isOpen;
  Object	*_content;
public:
  Wrap(std::string const &name = "", int type = UNKNOWN);
  ~Wrap();
  Wrap(Wrap const &);
  Wrap&	operator=(Wrap const &);
  virtual void wrapMeThat(Object *) = 0;
  Object*		takeMe();
  void		openMe();
  void		closeMe();
  bool getIsOpen() const;
  bool getIsWrapped() const;
};

#endif
