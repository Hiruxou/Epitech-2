/*
** datacenter.h for hashcode in /home/audibe_l/rendu/hashcode
**
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
**
** Started on  Thu Mar 12 19:18:09 2015 Audibert Louis
** Last update Thu Mar 12 20:59:29 2015 Nicolas Charvoz
*/

#ifndef _DATACENTER_H_
# define _DATACENTER_H_

# include <vector>
# include <string>

class	DataCenter
{
private:
  char **_map;
  int	_sizeX;
  int	_sizeY;
  int	_nbUnavailable;
  int	_nbGroups;
  int	_nbServ;

public:
  DataCenter(int, int, int ,int, int);
  ~DataCenter();
  DataCenter *getDataCenter();

  int	getSizeX() const;
  int	getSizeY() const;
  int	getNbU() const;
  int	getNbGroups() const;
  int	getNbServ() const;

  void	setSizeX(int);
  void	setSizeY(int);
  void	setNbUnavailable(int);
  void	setNbGroups(int);
  void	setNbServ(int);
};

#endif /* _DATACENTER_H_ */
