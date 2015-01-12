/*
** my_getenv.c for myutils in /home/poirie-n/blinux/poirie_n/repo/MyProjects/C_Lib_MyUtils
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Tue Jan  6 16:16:06 2015 Nathan Poirier
** Last update Wed Jan  7 14:27:45 2015 Nathan Poirier
*/

#include "myutils.h"

char	*my_getenv(char **env, char *name)
{
  int	i;

  i = 0;
  while (env[i])
    {
      if (my_str_startswith(env[i], name) && env[i][my_strlen(name)] == '=')
	return (env[i] + my_strlen(name) + 1);
      i++;
    }
  return (NULL);
}
