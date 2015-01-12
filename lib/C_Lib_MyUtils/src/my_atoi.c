/*
** my_atoi.c for myutils in /home/poirie-n/blinux/poirie_n/repo/MyProjects/C_Lib_MyUtils
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Wed Dec 10 14:38:55 2014 Nathan Poirier
** Last update Wed Dec 10 14:48:03 2014 Nathan Poirier
*/

/*
** Convert string to int.
** Stop at first non-numeric character.
**
** Return:
**  The converted value is returned.
*/
int     my_atoi(char *str)
{
  int	nb;
  int	i;

  i = (str[0] == '-') ? 1 : 0;
  nb = 0;
  while (str[i])
    {
      if (str[i] >= '0' && str[i] <= '9')
	{
	  nb *= 10;
	  nb -= str[i] - '0';
	}
      else
	{
	  if (str[0] != '-')
	    nb = -nb;
	  return (nb);
	}
      i++;
    }
  if (str[0] != '-')
    nb = -nb;
  return (nb);
}

/*
** Convert string to long.
** Stop at first non-numeric character.
**
** Return:
**  The converted value is returned.
*/
long	my_atol(char *str)
{
  long	nb;
  int   i;

  i = (str[0] == '-') ? 1 : 0;
  nb = 0;
  while (str[i])
    {
      if (str[i] >= '0' && str[i] <= '9')
	{
	  nb *= 10;
	  nb -= str[i] - '0';
	}
      else
	{
	  if (str[0] != '-')
	    nb = -nb;
	  return (nb);
	}
      i++;
    }
  if (str[0] != '-')
    nb = -nb;
  return (nb);
}
