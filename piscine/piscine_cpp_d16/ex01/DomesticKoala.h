/*
** DomesticKoala.h for  in /home/nicolaschr/rendu/piscine_cpp_d16/ex01
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Wed Jan 21 20:40:14 2015 Nicolas Charvoz
** Last update Wed Jan 21 20:40:15 2015 Nicolas Charvoz
*/

#ifndef _DOMESTICKOALA_H_
# define _DOMESTICKOALA_H_

# include <string>
# include <vector>
# include "KoalaAction.h"

class DomesticKoala
{
 public:
  explicit DomesticKoala(KoalaAction& action);
  virtual ~DomesticKoala();
  explicit DomesticKoala(DomesticKoala const& other);

  DomesticKoala& operator=(DomesticKoala const& other);
  typedef void (KoalaAction::*methodPointer_t)(std::string const&);
  std::vector<methodPointer_t> const* getActions() const;

  void learnAction(unsigned char c, methodPointer_t ptr);
  void unlearnAction(unsigned char c);
  void doAction(unsigned char, std::string const& str);
  void setKoalaAction(KoalaAction& action);

 private:
  KoalaAction _action;
  std::vector<methodPointer_t> _knowAction;
};

#endif
