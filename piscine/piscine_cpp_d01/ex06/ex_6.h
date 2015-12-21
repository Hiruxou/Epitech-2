/*
** ex_6.h for  in /home/charvo_a/rendu/piscine_cpp_d01/ex06
**
** Made by Charvoz Nicolas
** Login   <charvo_a@epitech.net>
**
** Started on  Wed Jan  7 15:59:23 2015 Charvoz Nicolas
** Last update Thu Jan  8 09:01:13 2015 NicolasCharvoz
*/

#ifndef EX_6_H_
#define EX_6_H_

typedef union	s_bar
{
  short int	foo;
  short int	bar;
}		t_bar;

typedef struct	s_charvoz
{
  short int	foo;
  t_bar		bar;
}		t_charvoz;

typedef union	s_foo
{
  int		bar;
  t_charvoz	foo;
}		t_foo;

#endif
