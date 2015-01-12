/*
** my_printf_flags_d.c for myutils in /home/poirie-n/blinux/poirie_n/repo/MyProjects/C_Lib_MyUtils/src/my_printf
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Fri Jan  9 10:50:03 2015 Nathan Poirier
** Last update Fri Jan  9 11:13:39 2015 Nathan Poirier
*/

#include <stdarg.h>
#include <stdlib.h>
#include "myutils_printf.h"
#include "myutils.h"

void		_my_printf_flag_d_put(t_my_printf *pf, int nb, int *r)
{
  if (nb <= -10)
    _my_printf_flag_d_put(pf, nb / 10, r);
  *r += _my_printf_putchar_at(pf, '0' - (nb % 10), *r);
}

int		_my_printf_flag_d(t_my_printf *pf, va_list ap)
{
  int		r;
  int		nb;

  r = 0;
  nb = va_arg(ap, int);
  if (nb < 0)
    r += _my_printf_putchar_at(pf, '-', r);
  else
    nb = -nb;
  _my_printf_flag_d_put(pf, nb, &r);
  return (r);
}
