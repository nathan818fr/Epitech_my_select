/*
** loop.c for my_select in /home/poirie-n/blinux/poirie_n/repo/B1/Syst_Unix/PSU_2014_my_select
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Thu Jan  8 17:30:26 2015 Nathan Poirier
** Last update Sun Jan 11 17:31:06 2015 Nathan Poirier
*/

#include "my_select.h"

void			mselect_loop_key_exit(t_data *data, char *buf, int len)
{
  if (len == 1 && (buf[0] == ASCII_ETX || buf[0] == ASCII_EOT ||
		   buf[0] == ASCII_ESC))
    mselect_exit(data, NULL);
  if (len == 1 && buf[0] == ASCII_NL)
    {
      mselect_print_result(data);
      mselect_exit(data, NULL);
    }
}

int			mselect_loop_key_action_getkey(int len, char *buf)
{
  if (len == 1 && buf[0] == ASCII_SPACE)
    return (1);
  else if (len == 1 && buf[0] == ASCII_BACKSPACE)
    return (2);
  else if (len == 4 && buf[0] == 27 && buf[1] == 91 && buf[2] == 51 &&
	   buf[3] == 126)
    return (3);
  return (0);
}

void			mselect_loop_key_action(t_data *data, char *buf,
						int len)
{
  int			action;
  t_my_listitem		*it;
  t_mselect_elem	*elem;

  if ((action = mselect_loop_key_action_getkey(len, buf)) != 0 &&
      (it = my_list_get(data->elems, data->cur_pos)) != NULL)
    {
      elem = (t_mselect_elem *)it->data;
      if (action == 1)
	{
	  elem->checked = !elem->checked;
	  if (elem->checked && data->cur_pos < data->elems->size - 1)
	    data->cur_pos++;
	}
      if (action >= 2)
	{
	  mselect_elem_free((t_mselect_elem *)it->data);
	  it->data = NULL;
	  my_list_remove(it);
	  if (action == 2 && data->cur_pos > 0)
	    data->cur_pos--;
	  if (data->cur_pos >= data->elems->size)
	    data->cur_pos = data->elems->size - 1;
	}
    }
}

void			mselect_loop_key_move(t_data *data, char *buf, int len)
{
  if (len == 3 && buf[0] == 27 && buf[1] == 91)
    {
      if (buf[2] == 65)
	data->cur_pos--;
      else if (buf[2] == 66)
	data->cur_pos++;
      else if (buf[2] == 67)
	{
	  if (data->cur_pos + data->col_height < data->elems->size)
	    data->cur_pos += data->col_height;
	}
      else if (buf[2] == 68)
	{
	  if (data->cur_pos - data->col_height >= 0)
	    data->cur_pos -= data->col_height;
	}
      if (data->cur_pos < 0)
	data->cur_pos = data->elems->size + data->cur_pos;
      if (data->cur_pos >= data->elems->size)
	data->cur_pos = data->elems->size - data->cur_pos;
    }
}

int			mselect_loop(t_data *data)
{
  char			buf[5];
  int			len;

  while (1)
    {
      if (data->elems == NULL)
	mselect_exit(data, "List is empty");
      mselect_draw(data);
      if ((len = read(0, buf, 4)) == -1)
	{
	  if (errno != EINTR && errno != EAGAIN)
	    mselect_exit(data, "Runtime error: read");
	}
      mselect_loop_key_exit(data, buf, len);
      mselect_loop_key_action(data, buf, len);
      mselect_loop_key_move(data, buf, len);
      mselect_search(data, buf, len);
      mselect_loop_key_reverse(data, buf, len);
      mselect_loop_key_movejump(data, buf, len);
      mselect_loop_key_selectall(data, buf, len);
      if (data->elems->size <= 0)
	mselect_exit(data, "List is empty");
    }
  return (0);
}
