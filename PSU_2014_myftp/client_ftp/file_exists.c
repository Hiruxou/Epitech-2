/*
** file_exists.c for  in /home/nicolaschr/rendu/PSU_2014_myftp/client_ftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Tue Mar 17 13:19:53 2015 Nicolas Charvoz
** Last update Tue Mar 17 13:20:43 2015 Nicolas Charvoz
*/

#include "client.h"

int	file_exists(char *file)
{
  if (access(file, F_OK | R_OK) != -1)
    return (0);
  else
    return (-1);
}
