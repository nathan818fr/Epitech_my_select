/*
** my_select.h for my_select in /home/poirie-n/blinux/poirie_n/repo/B1/Syst_Unix/PSU_2014_my_select
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Mon Jan  5 12:36:01 2015 Nathan Poirier
** Last update Sun Jan 11 15:15:06 2015 Nathan Poirier
*/

#ifndef MY_SELECT_H_
# define MY_SELECT_H_

# include <errno.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <sys/time.h>
# include "myutils.h"
# include "myutils_list.h"
# include "myutils_log.h"
# include "myutils_printf.h"
# include "myutils_strerror.h"

# define BASH_BG_RED "\033[101m"
# define BASH_BG_RESET "\033[0m"
# define ASCII_ETX 3
# define ASCII_EOT 4
# define ASCII_NL 10
# define ASCII_ESC 27
# define ASCII_SPACE 32
# define ASCII_BACKSPACE 127
# define TC_CLEAR "cl"
# define TC_UNDERLINE "us"
# define TC_REVERSE "mr"
# define TC_RESET "me"
# define TC_CURSOR_HIDE "vi"
# define TC_CURSOR_VISIBLE "ve"

typedef struct timeval	t_timev;

typedef struct		s_search
{
  t_timev		prevtime;
  t_timev		curtime;
  int			strlen;
  char			str[256];
}			t_search;

typedef struct		s_data
{
  struct termios	term;
  int			tty_fd;
  int			win_width;
  int			win_height;
  int			col_width;
  int			col_height;
  int			cur_pos;
  t_my_list		*elems;
  int			opt_cols;
  char			opt_delim;
  int			exit;
  char			arbuf[8192];
  t_search     		search;
}			t_data;

typedef struct		s_mselect_elem
{
  int			checked;
  int			strlen;
  char			*str;
  char			*value;
}			t_mselect_elem;

/*
** main.c
*/
int		mselect_exit(t_data *data, char *err);
t_data		*mselect_get_data();

/*
** utils.c
*/
void		mselect_setpos(int *pos, int x, int y);
int		mselect_util_getnbr(char *str);

/*
** options.c
*/
int		mselect_load_options(t_data *data, int argc, char **argv);

/*
** loop.c
*/
int		mselect_loop(t_data *data);

/*
** loop_additional.c
*/
void		mselect_loop_key_reverse(t_data *data, char *buf, int len);
void		mselect_loop_key_movejump(t_data *data, char *buf, int len);
void		mselect_loop_key_selectall(t_data *data, char *buf, int len);

/*
** help.c
*/
int		mselect_print_usage(int argc, char **argv);
int		mselect_print_resizeinfo(t_data *data);

/*
** loader.c
*/
int		mselect_load_list(t_data *data, int argc, char **argv);
void		mselect_free_list(t_data *data);

/*
** elems.c
*/
t_mselect_elem	*mselect_elem_create(t_data *data, char *str);
void		mselect_elem_free(t_mselect_elem *elem);

/*
** term.c
*/
int		mselect_term_init(t_data *data, char **env);
int		mselect_term_reset(t_data *data);
int		mselect_term_cmd(t_data *data, char *cmd);
int		mselect_term_putc(int c);

/*
** term_info.c
*/
int		mselect_term_updatesize(t_data *data);
int		mselect_term_curpos(t_data *data, int x, int y);

/*
** draw.c
*/
int		mselect_draw(t_data *data);

/*
** print.c
*/
size_t		mselect_putstr(t_data *data, char *str);
ssize_t		mselect_putchar(t_data *data, char c);
void		mselect_print_result(t_data *data);

/*
** search.c
*/
int		mselect_search(t_data *data, char *buf, int len);

#endif /* !MY_SELECT_H_ */
