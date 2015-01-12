/*
** myutils_list.h for myutils in /home/poirie-n/blinux/poirie_n/repo/MyProjects/C_Lib_MyUtils/include
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Sun Dec 21 15:58:46 2014 Nathan Poirier
** Last update Mon Dec 22 01:27:52 2014 Nathan Poirier
*/

#ifndef MYUTILS_LIST_H_
# define MYUTILS_LIST_H_

struct			s_my_listitem;
struct			s_my_list;

typedef struct		s_my_listitem
{
  void			*data;
  struct s_my_list	*list;
  struct s_my_listitem	*prev;
  struct s_my_listitem	*next;
}			t_my_listitem;

typedef struct		s_my_list
{
  int			size;
  t_my_listitem		*first;
  t_my_listitem		*last;
}			t_my_list;

/*
** my_list.c
*/
t_my_list	*my_list_create();
void		my_list_clean(t_my_list *list);
void		my_list_free(t_my_list *list);

/*
** my_list_item.c (TODO: Move in precise files)
*/
t_my_listitem	*my_list_add(t_my_list *list, void *data);
t_my_listitem	*my_list_insert(t_my_list *list, void *data, int pos);
t_my_listitem	*my_list_get(t_my_list *list, int pos);
void		my_list_remove(t_my_listitem *item);

/*
** my_list_item.c
*/
t_my_listitem	*_my_listitem_create(void *data);
void		_my_listitem_insert_at(t_my_list *list, t_my_listitem *item, t_my_listitem *pos);

#endif /* !MYUTILS_LIST_H_ */
