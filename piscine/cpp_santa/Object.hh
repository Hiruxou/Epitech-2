//
// Object.hh for Object in /home/garcia_t/cpp_santa
//
// Made by antoine garcia
// Login   <garcia_t@epitech.net>
//
// Started on  Sat Jan 17 09:27:23 2015 antoine garcia
// Last update Sat Jan 17 23:05:54 2015 Nicolas Charvoz
//

#ifndef OBJ_HH__
#define OBJ_HH__

#include <string>

typedef	enum e_obj
  {
    LITTLEPONY,
    TEDDY,
    BOX,
    GIFTPAPER,
    UNKNOWN
  }Objects;

class	Object
{
protected:
  std::string _name;
  int	      _type;
public:
  Object(std::string const &name = "", int type = UNKNOWN);
  virtual ~Object(){};
  Object(Object const &);
  Object&	operator=(Object const &);
  std::string const &getName() const;
  int getType() const;
};

#endif
