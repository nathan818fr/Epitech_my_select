/*
** my_printf_utils.c for myutils in /home/poirie-n/blinux/poirie_n/repo/MyProjects/C_Lib_MyUtils
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Mon Dec 15 14:22:58 2014 Nathan Poirier
** Last update Fri Jan  9 11:14:37 2015 Nathan Poirier
*/

#include "myutils_printf.h"
#include "myutils.h"

int	_my_printf_putchar_at(t_my_printf *pf, char c, int pos)
{
  if (pf->fd == -1)
    pf->str[pf->printed + pos] = c;
  else
    write(pf->fd, &c, 1);
  return (1);
}

int	_my_printf_putchar(t_my_printf *pf, char c)
{
  if (pf->fd == -1)
    pf->str[pf->printed] = c;
  else
    write(pf->fd, &c, 1);
  return (1);
}

int     _my_printf_putstr(t_my_printf *pf, char *str)
{
  int	i;
  int	l;

  if ((l = my_strlen(str)) <= 0)
    return (0);
  if (pf->fd == -1)
    {
      i = 0;
      while (i < l)
	{
	  pf->str[pf->printed + i] = str[i];
	  i++;
	}
    }
  else
    write(pf->fd, str, l);
  return (l);
}
