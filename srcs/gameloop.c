/*
** gameloop.c for ninjaaaaaah in /home/ungaro_l/perso/ludumdare
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Sat Dec 12 05:03:08 2015 Luca Ungaro
** Last update Mon Dec 14 12:59:30 2015 Luca Ungaro
*/

#include "ninja.h"

t_bunny_response	mainloop(void	*data)
{
  t_bunny_response	ret;
  t_dat			*dat;
  t_bunny_clipable	*tmp;

  dat = (t_dat*)data;
  move_this_naked_ninja(dat);
  tmp = where_is_this_ninja(dat->ninja);
  bunny_blit(&dat->win->buffer, dat->map->clip, &dat->map->pos);
  set_obstacles_n_drop(dat);
  bunny_blit(&dat->win->buffer, tmp, &dat->ninja->pos);
  bunny_display(dat->win);
  dat->map->pos.y = dat->map->pos.y >= 0 ? -400 : dat->map->pos.y + gl_fall;
  ret = check_collide(dat->ninja, dat->map->ent, dat->map->drop);
  gl_score += gl_fall;
  return (ret);
}

t_bunny_clipable	*where_is_this_ninja(t_ninja	*ninja)
{
  t_bunny_clipable	*ret;

  ret = ninja->clip[ninja->life + ninja->dir];
  if (ninja->dir >= FLYING)
    ret->rotation = ninja->pos.x;
  else
    ret->rotation = 0.0;
  return (ret);
}

void	move_this_naked_ninja(t_dat	*dat)
{
  gl_fall = 10 * ((dat->ninja->life / 3 ) + 1);
  if (dat->ninja->dep == GO_LEFT)
    dat->ninja->pos.x -= 10 * (dat->ninja->life + 2);
  else if (dat->ninja->dep == GO_RIGHT)
    dat->ninja->pos.x += 10 * (dat->ninja->life + 2);
  if (dat->ninja->pos.x >= R_LIMIT - DELTA_NINJA)
    {
      dat->ninja->pos.x = R_LIMIT - DELTA_NINJA;
      dat->ninja->dep = NOT_MOVING;
      dat->ninja->dir -= (dat->ninja->dir >= FLYING) ? FLYING : 0;
    }
  else if (dat->ninja->pos.x <= L_LIMIT + DELTA_NINJA)
    {
      dat->ninja->pos.x = L_LIMIT + DELTA_NINJA;
      dat->ninja->dep = NOT_MOVING;
      dat->ninja->dir -= (dat->ninja->dir >= FLYING) ? FLYING : 0;
    }
}
