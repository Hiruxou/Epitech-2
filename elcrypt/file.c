/*
** file.c for  in /home/nicolaschr/rendu/elcrypt
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Sun Mar 15 10:47:45 2015 Nicolas Charvoz
** Last update Sun Mar 15 12:00:52 2015 Nicolas Charvoz
*/

#include "elcrypt.h"

FILE	*open_files(FILE *file, char *src, int *size)
{
  file = fopen(src, "rb");
  if (!file)
    printf("Impossible d'ouvrir les fichiers");
  if (fseek(file, 0L, SEEK_END) != 0)
    printf("Erreur lecture");
  *size = ftell(file);
  if (fseek(file, 0L, SEEK_SET) != 0)
    printf("Erreur lecture");
  return (file);
}

char		*read_file(t_opt *opt, FILE **filesrc)
{
  static FILE		*file = NULL;
  static char		buff[9];
  int			ret;
  int			size;

  size = 8;
  if (file == NULL)
    file = open_files(*filesrc, opt->src, &size);
  buff[8] = '\0';
  *filesrc = file;
  ret = fread(buff, sizeof(char), 8, file);
  opt->current_byte += ret;
  if (ret < 0)
    printf("Erreur de lecture");
  else if (ret == 0)
    return (NULL);
  return (&buff[0]);
}

void		init(t_opt *opt)
{
  FILE		*filedest;
  FILE		*filesrc;
  int		writeSize;
  char		*cipher_ans;
  char		*read;

  filesrc = NULL;
  filedest = fopen(opt->dest, "wc");
  while (1)
    {
      if ((read = read_file(opt, &filesrc)) == NULL)
	break;
      cipher_ans = my_encrypt(opt->first32, read);
      writeSize = fwrite(cipher_ans, 1, 8, filedest);
      if (writeSize != 8)
	printf("Erreur d'écriture");
    }
  fclose(filedest);
  fclose(filesrc);
  puts("Opération effectué avec succès !");
}
