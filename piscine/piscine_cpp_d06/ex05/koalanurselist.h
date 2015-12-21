/*
** sickkoalalist.h for  in /home/nicolaschr/rendu/piscine_cpp_d06/ex05
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Mon Jan 12 16:19:02 2015 Nicolas Charvoz
** Last update Mon Jan 12 19:11:44 2015 Nicolas Charvoz
*/

#include <string>
#include <iostream>
#include "koalanurse.h"

class KoalaNurseList {
 private:
  KoalaNurse *koala;
  KoalaNurseList *next;

 public:
  KoalaNurseList(KoalaNurse *);
  ~KoalaNurseList();
  bool isEnd();
  void append(KoalaNurseList*);
  KoalaNurse *getFromID(int);
  KoalaNurseList *remove(KoalaNurseList*);
  KoalaNurseList *removeFromID(int);
  void dump();
  KoalaNurseList *getContent();
  KoalaNurseList *getNext();
};
