/*
** my_memset.c for myutils in /home/poirie-n/blinux/poirie_n/repo/MyProjects/C_Lib_MyUtils
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Thu Jan  8 16:01:57 2015 Nathan Poirier
** Last update Thu Jan  8 16:06:43 2015 Nathan Poirier
*/

#include "myutils.h"

void		*my_memset(void *s, int c, size_t size)
{
  char		*str;
  size_t	i;

  str = (char *)s;
  i = 0;
  while (i < size)
    {
      str[i] = c;
      i++;
    }
  return (s);
}
