/*
** my_list_item.c for myutils in /home/poirie-n/blinux/poirie_n/repo/MyProjects/C_Lib_MyUtils/src/my_list
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Sun Dec 21 16:28:50 2014 Nathan Poirier
** Last update Thu Jan  8 17:44:27 2015 Nathan Poirier
*/

#include "myutils_list.h"
#include "myutils.h"

t_my_listitem	*_my_listitem_create(void *data)
{
  t_my_listitem *item;

  if ((item = malloc(sizeof(t_my_listitem))) == NULL)
    return (NULL);
  item->data = data;
  item->list = NULL;
  item->prev = NULL;
  item->next = NULL;
  return (item);
}

t_my_listitem	*my_list_get(t_my_list *list, int pos)
{
  t_my_listitem	*item;
  int		i;

  if (pos < 0 || pos >= list->size)
    return (NULL);
  i = 0;
  item = list->first;
  while (item != NULL && i < pos)
    {
      item = item->next;
      i++;
    }
  return (item);
}

void		my_list_remove(t_my_listitem *item)
{
  if (item->list)
    {
      if (item->list->first == item)
	item->list->first = item->next;
      if (item->list->last == item)
	item->list->last = item->prev;
      item->list->size--;
    }
  if (item->prev)
    item->prev->next = item->next;
  if (item->next)
    item->next->prev = item->prev;
  free(item->data);
  free(item);
}
