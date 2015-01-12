/*
** elems.c for my_select in /home/poirie-n/blinux/poirie_n/repo/B1/Syst_Unix/PSU_2014_my_select
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Mon Jan  5 17:41:38 2015 Nathan Poirier
** Last update Sat Jan 10 14:54:07 2015 Nathan Poirier
*/

#include "my_select.h"

void			mselect_elem_parse_delim(t_data *data,
						 t_mselect_elem * elem)
{
  int			i;

  if (data->opt_delim != 0)
    {
      i = 0;
      while (i >= 0 && elem->str[i])
	{
	  if (elem->str[i] == data->opt_delim)
	    {
	      elem->strlen = i;
	      elem->str[i] = '\0';
	      elem->value = elem->str + i + 1;
	    }
	  i++;
	}
    }
}

t_mselect_elem		*mselect_elem_create(t_data *data, char *str)
{
  t_mselect_elem	*elem;

  if ((elem = malloc(sizeof(t_mselect_elem))) == NULL)
    return (NULL);
  elem->checked = 0;
  elem->strlen = my_strlen(str);
  elem->str = my_strdup(str);
  if (elem->str == NULL)
    {
      mselect_elem_free(elem);
      return (NULL);
    }
  elem->value = NULL;
  mselect_elem_parse_delim(data, elem);
  return (elem);
}

void			mselect_elem_free(t_mselect_elem *elem)
{
  if (elem == NULL)
    return ;
  free(elem->str);
  free(elem);
}
