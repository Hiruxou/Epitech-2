/*
** sickkoalalist.h for  in /home/nicolaschr/rendu/piscine_cpp_d06/ex05
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Mon Jan 12 16:19:02 2015 Nicolas Charvoz
** Last update Mon Jan 12 19:17:57 2015 Nicolas Charvoz
*/

#include <string>
#include <iostream>
#include "koaladoctor.h"

class KoalaDoctorList {
 private:
  KoalaDoctor *koala;
  KoalaDoctorList *next;

 public:
  KoalaDoctorList(KoalaDoctor *);
  ~KoalaDoctorList();
  bool isEnd();
  void append(KoalaDoctorList*);
  KoalaDoctor *getFromName(std::string);
  KoalaDoctorList *remove(KoalaDoctorList*);
  KoalaDoctorList *removeFromName(std::string);
  void dump();
  KoalaDoctorList *getContent();
  KoalaDoctorList *getNext();
};
