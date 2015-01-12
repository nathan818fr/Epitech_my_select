/*
** my_strcmp.c for myutils in /home/poirie-n/blinux/poirie_n/repo/MyProjects/C_Lib_MyUtils
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Wed Dec 10 14:15:06 2014 Nathan Poirier
** Last update Wed Jan  7 14:53:37 2015 Nathan Poirier
*/

#include "myutils.h"

/*
** Compare two strings.
**
** Return:
**  An integer less than, equal to, or greater than zero if s1 is found,
**  respectively, to be less than, to match, or be greater than s2.
*/
int		my_strcmp(char *s1, char *s2)
{
  size_t	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i])
    i++;
  return (s1[i] - s2[i]);
}

/*
** Compare the first n bytes of two strings.
**
** Return:
**  An integer less than, equal to, or greater than zero if the first n bytes
**  of s1 is found, respectively, to be less than, to match, or be greater
**  than s2.
*/
int		my_strncmp(char *s1, char *s2, size_t n)
{
  size_t	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] && i < n)
    i++;
  if (i < n)
    return (s1[i] - s2[i]);
  return (0);
}

int		my_str_startswith(char *s1, char *s2)
{
  if (my_strncmp(s1, s2, my_strlen(s2)) == 0)
    return (1);
  return (0);
}
