/*
** loader.c for my_select in /home/poirie-n/blinux/poirie_n/repo/B1/Syst_Unix/PSU_2014_my_select
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Mon Jan  5 14:35:12 2015 Nathan Poirier
** Last update Sat Jan 10 15:00:08 2015 Nathan Poirier
*/

#include "my_select.h"

int			mselect_load_list(t_data *data, int argc, char **argv)
{
  t_mselect_elem	*elem;
  int			i;
  int			maxlen;

  maxlen = 10;
  if ((data->elems = my_list_create()) == NULL)
    return (-1);
  i = 0;
  while (i < argc)
    {
      if ((elem = mselect_elem_create(data, argv[i])) == NULL)
	return (-1);
      if (my_list_add(data->elems, elem) == NULL)
	return (-1);
      if (elem->strlen > maxlen)
	maxlen = elem->strlen;
      i++;
    }
  if (maxlen < data->opt_cols)
    data->opt_cols = maxlen;
  return (0);
}

void			mselect_free_list(t_data *data)
{
  t_my_listitem		*it;

  if (data->elems == NULL)
    return ;
  it = data->elems->first;
  while (it)
    {
      if (it->data)
	mselect_elem_free((t_mselect_elem *)it->data);
      it->data = NULL;
      it = it->next;
    }
  my_list_free(data->elems);
}
