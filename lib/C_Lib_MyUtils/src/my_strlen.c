/*
** my_strlen.c for myutils in /home/poirie-n/blinux/poirie_n/repo/MyProjects/C_Lib_MyUtils
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Wed Dec 10 13:37:57 2014 Nathan Poirier
** Last update Wed Dec 10 13:51:36 2014 Nathan Poirier
*/

#include "myutils.h"

/*
** Calculate the length of a string.
**
** Return:
**  The number of bytes in the string is returned.
**  If the string is NULL, 0 is returned.
*/
size_t		my_strlen(char *str)
{
  size_t	l;

  if (!str)
    return (0);
  l = 0;
  while (str[l])
    l++;
  return (l);
}
