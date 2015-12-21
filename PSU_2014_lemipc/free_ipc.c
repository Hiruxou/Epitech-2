/*
** free_ipc.c for  in /home/nicolaschr/rendu/PSU_2014_lemipc
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Sat Mar  7 14:30:01 2015 Nicolas Charvoz
** Last update Sat Mar  7 20:51:33 2015 Nicolas Charvoz
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "lemipc.h"

int	raise_error(char *binary, int return_value)
{
  perror(binary);
  return (return_value);
}

int	free_ipcs(t_lemipc *lemipc)
{
  if (msgctl(lemipc->game->msg_id, IPC_RMID, NULL) < 0)
    return (raise_error("msgclt", -1));
  if (semctl(lemipc->game->sem_id, 0, IPC_RMID) < 0)
    return (raise_error("semclt", -1));
  if (shmctl(lemipc->shmid, IPC_RMID, NULL) < 0)
    return (raise_error("shmclt", -1));
  if (shmdt(lemipc->game) == -1)
    return (raise_error("shmdt", -1));
  return (0);
}
