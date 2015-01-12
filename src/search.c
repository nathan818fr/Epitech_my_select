/*
** search.c for my_select in /home/poirie-n/blinux/poirie_n/repo/B1/Syst_Unix/PSU_2014_my_select
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Sat Jan 10 17:58:09 2015 Nathan Poirier
** Last update Sat Jan 10 18:54:23 2015 Nathan Poirier
*/

#include "my_select.h"

void			my_timeval_copy(struct timeval *dst, struct timeval *src)
{
  dst->tv_sec = src->tv_sec;
  dst->tv_usec = src->tv_usec;
}

char			mselect_search_parsechar(char c)
{
  if (c >= 'A' && c <= 'Z')
    return (c + 'a' - 'A');
  return (c);
}

int			mselect_search_startwith(t_mselect_elem *elem, char *search,
						 int slen)
{
  int			i;

  i = 0;
  while (elem->str[i] && i < slen)
    {
      if (mselect_search_parsechar(elem->str[i]) !=
	  mselect_search_parsechar(search[i]))
	return (0);
      if (i + 1 == slen)
	return (1);
      i++;
    }
  return (0);
}

void			mselect_search_movecur(t_data *data, char *search, int slen)
{
  t_my_listitem		*it;
  int			cur[2];
  int			i;

  cur[0] = -1;
  cur[1] = -1;
  it = (data->elems != NULL) ? data->elems->first : NULL;
  i = 0;
  while (it && cur[1] == -1)
    {
      if (mselect_search_startwith((t_mselect_elem *)it->data, search, slen))
	{
	  if (cur[0] == -1)
	    cur[0] = i;
	  if (i > data->cur_pos - (slen > 1 ? 1 : 0))
	    cur[1] = i;
	}
      it = it->next;
      i++;
    }
  if (cur[1] >= 0)
    data->cur_pos = cur[1];
  else if (cur[0] >= 0)
    data->cur_pos = cur[0];
}

int			mselect_search(t_data *data, char *buf, int len)
{
  size_t	diff;

  if (len == 1 && buf[0] >= 33 && buf[0] <= 126)
    {
      gettimeofday(&data->search.curtime, NULL);
      diff = (1000000
	      * (data->search.curtime.tv_sec - data->search.prevtime.tv_sec)
	      + (data->search.curtime.tv_usec - data->search.prevtime.tv_usec));
      if (diff > 300 * 1000)
	data->search.strlen = 0;
      my_timeval_copy(&data->search.prevtime, &data->search.curtime);
      if (data->search.strlen >= 254)
	return (0);
      data->search.str[data->search.strlen] = buf[0];
      data->search.str[data->search.strlen + 1] = '\0';
      data->search.strlen++;
      mselect_search_movecur(data, data->search.str, data->search.strlen);
    }
  return (0);
}
