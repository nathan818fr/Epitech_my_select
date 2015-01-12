/*
** loop_additional.c for my_select in /home/poirie-n/blinux/poirie_n/repo/B1/Syst_Unix/PSU_2014_my_select
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Sun Jan 11 14:16:40 2015 Nathan Poirier
** Last update Sun Jan 11 15:18:27 2015 Nathan Poirier
*/

#include "my_select.h"

/*
** Reverse selection with Tab
*/
void			mselect_loop_key_reverse(t_data *data, char *buf,
						 int len)
{
  t_my_listitem		*it;
  t_mselect_elem	*elem;

  if (len == 1 && buf[0] == 9)
    {
      it = data->elems->first;
      while (it)
	{
	  elem = (t_mselect_elem *)it->data;
	  elem->checked = !elem->checked;
	  it = it->next;
	}
    }
}

/*
** Move first / last element with PageUp / PageDown
*/
void			mselect_loop_key_movejump(t_data *data, char *buf,
						  int len)
{
  if (len == 4 && buf[0] == 27 && buf[1] == 91 && buf[3] == 126)
    {
      if (buf[2] == 53)
	data->cur_pos = 0;
      if (buf[2] == 54)
	data->cur_pos = data->elems->size - 1;
    }
}

/*
** Select all (or deselect all) ith Ctrl-A
*/
void			mselect_loop_key_selectall(t_data *data, char *buf,
						   int len)
{
  t_my_listitem		*it;
  int			check_type;

  if (len == 1 && buf[0] == 1)
    {
      check_type = 0;
      it = data->elems->first;
      while (it && check_type == 0)
	{
	  if (!((t_mselect_elem *)it->data)->checked)
	    check_type = 1;
	  it = it->next;
	}
      it = data->elems->first;
      while (it)
	{
	  ((t_mselect_elem *)it->data)->checked = check_type;
	  it = it->next;
	}
    }
}
