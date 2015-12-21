//
// sickkoalalist.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d06/ex05
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Mon Jan 12 16:19:57 2015 Nicolas Charvoz
// Last update Mon Jan 12 21:32:16 2015 Nicolas Charvoz
//

#include "koaladoctorlist.h"

KoalaDoctorList::KoalaDoctorList(KoalaDoctor *koala)
{
  if (koala)
    {
      this->koala = koala;
      this->next = NULL;
    }
}

KoalaDoctorList::~KoalaDoctorList(){}

bool KoalaDoctorList::isEnd()
{
  if (this->next)
    return false;
  return true;
}

void KoalaDoctorList::append(KoalaDoctorList *koala)
{
  if (this->isEnd())
    this->next = koala;
  else
    this->next->append(koala);
}

KoalaDoctor *KoalaDoctorList::getFromName(std::string string)
{
  if (this->koala && this->koala->getName() == string)
    return this->koala;
  else if (this->next)
    return this->next->getFromName(string);
  return NULL;
}

KoalaDoctorList *KoalaDoctorList::remove(KoalaDoctorList *koala)
{
  KoalaDoctorList *current = this;
  KoalaDoctorList *previous = NULL;

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

KoalaDoctorList *KoalaDoctorList::removeFromName(std::string string)
{
  KoalaDoctorList *current = this;
  KoalaDoctorList *previous = NULL;

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

void KoalaDoctorList::dump()
{
  KoalaDoctorList *current = this;

  std::cout << "Liste des docteurs : ";
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

KoalaDoctorList *KoalaDoctorList::getContent()
{
  if (this)
    return this;
  return NULL;
}

KoalaDoctorList *KoalaDoctorList::getNext()
{
  if (this->next)
    return this->next;
  return NULL;
}
