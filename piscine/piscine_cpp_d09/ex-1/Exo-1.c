/*
** Ex-1.c for  in /home/nicolaschr/rendu/piscine_cpp_d09/ex-1
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Thu Jan 15 10:11:01 2015 Nicolas Charvoz
** Last update Fri Jan 16 09:20:07 2015 Nicolas Charvoz
*/

#include "Exo-1.h"

static void KoalaInitializer(t_koala *this, char *_name, char _isALegend);
static void CthulhuInitializer(t_cthulhu *this);

static void KoalaInitializer(t_koala *this, char *_name, char _isALegend)
{
  CthulhuInitializer(&this->m_parent);
  this->m_parent.m_name = _name;
  this->m_parent.m_power = (_isALegend ? 42 : 0);
  this->m_isALegend = _isALegend;
  printf("Building %s\n", this->m_parent.m_name);
}

static void CthulhuInitializer(t_cthulhu *this)
{
  printf("----\n");
  this->m_name = malloc(8 *sizeof(char));
  strcpy(this->m_name, "Cthulhu");
  this->m_power = 42;
  printf("Building Cthulhu\n");
}

t_cthulhu *NewCthulhu()
{
  t_cthulhu *new;

  new = malloc(sizeof(t_cthulhu));
  if (new)
    CthulhuInitializer(new);
  return new;
}

void PrintPower(t_cthulhu *this)
{
  if (this)
    {
      printf("Power => %d\n", this->m_power);
    }
}

void Attack(t_cthulhu *this)
{
  if (this->m_power >= 42)
    {
      this->m_power -= 42;
      printf("%s attacks and destroys the city\n", this->m_name);
    }
  else
    printf("%s can't attack, he doesn't have enough power\n", this->m_name);
}

void Sleeping(t_cthulhu *this)
{
  this->m_power += 42000;
  printf("%s sleeps\n", this->m_name);
}

t_koala *NewKoala(char *name, char _isALegend)
{
  t_koala *new;

  new = malloc(sizeof(t_koala));
  if (new)
    KoalaInitializer(new, name, _isALegend);

  return new;
}

void Eat(t_koala *this)
{
  this->m_parent.m_power += 42;
  printf("%s eats\n", this->m_parent.m_name);
}
