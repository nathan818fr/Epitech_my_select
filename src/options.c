/*
** options.c for my_select in /home/poirie-n/blinux/poirie_n/repo/B1/Syst_Unix/PSU_2014_my_select
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Sat Jan 10 13:46:11 2015 Nathan Poirier
** Last update Sat Jan 10 14:41:10 2015 Nathan Poirier
*/

#include "my_select.h"

int	mselect_option_getvpos(char *opt, char *name)
{
  int	l;
  if (my_str_startswith(opt, name))
    {
      l = my_strlen(name);
      if (opt[l] == '=')
	return (l + 1);
      if (opt[l] != '\0')
	return (-1);
      return (l);
    }
  return (-1);
}

int	mselect_option_cols(t_data *data, char *opt)
{
  int	p;

  p = mselect_option_getvpos(opt, "-C");
  if (p == -1)
    p = mselect_option_getvpos(opt, "--col-width");
  if (p != -1)
    {
      data->opt_cols = mselect_util_getnbr(opt + p);
      if (data->opt_cols <= 0)
	return (my_error_zero("-C, --col-width value must be a positive \
integer (max value: 999).") - 2);
      return (1);
    }
  return (-1);
}

int	mselect_option_valdelim(t_data *data, char *opt)
{
  int   p;

  p = mselect_option_getvpos(opt, "-V");
  if (p == -1)
    p = mselect_option_getvpos(opt, "--val-delemiter");
  if (p != -1)
    {
      if (my_strlen(opt + p) != 1)
	return (my_error_zero("-V, --val-delemiter value must be a \
single caracter.") - 2);
      data->opt_delim = (opt + p)[0];
      return (1);
    }
  return (-1);
}

int	mselect_option_parse(t_data *data, char *opt)
{
  int	r;

  if (my_strcmp(opt, "--") == 0)
    return (-3);
  if ((r = mselect_option_cols(data, opt)) != -1)
    return (r);
  if ((r = mselect_option_valdelim(data, opt)) != -1)
    return (r);
  return (-1);
}

int	mselect_load_options(t_data *data, int argc, char **argv)
{
  int	ignore;
  int	stop;
  int	i;
  int	r;

  ignore = 0;
  stop = 0;
  i = 0;
  while (i < argc && argv[i][0] == '-' && !stop)
    {
      if (my_strcmp(argv[i], "--help") == 0)
	return (-1);
      else
	{
	  r = mselect_option_parse(data, argv[i]);
	  if (r == -2)
	    return (-2);
	  if (r == -1 || r == -3)
	    stop = 1;
	  if (r != -1)
	    ignore++;
	  i++;
	}
    }
  return (ignore);
}
