/*
** term_info.c for my_select in /home/poirie-n/blinux/poirie_n/repo/B1/Syst_Unix/PSU_2014_my_select
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Thu Jan  8 17:50:54 2015 Nathan Poirier
** Last update Sat Jan 10 14:28:34 2015 Nathan Poirier
*/

#include "my_select.h"

int			mselect_term_updatesize(t_data *data)
{
  struct winsize	win;

  if (ioctl(data->tty_fd, TIOCGWINSZ, &win) == -1)
    return (-1);
  data->win_width = win.ws_col;
  data->win_height = win.ws_row;
  data->col_width = 32 + 1;
  if (data->opt_cols > 0)
    data->col_width = data->opt_cols + 1;
  data->col_height = win.ws_row;
  if (data->win_height > 2)
    data->col_height--;
  return (0);
}

int     mselect_term_curpos(t_data *data, int x, int y)
{
  char	*buf;
  char	*res;

  buf = data->arbuf;
  if ((res = tgetstr("cm", &buf)) == NULL)
    return (mselect_exit(data, "Runtime error: tgetstr"));
  tputs(tgoto(res, x, y), 0, mselect_term_putc);
  return (0);
}
