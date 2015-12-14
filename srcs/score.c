/*
** score.c for ninja in /home/ungaro_l/perso/ludumdare
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Mon Dec 14 17:18:51 2015 Luca Ungaro
** Last update Mon Dec 14 21:04:27 2015 Luca Ungaro
*/

#include "ninja.h"

void			score_screen(t_bunny_window	*wind)
{
  t_bunny_picture	*back;

  back = bunny_load_picture("misc/gameover.png");
  bunny_blit(&wind->buffer, back, NULL);
  bunny_display(wind);
  bunny_set_key_response(keymenu);
  bunny_set_loop_main_function(scoreloop);
  bunny_loop(wind, FPS, wind);
}

t_bunny_response	scoreloop(void		*data)
{
  int			i;
  int			tmp;
  t_bunny_picture	*frame;

  frame = bunny_load_picture("misc/gameover.png");
  bunny_blit(&((t_bunny_window *)data)->buffer, frame, NULL);
  i = 1;
  tmp = gl_score;
  while (tmp >= 10)
    {
      tmp /= 10;
      i += 1;
    }
  putscore((t_bunny_window *)data, gl_score, i, 0);
  bunny_display(((t_bunny_window *)data));
  sleep(1);
  return (GO_ON);
}

void			putscore(t_bunny_window	*win,
				 int		score,
				 int		score_size,
				 int		pos_nb)
{
  int			actual_width;
  t_bunny_position	pos;

  actual_width = gl_numbers[0]->clip_width * gl_numbers[0]->scale.x;
  if (score > 9)
    putscore(win, score / 10, score_size, pos_nb + 1);
  pos.y = 500;
  pos.x = ((win->buffer.width / 2) - (((score_size + 0.5) * actual_width) / 2)) +
    ((score_size - pos_nb - 1) * actual_width) +
    (0.5 * gl_numbers[0]->clip_width);
  bunny_blit(&win->buffer, gl_numbers[score % 10], &pos);
}
