/*
** collide.c for ninja in /home/ungaro_l/perso/ludumdare
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Sat Dec 12 16:47:09 2015 Luca Ungaro
** Last update Sun Dec 13 21:08:28 2015 Luca Ungaro
*/

#include "ninja.h"

/*
** Du coup ca c'est crade
*/
t_bunny_response	check_collide(t_ninja	*ninja,
				      t_entity	*ent,
				      t_entity	*drop)
{
  t_bunny_response	collide;

  collide = GO_ON;
  check_for_obstacles(ninja, ent);
  check_for_drop(ninja, drop);
  if (ninja->life == -1)
    collide = EXIT_ON_SUCCESS;
  return (collide);
}

void	check_for_obstacles(t_ninja *ninja, t_entity *ent)
{
  while (ent)
    {
      if (coord_corresp(ninja->pos, ent->pos))
	{
	  ninja->life -= 1;
	  ent->pos.y += HEIGHT;
	}
      ent = ent->next;
    }
}

void	check_for_drop(t_ninja *ninja, t_entity *drop)
{
  while (drop)
    {
      if (coord_corresp(ninja->pos, drop->pos))
	{
	  ninja->life += (ninja->life < 4) ? 1 : 0;
	  drop->pos.y += HEIGHT;
	}
      drop = drop->next;
    }
}

int			coord_corresp(t_bunny_position	nin_p,
				      t_bunny_position	ent_p)
{
  int			ret;
  t_bunny_position	actual;

  ret = 0;
  actual.x = nin_p.x - DELTA_NINJA;
  actual.y = nin_p.y - DELTA_NINJA;
  if (((actual.x >= ent_p.x && actual.x <= ent_p.x + ENTITY_W) &&
       (actual.y >= ent_p.y && actual.y <= ent_p.y + ENTITY_H)) ||
      ((actual.x + NINJA_W>= ent_p.x && actual.x + NINJA_W <= ent_p.x + ENTITY_W) &&
       (actual.y >= ent_p.y && actual.y <= ent_p.y + ENTITY_H)) ||
      ((actual.x >= ent_p.x && actual.x <= ent_p.x + ENTITY_W) &&
       (actual.y + NINJA_H >= ent_p.y && actual.y + NINJA_H <= ent_p.y + ENTITY_H)) ||
      ((actual.x + NINJA_W >= ent_p.x && actual.x + NINJA_W <= ent_p.x + ENTITY_W) &&
       (actual.y + NINJA_H >= ent_p.y && actual.y + NINJA_H <= ent_p.y + ENTITY_H)))
    ret = 1;
  return (ret);
}
