/*
** print.c for my_select in /home/poirie-n/blinux/poirie_n/repo/B1/Syst_Unix/PSU_2014_my_select
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Thu Jan  8 16:13:04 2015 Nathan Poirier
** Last update Sun Jan 11 15:08:57 2015 Nathan Poirier
*/

#include "my_select.h"

size_t			mselect_putstr(t_data *data, char *str)
{
  return (my_putstr_to(data->tty_fd, str));
}

ssize_t			mselect_putchar(t_data *data, char c)
{
  return (my_putchar_to(data->tty_fd, c));
}

void                    mselect_print_shell_arg(char *str)
{
  int                   i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}

void			mselect_print_result(t_data *data)
{
  int			i;
  t_my_listitem		*it;
  t_mselect_elem	*elem;

  i = 0;
  it = data->elems->first;
  while (it)
    {
      elem = (t_mselect_elem *)it->data;
      if (elem->checked)
	{
	  if (i > 0)
	    my_putchar(' ');
	  if (elem->value == NULL)
	    mselect_print_shell_arg(elem->str);
	  else
	    mselect_print_shell_arg(elem->value);
	  i++;
	}
      it = it->next;
    }
}
