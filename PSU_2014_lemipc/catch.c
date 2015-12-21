/*
** catch.c for  in /home/nicolaschr/rendu/PSU_2014_lemipc
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Sat Mar  7 14:22:59 2015 Nicolas Charvoz
** Last update Sun Mar  8 21:29:50 2015 antoine garcia
*/

#include "lemipc.h"

void    catch(int sig)
{
  sig = sig;
  g_live = 0;
}
