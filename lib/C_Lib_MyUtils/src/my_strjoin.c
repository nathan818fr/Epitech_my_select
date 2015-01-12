/*
** my_strjoin.c for myutils in /home/poirie-n/blinux/poirie_n/repo/MyProjects/C_Lib_MyUtils/src
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Mon Dec 15 16:09:48 2014 Nathan Poirier
** Last update Mon Dec 15 17:43:54 2014 Nathan Poirier
*/

#include <stdlib.h>
#include "myutils.h"

int		_my_strnjoin_append(char **str, int *str_size,
				    char *argstr, int argstr_size)
{
  char		*nstr;
  int		i;

  if ((nstr = malloc(*str_size + argstr_size + 1)) == NULL)
    return (-1);
  i = 0;
  while (i < *str_size)
    {
      nstr[i] = (*str)[i];
      i++;
    }
  while (i < *str_size + argstr_size)
    {
      nstr[i] = argstr[i - *str_size];
      i++;
    }
  nstr[i] = '\0';
  free(*str);
  *str = nstr;
  *str_size = *str_size + argstr_size;
  return (0);
}

char		*my_strnjoin(int n, ...)
{
  char		*str;
  int		str_size;
  char		*argstr;
  va_list	ap;

  str = NULL;
  str_size = 0;
  va_start(ap, n);
  while (n > 0)
    {
      argstr = va_arg(ap, char *);
      if (argstr != NULL &&
	  _my_strnjoin_append(&str, &str_size,
			      argstr, my_strlen(argstr)) == -1)
	return (NULL);
      n--;
    }
  va_end(ap);
  return (str);
}
