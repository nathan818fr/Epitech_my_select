##
## Makefile for my_select in /home/poirie-n/blinux/poirie_n/repo/B1/Syst_Unix/PSU_2014_my_select
## 
## Made by Nathan Poirier
## Login   <poirie-n@epitech.net>
## 
## Started on  Mon Jan  5 12:26:21 2015 Nathan Poirier
## Last update Sun Jan 11 17:18:27 2015 Nathan Poirier
##

SRCS		= main.c		\
		  utils.c		\
		  options.c		\
		  help.c		\
		  loader.c		\
		  elems.c		\
		  term.c		\
		  term_info.c		\
		  draw.c		\
		  print.c		\
		  loop.c		\
		  loop_additional.c	\
		  search.c

OBJS		= $(addprefix src/, $(SRCS:.c=.o))

PROJECT		= PSU_2014_my_select

NAME		= my_select

RM		= rm -f

CC		= gcc

LIBS		= -Ilib/C_Lib_MyUtils/include -Llib/C_Lib_MyUtils -lmyutils
LIBS		+= -lncurses -Llib/

CFLAGS		= -W -Wall -Wextra -Werror
CFLAGS		+= -Wno-variadic-macros -Wno-unused-parameter
CFLAGS		+= -ansi -pedantic
CFLAGS		+= -Ofast
CFLAGS		+= -Iinclude/
CFLAGS		+= $(LIBS)

LDFLAGS		= $(LIBS)

LIB_MYUTILS	= lib/C_Lib_MyUtils/libmyutils.a
LIB_MYUTILS_MK	= make -C lib/C_Lib_MyUtils/

$(PROJECT):	$(LIB_MYUTILS) $(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

$(LIB_MYUTILS):
		$(LIB_MYUTILS_MK)

all:		$(PROJECT)

clean:
		$(RM) $(OBJS)
		$(LIB_MYUTILS_MK) clean

fclean:		clean
		$(RM) $(NAME)
		$(LIB_MYUTILS_MK) fclean

re:		fclean all

.PHONY: re fclean clean all $(PROJECT)
