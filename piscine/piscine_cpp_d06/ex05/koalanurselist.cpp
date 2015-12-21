//
// sickkoalalist.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d06/ex05
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Mon Jan 12 16:19:57 2015 Nicolas Charvoz
// Last update Mon Jan 12 21:32:44 2015 Nicolas Charvoz
//

#include "koalanurselist.h"

KoalaNurseList::KoalaNurseList(KoalaNurse *koala)
{
  if (koala)
    {
      this->koala = koala;
      this->next = NULL;
    }
}

KoalaNurseList::~KoalaNurseList(){}

bool KoalaNurseList::isEnd()
{
  if (this->next)
    return false;
  return true;
}

void KoalaNurseList::append(KoalaNurseList *koala)
{
  if (this->isEnd())
    this->next = koala;
  else
    this->next->append(koala);
}

KoalaNurse *KoalaNurseList::getFromID(int id)
{
  if (this->koala && this->koala->getID() == id)
      return this->koala;
  else if (this->next)
    return this->next->getFromID(id);
  return NULL;
}

KoalaNurseList *KoalaNurseList::remove(KoalaNurseList *koala)
{
  KoalaNurseList *current = this;
  KoalaNurseList *previous = NULL;

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

KoalaNurseList *KoalaNurseList::removeFromID(int id)
{
  KoalaNurseList *current = this;
  KoalaNurseList *previous = NULL;

  while (current)
    {
      if (current && current->koala && current->koala->getID() == id)
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

void KoalaNurseList::dump()
{
  KoalaNurseList *current = this;

  std::cout << "Liste des infirmieres : ";
  while (current)
    {
      if (current->koala)
	std::cout << current->koala->getID();
      else
	std::cout << "[NULL]";
      if (current->next)
	std::cout << ", ";
      else
	std::cout << "." << std::endl;
      current = current->next;
    }
}

KoalaNurseList *KoalaNurseList::getContent()
{
  if (this)
    return this;
  return NULL;
}

KoalaNurseList *KoalaNurseList::getNext()
{
  if (this->next)
    return this->next;
  return NULL;
}
