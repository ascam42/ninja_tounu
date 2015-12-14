/*
** header.h for  in /home/aitoua_s/ludumtest
** 
** Made by Samy Ait-ouakli
** Login   <aitoua_s@epitech.net>
** 
** Started on  Sat Dec 12 04:04:12 2015 Samy Ait-ouakli
** Last update Mon Dec 14 17:47:35 2015 Luca Ungaro
*/

#ifndef NINSHREDDER
# define NINSHREDDER

# include <unistd.h>
# include <stdio.h>
# include <time.h>
# include <lapin.h>

# define WIDTH	1000
# define HEIGHT	1000
# define FPS	60

# define L_LIMIT	(WIDTH / 10)
# define R_LIMIT	(WIDTH - (WIDTH / 10))
# define DELTA_NINJA	28

# define NINJA_W	50
# define NINJA_H	50
# define ENTITY_W	140
# define ENTITY_H	140

/*
** Error codes
*/
# define MENU_ERROR	1
# define FILE_ERROR	2

typedef enum		e_dep
  {
    GO_RIGHT = -1,
    NOT_MOVING,
    GO_LEFT
  }			t_dep;

typedef enum		e_dir
  {
    TO_RIGHT = 0,
    TO_LEFT = 5,
    FLYING = 10
  }			t_dir;

typedef struct		s_entity
{
  t_bunny_clipable	*clip;
  t_bunny_position	pos;
  int			type;
  struct s_entity	*next;
}			t_entity;

typedef struct		s_ninja
{
  int			life;
  t_bunny_clipable	**clip;
  t_bunny_position	pos;
  t_dep			dep;
  t_dir			dir;
}			t_ninja;

typedef struct		s_map
{
  t_bunny_position	pos;
  t_bunny_clipable	*clip;
  t_entity		*ent;
  t_entity		*drop;
  int			drop_on;
}			t_map;

/*
** (void *) passed to bunny_loop
*/
typedef struct		s_dat
{
  t_bunny_window	*win;
  t_ninja		*ninja;
  t_map			*map;
  t_bunny_music		*music;
}			t_dat;


/*
** Obstacle clipable global definition (FOR SPEED !)
*/
extern t_bunny_clipable	*gl_obstacle[2];
extern t_bunny_picture	*gl_drop;
extern t_bunny_picture	*gl_numbers[10];
extern int		gl_cooldown;
extern int		gl_fall;
extern unsigned int	gl_score; /* Long ? Long long ? */

/*
** inits.c
*/
void			init_these_globals(void);
t_ninja			init_this_ninja(void);
t_map			init_this_map(void);
void			startup_menu(t_bunny_window	*wind);
void			loading_screen(t_bunny_window	*win);
t_bunny_music		*init_music(void);
/*
** gameloop.c
*/
t_bunny_response	mainloop(void			*data);
void			set_drop(t_dat			*dat);
void			move_this_naked_ninja(t_dat	*dat);
t_bunny_clipable	*where_is_this_ninja(t_ninja	*ninja);
/*
** items.c
*/
void			set_obstacles_n_drop(t_dat	*dat);
void			show_obstacles(t_dat		*dat);
void			show_drop(t_dat			*dat);
/*
** collide.c
*/
t_bunny_response	check_collide(t_ninja		*ninja,
				      t_entity		*ent,
				      t_entity		*drop);
void			check_for_obstacles(t_ninja	*ninja,
					    t_entity	*ent);
void			check_for_drop(t_ninja		*ninja,
				       t_entity		*ent);
int			coord_corresp(t_bunny_position	nin_p,
				      t_bunny_position	ent_p);
/*
** key.c
*/
t_bunny_response	keytest(t_bunny_event_state	state,
				t_bunny_keysym		keysym,
				void			*data);
t_bunny_response	keypause(t_bunny_event_state	state,
				  t_bunny_keysym	keysym,
				 void			*data);
t_bunny_response	pauseloop(void			*data);
t_bunny_response	scoreloop(void			*data);
t_bunny_response	keymenu(t_bunny_event_state	state,
				t_bunny_keysym		keysym,
				void			*data);
/*
** colorize.c
*/
void			colorize(t_bunny_pixelarray	*pix,
				 unsigned int		col);
/*
** randomize.c
*/
void			ent_randomize(t_map		*map,
				      int		density,
				      int		lim_l,
				      int		lim_r);
void			add_drop(t_map			*map,
				 int			lim_l,
				 int			lim_r);
void			add_ent(t_map			*map,
				int			lim_l,
				int			lim_r);
/*
** score.c
*/
void			score_screen(t_bunny_window	*wind);
t_bunny_response	scoreloop(void			*data);
void			putscore(t_bunny_window		*win,
				 int			score,
				 int			score_size,
				 int			pos);
/*
** frees.c
*/
void			freaking_frees(t_ninja		*ninja,
				       t_map		*map,
				       t_bunny_music	*music);
void			free_list(t_entity		*list);

#endif /* !NINSHREDDER */
