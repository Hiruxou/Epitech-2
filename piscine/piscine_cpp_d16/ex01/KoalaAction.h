/*
** KoalaAction.h for  in /home/nicolaschr/rendu/piscine_cpp_d16/ex01
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Wed Jan 21 20:40:28 2015 Nicolas Charvoz
** Last update Wed Jan 21 20:40:29 2015 Nicolas Charvoz
*/

#ifndef KOALAACTION_H_
# define KOALAACTION_H_

# include <iostream>
# include <string>

class KoalaAction
{
 public:
  KoalaAction();
  virtual ~KoalaAction();
  void eat(const std::string &str);
  void sleep(const std::string &str);
  void goTo(const std::string &str);
  void reproduce(const std::string &str);
};

#endif
