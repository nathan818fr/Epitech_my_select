/*
** utils.c for my_select in /home/poirie-n/blinux/poirie_n/repo/B1/Syst_Unix/PSU_2014_my_select
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Sat Jan 10 14:28:50 2015 Nathan Poirier
** Last update Sat Jan 10 16:07:05 2015 Nathan Poirier
*/

#include "my_select.h"

void	mselect_setpos(int *pos, int x, int y)
{
  pos[0] = x;
  pos[1] = y;
}

int	mselect_util_getnbr(char *str)
{
  int	nb;
  int	pow;
  int	i;

  if (str[0] == '\0')
    return (-1);
  nb = 0;
  pow = 1;
  i = 0;
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9' || i >= 3)
	return (-1);
      if (nb == 0 && str[i] == '0')
	str++;
      else
	{
	  nb = nb * pow + (str[i] - '0');
	  pow *= 10;
	  i++;
	}
    }
  return (nb);
}
