/*
** my_strerror.c for myutils in /home/poirie-n/blinux/poirie_n/repo/MyProjects/C_Lib_MyUtils/src
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Sun Dec 14 15:44:06 2014 Nathan Poirier
** Last update Sun Dec 14 15:44:07 2014 Nathan Poirier
*/

#include "myutils_strerror.h"
#include "myutils.h"

char		*my_strerror(int errnum)
{
  t_my_strerror	err;
  int		i;

  i = 0;
  while (i == 0 || err.errnum != 0)
    {
      err = my_strerror_list[i];
      if (err.errnum == errnum)
	return ((char *)(err.msg));
      i = i + 1;
    }
  return ("Unknown error");
}
