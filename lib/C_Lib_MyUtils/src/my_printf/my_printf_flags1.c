/*
** my_printf_flags1.c for myutils in /home/poirie-n/blinux/poirie_n/repo/MyProjects/C_Lib_MyUtils/src/my_printf
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Sun Dec 14 16:39:31 2014 Nathan Poirier
** Last update Fri Jan  9 10:51:16 2015 Nathan Poirier
*/

#include <stdarg.h>
#include <stdlib.h>
#include "myutils_printf.h"
#include "myutils.h"

int		_my_printf_flag_perc(t_my_printf *pf, va_list ap)
{
  return (_my_printf_putchar(pf, '%'));
}

int		_my_printf_flag_c(t_my_printf *pf, va_list ap)
{
  unsigned char c;

  c = (unsigned char)va_arg(ap, int);
  return (_my_printf_putchar(pf, c));
}

int		_my_printf_flag_s(t_my_printf *pf, va_list ap)
{
  char		*str;

  str = va_arg(ap, char*);
  if (str == NULL)
    str = "(nil)";
  return (_my_printf_putstr(pf, str));
}
