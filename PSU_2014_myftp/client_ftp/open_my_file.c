/*
** open_my_file.c for  in /home/nicolaschr/rendu/PSU_2014_myftp/client_ftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Sat Mar 21 18:40:36 2015 Nicolas Charvoz
** Last update Sun Mar 22 11:05:16 2015 Nicolas Charvoz
*/

#include "client.h"

FILE	*open_my_file(char *file, int *size)
{
  FILE	*oFile;

  oFile = fopen(file, "rb");
  if (!oFile)
    printf("Impossible d'ouvrir le fichier\n");
  if (fseek(oFile, 0L, SEEK_END) != 0)
    printf("Erreur de lecture du fichier\n");
  *size = ftell(oFile);
  if (fseek(oFile, 0L, SEEK_SET) != 0)
    printf("Erreur de lecture du fichier\n");
  return (oFile);
}
