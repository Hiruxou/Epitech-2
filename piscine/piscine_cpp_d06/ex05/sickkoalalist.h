/*
** sickkoalalist.h for  in /home/nicolaschr/rendu/piscine_cpp_d06/ex05
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Mon Jan 12 16:19:02 2015 Nicolas Charvoz
** Last update Mon Jan 12 19:00:24 2015 Nicolas Charvoz
*/

#include <string>
#include <iostream>
#include "sickkoala.h"

class SickKoalaList {
 private:
  SickKoala *koala;
  SickKoalaList *next;

 public:
  SickKoalaList(SickKoala *);
  ~SickKoalaList();
  bool isEnd();
  void append(SickKoalaList*);
  SickKoala *getFromName(std::string);
  SickKoalaList *remove(SickKoalaList*);
  SickKoalaList *removeFromName(std::string);
  void dump();
  SickKoalaList *getContent();
  SickKoalaList *getNext();
};
