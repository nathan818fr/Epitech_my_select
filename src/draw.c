/*
** draw.c for my_select in /home/poirie-n/blinux/poirie_n/repo/B1/Syst_Unix/PSU_2014_my_select
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Wed Jan  7 16:16:28 2015 Nathan Poirier
** Last update Sun Jan 11 17:30:17 2015 Nathan Poirier
*/

#include "my_select.h"

int			mselect_draw_elem(t_data *data, t_mselect_elem *elem,
					  int *pos, int i)
{
  int			x;

  if (pos[0] < 0 || pos[0] >= data->win_width)
    return (elem->checked ? 1 : 0);
  mselect_term_curpos(data, pos[0], pos[1]);
  mselect_term_cmd(data, TC_RESET);
  if (elem->checked)
    mselect_term_cmd(data, TC_REVERSE);
  if (i == data->cur_pos)
    mselect_term_cmd(data, TC_UNDERLINE);
  x = 0;
  while (x < data->col_width - 1)
    {
      if (pos[0] + x >= 0 && pos[0] + x < data->win_width)
	{
	  if (x < elem->strlen)
	    mselect_putchar(data, elem->str[x]);
	}
      x++;
    }
  mselect_term_cmd(data, TC_RESET);
  return (elem->checked ? 1 : 0);
}

int			mselect_draw_info_at(t_data *data, char *str,
					     int strlen,
					     int i, t_mselect_elem *elem)
{
  if (elem != NULL && i < elem->strlen &&
      i < data->win_width - strlen - 2)
    {
      if (i == data->win_width - strlen - 2 - 1 && i + 1 < elem->strlen)
	{
	  mselect_term_cmd(data, TC_RESET);
	  mselect_putstr(data, BASH_BG_RED);
	}
      mselect_putchar(data, elem->str[i]);
      if (i == data->win_width - strlen - 2 - 1 && i + 1 < elem->strlen)
	{
	  mselect_putstr(data, BASH_BG_RESET);
	  mselect_term_cmd(data, TC_REVERSE);
	}
    }
  else if (strlen > 0 && i == data->win_width - strlen - 1)
    {
      mselect_putstr(data, str);
      return (1);
    }
  else
    mselect_putchar(data, ' ');
  return (0);
}

void			mselect_draw_info(t_data *data, int count)
{
  char			str[81];
  int			strlen;
  int			i;
  t_my_listitem		*it;
  t_mselect_elem	*elem;

  my_memset(str, 0, 81);
  strlen = my_sprintf(str, "(%d) %d/%d", count, data->cur_pos + 1,
		      data->elems->size);
  elem = NULL;
  if ((it = my_list_get(data->elems, data->cur_pos)) != NULL)
    elem = (t_mselect_elem *)it->data;
  mselect_term_curpos(data, 0, data->win_height - 1);
  mselect_term_cmd(data, TC_RESET);
  mselect_term_cmd(data, TC_REVERSE);
  i = 0;
  while (i < data->win_width)
    {
      if (mselect_draw_info_at(data, str, strlen, i, elem) == 1)
	i = data->win_width;
      i++;
    }
  mselect_term_cmd(data, TC_RESET);
}

int			mselect_draw_check(t_data *data, int *pos)
{
  if (mselect_term_updatesize(data) == -1)
    mselect_exit(data, "Runtime: ioctl");
  mselect_term_cmd(data, TC_CURSOR_HIDE);
  mselect_term_cmd(data, TC_CLEAR);
  if (data->col_width <= 0 || data->col_height <= 0)
    return (-1);
  if (data->win_height < 2 || data->win_width < data->col_width - 1)
    return (mselect_print_resizeinfo(data));
  pos[0] = (data->cur_pos / data->col_height + 1) * data->col_width;
  if (pos[0] > data->win_width)
    pos[0] = -((pos[0] - data->win_width) / data->col_width
	       + (data->col_width < data->win_width))
      * data->col_width;
  else
    pos[0] = 0;
  pos[1] = 0;
  return (0);
}

int			mselect_draw(t_data *data)
{
  int			count;
  int			i;
  int			pos[2];
  t_my_listitem		*it;

  if (mselect_draw_check(data, pos) == -1)
    return (-1);
  i = 0;
  count = 0;
  it = data->elems->first;
  while (it)
    {
      count += mselect_draw_elem(data, (t_mselect_elem *)it->data, pos, i);
      pos[1]++;
      if (pos[1] >= data->col_height)
	mselect_setpos(pos, pos[0] + data->col_width, 0);
      i++;
      it = it->next;
    }
  if (data->col_height < data->win_height)
    mselect_draw_info(data, count);
  return (0);
}
