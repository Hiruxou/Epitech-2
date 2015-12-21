//
// sickkoalalist.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d06/ex05
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Mon Jan 12 16:19:57 2015 Nicolas Charvoz
// Last update Mon Jan 12 21:40:53 2015 Nicolas Charvoz
//

#include "sickkoalalist.h"

SickKoalaList::SickKoalaList(SickKoala *koala)
{
  if (koala)
    {
      this->koala = koala;
      this->next = NULL;
    }
}

SickKoalaList::~SickKoalaList(){}

bool SickKoalaList::isEnd()
{
  if (this->next)
    return false;
  return true;
}

void SickKoalaList::append(SickKoalaList *koala)
{
  if (this->isEnd())
    this->next = koala;
  else
    this->next->append(koala);
}

SickKoala *SickKoalaList::getFromName(std::string string)
{
  if (this->koala && this->koala->getName() == string)
      return this->koala;
  else if (this->next)
    return this->next->getFromName(string);
  return NULL;
}

SickKoalaList *SickKoalaList::remove(SickKoalaList *koala)
{
  SickKoalaList *current = this;
  SickKoalaList *previous = NULL;

  while (current)
    {
      if (current == koala)
	{
	  if (previous)
	    {
	      previous->next = current->next;
	      current->next = NULL;
	      return this;
	    }
	  else
	    {
	      previous = current->next;
	      current->next = NULL;
	      return previous;
	    }
	}
      previous = current;
      current = current->next;
    }
  return NULL;
}

SickKoalaList *SickKoalaList::removeFromName(std::string string)
{
  SickKoalaList *current = this;
  SickKoalaList *previous = NULL;

  while (current)
    {
      if (current && current->koala && current->koala->getName() == string)
	{
	  if (previous)
	    {
	      previous->next = current->next;
	      current->next = NULL;
	      return this;
	    }
	  else
	    {
	      // previous = current->next;
	      // current->next = NULL;
	      // return previous;
	      return current->next;
	    }
	}
      previous = current;
      current = current->next;
    }
  return NULL;
}

void SickKoalaList::dump()
{
  SickKoalaList *current = this;

  std::cout << "Liste des patients : ";
  while (current)
    {
      if (current->koala)
	std::cout << current->koala->getName();
      else
	std::cout << "[NULL]";
      if (current->next)
	std::cout << ", ";
      else
	std::cout << "." << std::endl;
      current = current->next;
    }
}

SickKoalaList *SickKoalaList::getContent()
{
  if (this)
    return this;
  return NULL;
}

SickKoalaList *SickKoalaList::getNext()
{
  if (this->next)
    return this->next;
  return NULL;
}
