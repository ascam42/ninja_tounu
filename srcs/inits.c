/*
** inits.c for epr,c in /home/ungaro_l/perso/ludumdare
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Sat Dec 12 08:01:39 2015 Luca Ungaro
** Last update Mon Dec 14 18:14:45 2015 Luca Ungaro
*/

#include "ninja.h"

void	init_these_globals(void)
{
  int	i;

  gl_obstacle[0] = bunny_load_picture("misc/flower2.png"); /* WTF WITH THIS ? */
  if (gl_obstacle[0])
    {
      gl_obstacle[0]->scale.x = 0.5;
      gl_obstacle[0]->scale.y = 0.5;
    }
  gl_obstacle[1] = bunny_load_picture("misc/plant2.png");
  if (gl_obstacle[1])
    {
      gl_obstacle[1]->scale.x = 0.5;
      gl_obstacle[1]->scale.y = 0.5;
    }
  gl_drop = bunny_load_picture("misc/colis.png");
  gl_numbers[0] = bunny_load_picture("misc/0.png");
  gl_numbers[1] = bunny_load_picture("misc/1.png");
  gl_numbers[2] = bunny_load_picture("misc/2.png");
  gl_numbers[3] = bunny_load_picture("misc/3.png");
  gl_numbers[4] = bunny_load_picture("misc/4.png");
  gl_numbers[5] = bunny_load_picture("misc/5.png");
  gl_numbers[6] = bunny_load_picture("misc/6.png");
  gl_numbers[7] = bunny_load_picture("misc/7.png");
  gl_numbers[8] = bunny_load_picture("misc/8.png");
  gl_numbers[9] = bunny_load_picture("misc/9.png");
  i = -1;
  while (++i < 10)
    {
      gl_numbers[i]->scale.x = 2;
      gl_numbers[i]->scale.y = 2;
    }
}

t_ninja		init_this_ninja(void)
{
  t_ninja	nin;
  int		i;

  i = -1;
  nin.pos.x = R_LIMIT - DELTA_NINJA;
  nin.pos.y = 750;
  nin.clip = malloc(sizeof(t_bunny_clipable *) * 20);
  if (nin.clip)
    {
      /*
      ** [0;4] : Right
      ** [5;9] : Left
      ** [10;14] : Jumping Right
      ** [14;19] : Jumping Left
      */
      nin.clip[0] = bunny_load_picture("misc/ninja/Ninja-NudeRight.png");
      nin.clip[1] = bunny_load_picture("misc/ninja/Ninja-BandanaRight.png");
      nin.clip[2] = bunny_load_picture("misc/ninja/Ninja-CagouleRight.png");
      nin.clip[3] = bunny_load_picture("misc/ninja/Ninja-HautRight.png");
      nin.clip[4] = bunny_load_picture("misc/ninja/Ninja-FullRight.png");
      nin.clip[5] = bunny_load_picture("misc/ninja/Ninja-NudeLeft.png");
      nin.clip[6] = bunny_load_picture("misc/ninja/Ninja-BandanaLeft.png");
      nin.clip[7] = bunny_load_picture("misc/ninja/Ninja-CagouleLeft.png");
      nin.clip[8] = bunny_load_picture("misc/ninja/Ninja-HautLeft.png");
      nin.clip[9] = bunny_load_picture("misc/ninja/Ninja-FullLeft.png");
      nin.clip[10] = bunny_load_picture("misc/ninja/Ninja-AirNudeRight.png");
      nin.clip[11] = bunny_load_picture("misc/ninja/Ninja-AirBandanaRight.png");
      nin.clip[12] = bunny_load_picture("misc/ninja/Ninja-AirCagouleRight.png");
      nin.clip[13] = bunny_load_picture("misc/ninja/Ninja-AirHautRight.png");
      nin.clip[14] = bunny_load_picture("misc/ninja/Ninja-AirFullRight.png");
      nin.clip[15] = bunny_load_picture("misc/ninja/Ninja-AirNudeLeft.png");
      nin.clip[16] = bunny_load_picture("misc/ninja/Ninja-AirBandanaLeft.png");
      nin.clip[17] = bunny_load_picture("misc/ninja/Ninja-AirCagouleLeft.png");
      nin.clip[18] = bunny_load_picture("misc/ninja/Ninja-AirHautLeft.png");
      nin.clip[19] = bunny_load_picture("misc/ninja/Ninja-AirFullLeft.png");
      while (++i < 20)
	{
	  nin.clip[i]->scale.x = 1.0 / 12.0;
	  nin.clip[i]->scale.y = 1.0 / 12.0;
	  nin.clip[i]->origin.x = (int)(0.5 * nin.clip[i]->clip_width);
	  nin.clip[i]->origin.y = (int)(0.5 * nin.clip[i]->clip_height);
	}
      nin.dep = NOT_MOVING;
      nin.dir = TO_RIGHT;
      nin.life = 2;
    }
  return (nin);
}

t_map		init_this_map(void)
{
  t_map		map;

  map.pos.x = 0;
  map.pos.y = 0;
  map.clip = bunny_load_picture("misc/fond.png");
  map.ent = NULL;
  map.drop = NULL;
  map.drop_on = 1;
  return (map);
}

void			startup_menu(t_bunny_window	*wind)
{
  t_bunny_clipable	*menu;

  menu = bunny_load_picture("misc/menu.png");
  if (menu)
    {
      bunny_blit(&wind->buffer, menu, NULL);
      bunny_display(wind);
      bunny_set_key_response(keymenu);
      bunny_loop(wind, 25, NULL);
    }
}

void	loading_screen(t_bunny_window *win)
{
  t_bunny_clipable	*loading;

  loading = bunny_load_picture("misc/loading.jpeg");
  if (loading)
    {
      loading->scale.x = 1.25;
      loading->scale.y = 1.25;
      bunny_blit(&win->buffer, loading, NULL);
      bunny_display(win);
    }
}

t_bunny_music		*init_music(void)
{
  t_bunny_music	*epic_sound;

  epic_sound = bunny_load_music("misc/music.ogg");
  bunny_sound_loop(epic_sound, true);
  bunny_sound_play(epic_sound);
  return (epic_sound);
}
