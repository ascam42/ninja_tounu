/*
** key.c for nenene in /home/ungaro_l/perso/ludumdare
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Sat Dec 12 05:41:08 2015 Luca Ungaro
** Last update Mon Dec 14 17:32:02 2015 Luca Ungaro
*/

#include "ninja.h"

t_bunny_response	keytest(t_bunny_event_state	state,
				t_bunny_keysym		keysym,
				void			*data)
{
  t_bunny_response	res;

  res = GO_ON;
  if (keysym == BKS_LEFT && state == GO_DOWN)
    {
      ((t_dat *)data)->ninja->dep = GO_LEFT;
      ((t_dat *)data)->ninja->dir = TO_LEFT + FLYING;
      gl_cooldown = 0;
    }
  else if (keysym == BKS_RIGHT && state == GO_DOWN)
    {
      ((t_dat *)data)->ninja->dep = GO_RIGHT;
      ((t_dat *)data)->ninja->dir = TO_RIGHT + FLYING;
      gl_cooldown = 0;
    }
  else if (keysym == BKS_ESCAPE && state == GO_DOWN)
    {
      bunny_set_key_response(keypause);
      bunny_set_loop_main_function(pauseloop);
      res = bunny_loop(((t_dat *)data)->win, FPS, data);
      res = (res == EXIT_ON_CROSS) ? GO_ON : res;
    }
  return (res);
}

t_bunny_response	keypause(t_bunny_event_state	state,
				  t_bunny_keysym	keysym,
				  void			*data)
{
  t_bunny_response	res;

  res = GO_ON;
  if ((keysym == BKS_LEFT && state == GO_DOWN) ||
      (keysym == BKS_ESCAPE && state == GO_DOWN))
    res = EXIT_ON_SUCCESS;
  else if (keysym == BKS_RIGHT && state == GO_DOWN)
    {
      res = EXIT_ON_CROSS;
      bunny_set_key_response(keytest);
      bunny_set_loop_main_function(mainloop);
    }
  (void)data;
  return (res);
}

t_bunny_response	pauseloop(void *data)
{
  t_bunny_picture	*frame;

  frame = bunny_load_picture("misc/pause.png");
  bunny_blit(&((t_dat *)data)->win->buffer, frame, NULL);
  bunny_display(((t_dat *)data)->win);
  return (GO_ON);
}

t_bunny_response	keymenu(t_bunny_event_state	state,
				t_bunny_keysym		keysym,
				void			*data)
{
  t_bunny_response	ret;

  ret = GO_ON;
  if (state == GO_DOWN)
    ret = EXIT_ON_SUCCESS;
  (void)keysym;
  (void)data;
  return (ret);
}
