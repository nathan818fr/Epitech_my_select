/*
** my_printf.c for myutils in /home/poirie-n/blinux/poirie_n/repo/MyProjects/C_Lib_MyUtils/src/my_printf
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Sun Dec 14 16:42:44 2014 Nathan Poirier
** Last update Fri Jan  9 10:52:30 2015 Nathan Poirier
*/

#include "myutils_printf.h"
#include "myutils.h"

char		*_my_printf_init_flags()
{
  char		*tab;

  if ((tab = malloc(sizeof(char) * MYUTILS_PRINTF_FLAGS)) == NULL)
    return (NULL);
  tab[0] = '%';
  tab[1] = 'c';
  tab[2] = 's';
  tab[3] = 'd';
  return (tab);
}

t_printf_func	*_my_printf_init_funcs()
{
  t_printf_func	*tab;

  if ((tab = malloc(sizeof(t_printf_func) * MYUTILS_PRINTF_FLAGS)) == NULL)
    return (NULL);
  tab[0] = (t_printf_func)&_my_printf_flag_perc;
  tab[1] = (t_printf_func)&_my_printf_flag_c;
  tab[2] = (t_printf_func)&_my_printf_flag_s;
  tab[3] = (t_printf_func)&_my_printf_flag_d;
  return (tab);
}

t_my_printf	*_my_printf_init(int fd, char *str)
{
  t_my_printf	*pf;

  if ((pf = malloc(sizeof(t_my_printf))) == NULL)
    return (NULL);
  if ((pf->tab_flag = _my_printf_init_flags()) == NULL)
    return (NULL);
  if ((pf->tab_func = _my_printf_init_funcs()) == NULL)
    return (NULL);
  pf->fd = fd;
  pf->str = str;
  pf->printed = 0;
  return (pf);
}

void		_my_printf_free(t_my_printf *pf)
{
  free(pf->tab_flag);
  free(pf->tab_func);
  free(pf);
}

int		_my_printf(int fd, char *str, const char *format, va_list ap)
{
  t_my_printf	*pf;
  int		r;

  if ((pf = _my_printf_init(fd, str)) == NULL)
    return (-1);
  _my_printf_exec(pf, format, ap, 0);
  r = pf->printed;
  _my_printf_free(pf);
  return (r);
}
