/*
** my_printf_vfct.c for myutils in /home/poirie-n/blinux/poirie_n/repo/MyProjects/C_Lib_MyUtils/src/my_printf
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Sun Dec 14 16:37:11 2014 Nathan Poirier
** Last update Sun Dec 14 16:37:45 2014 Nathan Poirier
*/

#include "myutils_printf.h"
#include "myutils.h"

int             my_vsprintf(char *str, const char *format, va_list ap)
{
  return (_my_printf(-1, str, format, ap));
}

int             my_vfprintf(int fd, const char *format, va_list ap)
{
  return (_my_printf(fd, NULL, format, ap));
}

int             my_vprintf(const char *format, va_list ap)
{
  return (_my_printf(STDOUT_FILENO, NULL, format, ap));
}
