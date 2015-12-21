/*
** Ex-1.h for  in /home/nicolaschr/rendu/piscine_cpp_d09/ex-1
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Thu Jan 15 10:11:07 2015 Nicolas Charvoz
** Last update Thu Jan 15 10:47:28 2015 Nicolas Charvoz
*/

#ifndef EX_1_H_
#define EX_1_H_

#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef struct 		s_cthulhu {
  int m_power;
  char *m_name;
}			t_cthulhu;

typedef struct s_koala {
  t_cthulhu m_parent;
  char m_isALegend;
}	t_koala;

t_cthulhu *NewCthulhu();
void PrintPower(t_cthulhu*);
void Attack(t_cthulhu*);
void Sleeping(t_cthulhu*);
t_koala *NewKoala(char*, char);
void Eat(t_koala*);

#endif
