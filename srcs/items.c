/*
** items.c for ninja in /home/ungaro_l/perso/ludumdare
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Sun Dec 13 18:42:06 2015 Luca Ungaro
** Last update Mon Dec 14 19:03:59 2015 Luca Ungaro
*/

#include "ninja.h"

void	set_obstacles_n_drop(t_dat	*dat)
{
  int	density;
  int	lim_r;
  int	lim_l;

  density = (dat->ninja->life > 2) ? 50 : 20;
  lim_r = R_LIMIT - (gl_obstacle[0]->clip_width * gl_obstacle[0]->scale.x);
  lim_l = L_LIMIT;
  if (dat->ninja->life == 4)
    dat->map->drop_on = 0;
  if (dat->ninja->dep == NOT_MOVING)
    gl_cooldown += 1;
  if (gl_cooldown >= 2 * FPS)
    {
      if (dat->ninja->pos.x == R_LIMIT - DELTA_NINJA)
	lim_l = lim_r + 1;
      else
	lim_r = lim_l + 1;
      density = 50;
      dat->map->drop_on = 0;
    }
  ent_randomize(dat->map, density, lim_l, lim_r);
  show_obstacles(dat);
  show_drop(dat);
}

void	show_obstacles(t_dat	*dat)
{
  t_entity	*ent;
  t_entity	*tmp;

  ent = dat->map->ent;
  while (ent != NULL)
    {
      ent->pos.y += gl_fall;
      bunny_blit(&dat->win->buffer, ent->clip, &ent->pos);
      if (ent->next && ent->next->pos.y > HEIGHT)
	{
	  tmp = ent->next;
	  ent->next = tmp->next;
	  free(tmp);
	}
      ent = ent->next;
    }
}

void	show_drop(t_dat	*dat)
{
  t_entity	*drop;
  t_entity	*tmp;

  drop = dat->map->drop;
  while (drop != NULL)
    {
      drop->pos.y += gl_fall;
      bunny_blit(&dat->win->buffer, drop->clip, &drop->pos);
      if (drop->next && drop->next->pos.y > HEIGHT)
	{
	  tmp = drop->next;
	  drop->next = tmp->next;
	  free(tmp);
	}
      drop = drop->next;
    }
}
