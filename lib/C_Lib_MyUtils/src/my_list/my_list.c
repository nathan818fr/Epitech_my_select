/*
** my_list.c for myutils in /home/poirie-n/blinux/poirie_n/repo/MyProjects/C_Lib_MyUtils/src/my_list
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Sun Dec 21 15:58:15 2014 Nathan Poirier
** Last update Sun Dec 21 16:30:47 2014 Nathan Poirier
*/

#include "myutils_list.h"
#include "myutils.h"

t_my_list	*my_list_create()
{
  t_my_list	*list;

  if ((list = malloc(sizeof(t_my_list))) == NULL)
    return (NULL);
  list->size = 0;
  list->first = NULL;
  list->last = NULL;
  return (list);
}

void		my_list_clean(t_my_list *list)
{
  if (list)
    {
      while (list->first)
	my_list_remove(list->first);
    }
}

void		my_list_free(t_my_list *list)
{
  my_list_clean(list);
  free(list);
}
