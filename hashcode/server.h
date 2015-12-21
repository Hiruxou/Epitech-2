/*
** server.h for hashcode in /home/audibe_l/rendu/hashcode
**
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
**
** Started on  Thu Mar 12 19:26:32 2015 Audibert Louis
** Last update Thu Mar 12 21:34:02 2015 Nicolas Charvoz
*/

#ifndef _SERVER_H_
# define _SERVER_H_

typedef struct s_serv {
  int size;
  int capacity;
  int x;
  int y;
  int group;
} t_serv;

class	Server
{
private:
  int	size;
  int	capacity;
  int	x;
  int	y;

public:
  Server(int size, int capacity, int x, int y);
  ~Server();
};

#endif /* _SERVER_H_ */
