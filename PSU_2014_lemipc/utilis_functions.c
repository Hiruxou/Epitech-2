/*
** utilis_functions.c for utilis_function in /home/garcia_t/rendu/PSU_2014_lemipc
** 
** Made by antoine garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Thu Mar  5 12:54:10 2015 antoine garcia
** Last update Sun Mar  8 13:58:09 2015 antoine garcia
*/

#include "lemipc.h"

void	unlock_sem(int semid)
{
  struct sembuf sops;

  sops.sem_op = 1;
  semop(semid, &sops, 1);
}

void	lock_sem(int semid)
{
  struct sembuf sops;

  sops.sem_op = -1;
  semop(semid, &sops, 1);
}
