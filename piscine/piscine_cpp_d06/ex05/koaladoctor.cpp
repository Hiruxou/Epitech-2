//
// koaladoctor.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d06/ex04
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Mon Jan 12 15:22:22 2015 Nicolas Charvoz
// Last update Tue Jan 13 00:30:05 2015 Nicolas Charvoz
//

#include "koaladoctor.h"

KoalaDoctor::KoalaDoctor(std::string name)
{
  this->name = name;
  std::cout << "Dr."<<this->name <<": Je suis le Dr."
    << this->name <<" ! Comment Kreoggez-vous ?"<<std::endl;
}

KoalaDoctor::~KoalaDoctor(){}

void KoalaDoctor::timeCheck()
{
  static bool check = false;

  if (check == false)
    {
      std::cout << "Dr."<< this->name <<": Je commence le travail\
 !"<<std::endl;
      check = true;
    }
  else if (check == true)
    {
      std::cout << "Dr."<< this->name <<": Je rentre dans ma foret \
d’eucalyptus !"<<std::endl;
      check = false;
    }
}

void KoalaDoctor::diagnose(SickKoala *patient)
{
  std::ofstream file;
  std::string fileName;
  std::string drugName;

  std::string drugs[] = {"mars", "Buronzand", "Viagra", "Extasy", "Feuille d'eucalyptus"};
  std::cout << "Dr."<< this->name
	    <<": Alors qu’est-ce qui vous goerk Mr."
	    << patient->getName() <<" ?" <<std::endl;

  patient->poke();
  fileName = patient->getName() + ".report";
  file.open(fileName.c_str());
  if (file.is_open())
    file << drugs[random() % 5];
}

std::string KoalaDoctor::getName()
{
  return this->name;
}
