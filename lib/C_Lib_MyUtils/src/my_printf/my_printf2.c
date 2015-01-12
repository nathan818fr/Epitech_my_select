/*
** my_printf2.c for myutils in /home/poirie-n/blinux/poirie_n/repo/MyProjects/C_Lib_MyUtils
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Mon Dec 15 13:37:33 2014 Nathan Poirier
** Last update Mon Dec 15 14:21:40 2014 Nathan Poirier
*/

#include "errno.h"
#include "myutils_printf.h"
#include "myutils.h"

int             _my_printf_get_flag(t_my_printf *pf, const char *str, int *i)
{
  int           pos;
  int           r;

  pos = 1;
  while (str[*i + pos] == ' ')
    pos = pos + 1;
  if (str[*i + pos] == '\0')
    return (-2);
  r = 0;
  while (r < MYUTILS_PRINTF_FLAGS)
    {
      if (pf->tab_flag[r] == str[*i + pos])
	{
	  *i = *i + pos;
	  return (r);
	}
      r = r + 1;
    }
  return (-1);
}

void    _my_printf_exec(t_my_printf *pf, const char *str, va_list ap, int i)
{
  int   flag;

  while (str[i])
    {
      if (str[i] == '%' && (flag = _my_printf_get_flag(pf, str, &i)) >= 0)
	pf->printed += (pf->tab_func[flag])(pf, ap);
      else if (flag == -2)
	{
	  errno = EINVAL;
	  pf->printed = -1;
	  return ;
	}
      else
	pf->printed += _my_printf_putchar(pf, str[i]);
      i = i + 1;
    }
}
