/*
** my_list_insert.c for myutils in /home/poirie-n/blinux/poirie_n/repo/MyProjects/C_Lib_MyUtils
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Thu Jan  8 17:44:59 2015 Nathan Poirier
** Last update Thu Jan  8 17:45:08 2015 Nathan Poirier
*/

#include "myutils_list.h"
#include "myutils.h"

void		_my_listitem_insert_at(t_my_list *list, t_my_listitem *item,
				       t_my_listitem *pos)
{
  item->list = list;
  if (pos == NULL)
    {
      item->prev = list->last;
      if (list->last != NULL)
	list->last->next = item;
      list->last = item;
      if (list->first == NULL)
	list->first = item;
    }
  else
    {
      item->next = pos;
      pos->prev = item;
      if (pos == list->first)
	list->first = item;
    }
  list->size++;
}

t_my_listitem	*my_list_add(t_my_list *list, void *data)
{
  return (my_list_insert(list, data, -1));
}

t_my_listitem	*my_list_insert(t_my_list *list, void *data, int pos)
{
  t_my_listitem	*item;

  if ((item = _my_listitem_create(data)) == NULL)
    return (NULL);
  if (list)
    {
      if (pos < -list->size)
	pos = 0;
      else if (pos >= list->size)
	pos = list->size - 1;
      else if (pos < 0)
	pos = list->size + pos + 1;
      if (pos == 0)
	_my_listitem_insert_at(list, item, list->first);
      else if (pos == list->size)
	_my_listitem_insert_at(list, item, NULL);
      else
	{
	  _my_listitem_insert_at(list, item, my_list_get(list, pos));
	}
    }
  return (item);
}
