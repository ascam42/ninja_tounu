/*
** main_event.c for  in /home/aitoua_s/ludumdare/srcs
** 
** Made by Samy Ait-ouakli
** Login   <aitoua_s@epitech.net>
** 
** Started on  Sat Dec 12 06:39:11 2015 Samy Ait-ouakli
** Last update Mon Dec 14 21:04:44 2015 Luca Ungaro
*/

#include "ninja.h"

t_bunny_picture	*gl_obstacle[2];
t_bunny_picture	*gl_drop;
t_bunny_picture	*gl_numbers[10];
int		gl_cooldown = 0;
int		gl_fall = 10;
unsigned int	gl_score = 0;

/*
** Ce main prend void parce qu'on est trop des rebels t'as vu
*/
int			main(void)
{
  t_bunny_window	*wind;
  t_dat			dat;
  t_bunny_music		*music;
  t_ninja		nin;
  t_map			map;

  wind = bunny_start(WIDTH, HEIGHT, 0, "NINJA TOUNU!");
  if (wind)
    {
      loading_screen(wind);
      music = init_music();
      nin = init_this_ninja();
      map = init_this_map();
      init_these_globals();
      if (!map.clip || !nin.clip || !gl_obstacle[0] || !gl_obstacle[1] ||
	  !gl_drop)
	exit(FILE_ERROR);
      dat.ninja = &nin;
      dat.map = &map;
      dat.win = wind;
      dat.music = music;
      startup_menu(wind);
      /* LET'S GO ! */
      bunny_set_key_response(keytest);
      bunny_set_loop_main_function(mainloop);
      if (bunny_loop(wind, FPS, &dat) != EXIT_ON_CROSS)
	score_screen(wind);
      freaking_frees(&nin, &map, music);
      bunny_stop(wind);
    }
  return (0);
}
