//
// koalanurse.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d06/ex03
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Mon Jan 12 13:51:32 2015 Nicolas Charvoz
// Last update Mon Jan 12 16:49:50 2015 Nicolas Charvoz
//

#include "koalanurse.h"
#include <fstream>

KoalaNurse::KoalaNurse(int id)
{
  this->id = id;
}

KoalaNurse::~KoalaNurse()
{
  std::cout << "Nurse "<< this->id <<": Enfin un peu de repos !" << std::endl;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *patient)
{
  patient->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string fileName)
{
  std::string line;
  std::string drugName;
  std::ifstream file;
  std::string patientName;

  if (fileName.substr(fileName.find_last_of(".") + 1) == "report")
    {
      patientName = fileName.substr(0, fileName.find("."));
      file.open(fileName.c_str());
      if (file.is_open())
	{
	  getline(file, drugName);
	  std::cout << "Nurse " << this->id <<": Kreog ! Il faut donner un "
		    << drugName <<" a Mr." << patientName << " !" << std::endl;
	  return drugName;
	}
    }
  return "";
}

void KoalaNurse::timeCheck()
{
  static bool check = false;

  if (check == false)
    {
      std::cout << "Nurse "<< this->id <<": Je commence le travail !"<<std::endl;
      check = true;
    }
  else if (check == true)
    {
    std::cout << "Nurse "<< this->id <<": Je rentre dans ma foret d'eucalyptus !"<<std::endl;
    check = false;
    }
}
