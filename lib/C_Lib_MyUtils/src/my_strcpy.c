/*
** my_strcpy.c for myutils in /home/poirie-n/blinux/poirie_n/repo/MyProjects/C_Lib_MyUtils/src
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Mon Jan  5 17:48:37 2015 Nathan Poirier
** Last update Mon Jan  5 17:54:42 2015 Nathan Poirier
*/

#include "myutils.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char	*my_strdup(char *str)
{
  char	*nstr;

  if ((nstr = malloc(my_strlen(str) + 1)) == NULL)
    return (NULL);
  my_strcpy(nstr, str);
  return (nstr);
}
