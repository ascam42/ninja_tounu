/*
** randomize.c for  in /home/aitoua_s/ludumdare/srcs
** 
** Made by Samy Ait-ouakli
** Login   <aitoua_s@epitech.net>
** 
** Started on  Sat Dec 12 09:32:41 2015 Samy Ait-ouakli
** Last update Mon Dec 14 18:44:14 2015 Luca Ungaro
*/

#include "ninja.h"

void		add_ent(t_map *map, int lim_l, int lim_r)
{
  t_entity	*new;
  t_entity	*last;

  new = malloc(sizeof(t_entity));
  if (new)
    {
      if (gl_obstacle[0] && gl_obstacle[1])
	new->clip = gl_obstacle[rand() % 2];
      new->pos.y = 0;
      new->pos.x = lim_l + rand() % (lim_r - lim_l);
      new->type = 0;
      new->clip->scale.x = 3;
      new->clip->scale.y = 3;
      last = map->ent;
      new->next = NULL;
      if (map->ent == NULL)
	map->ent = new;
      else
	{
	  while (last->next != NULL)
	    last = last->next;
	  last->next = new;
	}
    }
}

void		add_drop(t_map *map, int lim_l, int lim_r)
{
  t_entity	*new;
  t_entity	*last;

  new = malloc(sizeof(t_entity));
  if (new)
    {
      if (gl_drop)
	new->clip = gl_drop;
      new->pos.y = 0;
      new->pos.x = lim_l + rand() % (lim_r - lim_l);
      new->type = 0;
      new->clip->scale.x = 1.5;
      new->clip->scale.y = 1.5;
      last = map->drop;
      new->next = NULL;
      if (map->drop == NULL)
	map->drop = new;
      else
	{
	  while (last->next != NULL)
	    last = last->next;
	  last->next = new;
	}
    }
}

void	ent_randomize(t_map *map, int density,int lim_l, int lim_r)
{
  int	i;
  int	j;

  i = density / 100;
  j = density / 100;
  if (rand() % 1000 < density % 100)
    i++;
  if (rand() % 5000 < density % 100)
    j++;
  while (i-- > 0)
    add_ent(map, lim_l, lim_r);
  while (map->drop_on && j-- > 0)
    add_drop(map, lim_l, lim_r);
  map->drop_on = 1;
}
