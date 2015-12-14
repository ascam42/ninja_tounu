/*
** frees.c for ninja in /home/ungaro_l/perso/ludumdare
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Sun Dec 13 18:05:52 2015 Luca Ungaro
** Last update Mon Dec 14 17:48:23 2015 Luca Ungaro
*/

#include "ninja.h"

void	freaking_frees(t_ninja *ninja, t_map *map, t_bunny_music *music)
{
  int	i;

  i = -1;
  while (++i < 20)
    bunny_delete_clipable(ninja->clip[i]);
  free(ninja->clip);
  bunny_delete_clipable(map->clip);
  free_list(map->ent);
  free_list(map->drop);
  bunny_delete_clipable(gl_obstacle[0]);
  bunny_delete_clipable(gl_obstacle[1]);
  bunny_delete_clipable(gl_drop);
  i = -1;
  while (++i < 10)
    bunny_delete_clipable(gl_numbers[i]);
  if (music)
    {
      bunny_sound_stop(music);
      bunny_delete_sound(music);
    }
}

void		free_list(t_entity *list)
{
  t_entity	*tmp;

  while (list)
    {
      tmp = list;
      list = list->next;
      free(tmp);
    }
}
