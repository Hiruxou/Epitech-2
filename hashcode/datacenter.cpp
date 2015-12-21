//
// datacenter.cpp for hashcode in /home/audibe_l/rendu/hashcode
//
// Made by Audibert Louis
// Login   <audibe_l@epitech.net>
//
// Started on  Thu Mar 12 19:29:58 2015 Audibert Louis
// Last update Thu Mar 12 20:59:37 2015 Nicolas Charvoz
//

#include "datacenter.h"

DataCenter::DataCenter(int sizeY, int sizeX, int nbUnavailable, int nbGroups, int nbServ)
{
  this->_sizeX = sizeX;
  this->_sizeY = sizeY;
  this->_nbUnavailable = nbUnavailable;
  this->_nbGroups = nbGroups;
  this->_nbServ = nbServ;
}

DataCenter::~DataCenter()
{

}

DataCenter *DataCenter::getDataCenter()
{
  return this;
}

int	DataCenter::getSizeX() const
{
  return _sizeX;
}

int	DataCenter::getSizeY() const
{
  return _sizeY;
}

int	DataCenter::getNbU() const
{
  return _nbUnavailable;
}

int	DataCenter::getNbGroups() const
{
  return _nbGroups;
}

int	DataCenter::getNbServ() const
{
  return _nbServ;
}

void	DataCenter::setSizeX(int x)
{
  _sizeX = x;
}

void	DataCenter::setSizeY(int y)
{
  _sizeY = y;
}

void	DataCenter::setNbUnavailable(int nb)
{
  _nbUnavailable = nb;
}

void	DataCenter::setNbGroups(int nb)
{
  _nbGroups = nb;
}

void	DataCenter::setNbServ(int nb)
{
  _nbServ = nb;
}
