//
// droid.hh for  in /home/nicolaschr/rendu/piscine_cpp_d08/ex00
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Jan 14 10:50:17 2015 Nicolas Charvoz
// Last update Wed Jan 14 17:35:12 2015 Nicolas Charvoz
//

#ifndef DROID_HH_
#define DROID_HH_

# include <string>
# include <iostream>

class Droid {
public:
  Droid(std::string id = "");
  Droid(Droid const&);
  ~Droid();
  void setId(std::string);
  std::string getId() const;
  void setEnergy(size_t);
  size_t getEnergy() const;
  std::string *getStatus() const;
  size_t getAttack() const;
  size_t getToughness()const;
  void setStatus(std::string*);
  bool operator==(Droid const&) const;
  bool operator!=(Droid const&) const;
  Droid &operator<<(size_t&);
  Droid &operator=(Droid const&);
private:
  std::string Id;
  size_t Energy;
  size_t const Attack;
  size_t const Toughness;
  std::string *Status;
};

std::ostream& operator<<(std::ostream&, Droid const&);


#endif
