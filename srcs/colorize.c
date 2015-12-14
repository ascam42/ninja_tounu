/*
** colorize.c for nenene in /home/ungaro_l/perso/ludumdare
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Sat Dec 12 05:43:19 2015 Luca Ungaro
** Last update Sat Dec 12 15:05:01 2015 Luca Ungaro
*/

#include "ninja.h"

void	colorize(t_bunny_pixelarray	*pix,
		 unsigned int		col)
{
  int	i;

  i = 0;
  while (i < pix->clipable.clip_width * pix->clipable.clip_height)
    ((unsigned int*)(pix)->pixels)[i++] = col;
}
