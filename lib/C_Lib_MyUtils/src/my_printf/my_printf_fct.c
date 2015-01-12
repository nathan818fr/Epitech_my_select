/*
** my_printf_fct.c for myutils in /home/poirie-n/blinux/poirie_n/repo/MyProjects/C_Lib_MyUtils/src/my_printf
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Sun Dec 14 16:35:21 2014 Nathan Poirier
** Last update Mon Dec 15 13:26:43 2014 Nathan Poirier
*/

#include "myutils_printf.h"
#include "myutils.h"

int		my_sprintf(char *str, const char *format, ...)
{
  va_list	ap;
  int		r;

  va_start(ap, format);
  r = my_vsprintf(str, format, ap);
  va_end(ap);
  return (r);
}

int		my_fprintf(int fd, const char *format, ...)
{
  va_list	ap;
  int		r;

  va_start(ap, format);
  r = my_vfprintf(fd, format, ap);
  va_end(ap);
  return (r);
}

int		my_printf(const char *format, ...)
{
  va_list	ap;
  int		r;

  va_start(ap, format);
  r = my_vprintf(format, ap);
  va_end(ap);
  return (r);
}
