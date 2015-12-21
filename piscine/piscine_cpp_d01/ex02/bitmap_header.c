/*
** bitmap_header.c for  in /home/charvo_a/rendu/piscine_cpp_d01/ex02
** 
** Made by Charvoz Nicolas
** Login   <charvo_a@epitech.net>
** 
** Started on  Wed Jan  7 13:26:37 2015 Charvoz Nicolas
** Last update Wed Jan  7 21:45:26 2015 Charvoz Nicolas
*/

#include "bitmap.h"
#include <byteswap.h>

void	make_bmp_header(t_bmp_header *header, size_t size)
{
  int n = 1;
  if (*(char*) & n == 1) 
    header->magic = 0x4D42;
  else 
    header->magic = 0x424D;
  header->size = size * size * sizeof(int) + sizeof(t_bmp_header) + sizeof(t_bmp_info_header);
  header->_app1 = 0;
  header->_app2 = 0;
  header->offset = sizeof(t_bmp_header) + sizeof(t_bmp_info_header);
}

void	make_bmp_info_header(t_bmp_info_header *header, size_t size)
{
  header->size = 40;
  header->width = size;
  header->height = size;
  header->planes = 1;
  header->bpp = 32;
  header->compression = 0;
  header->raw_data_size = size * size *4;
  header->h_resolution = 0;
  header->v_resolution = 0;
  header->palette_size = 0;
  header->important_colors = 0;
}
