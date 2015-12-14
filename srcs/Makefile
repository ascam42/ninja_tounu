##
## Makefile for ninja in /home/ungaro_l/perso/ludumdare
## 
## Made by Luca Ungaro
## Login   <ungaro_l@epitech.net>
## 
## Started on  Sat Dec 12 05:07:41 2015 Luca Ungaro
## Last update Mon Dec 14 17:41:21 2015 Luca Ungaro
##

NAME		= ninja

CC		= gcc

RM		= rm -f

override CFLAGS	+= -W -Wall -Wextra -Werror -ansi -pedantic
override CFLAGS	+= -Iinclude

SRCS		= main_event.c \
		inits.c \
		gameloop.c \
		items.c  \
		randomize.c \
		key.c \
		collide.c \
		colorize.c \
		score.c \
		frees.c

OBJS		= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LDFLAGS)

relink:
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all relink clean fclean re
