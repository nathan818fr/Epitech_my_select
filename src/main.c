/*
** main.c for my_select in /home/poirie-n/blinux/poirie_n/repo/B1/Syst_Unix/PSU_2014_my_select
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Mon Jan  5 12:35:35 2015 Nathan Poirier
** Last update Sat Jan 10 15:42:35 2015 Nathan Poirier
*/

#include "my_select.h"

/*
** Function used to reset terminal, close tty file descriptor, free memory
** and exit the program.
*/
int		mselect_exit(t_data *data, char *err)
{
  int		failure;

  if (data->exit)
    return (0);
  data->exit = 1;
  failure = 0;
  mselect_term_cmd(data, TC_CLEAR);
  if (err != NULL)
    failure = my_error_zero(err) + 1;
  if (mselect_term_cmd(data, TC_CURSOR_VISIBLE) == -1)
    failure = my_error_zero("Unable to display cursor") + 1;
  if (mselect_term_reset(data) == -1)
    failure = my_error_zero("Unable to reset shell") + 1;
  close(data->tty_fd);
  mselect_free_list(data);
  if (failure)
    exit(EXIT_FAILURE);
  exit(EXIT_SUCCESS);
  return (-1);
}

/*
** Functions used to return data structure everywhere.
** Needed because we can't pass personal arguments to signal handlers
** and tputs.
*/
t_data		*mselect_get_data()
{
  static t_data	data;

  return (&data);
}

/*
** Main function: Load list, read arguments, initialize terminal (canonic
** mode), open tty and run program loop.
*/
int		main(int argc, char **argv, char **env)
{
  t_data	*data;
  int		argv_ignore;

  data = mselect_get_data();
  if (argc <= 1)
    return (mselect_print_usage(argc, argv));
  my_memset(data, 0, sizeof(t_data));
  data->opt_cols = 32;
  argv_ignore = mselect_load_options(data, argc - 1, argv + 1);
  if (argv_ignore == -1 || argc - 1 - argv_ignore <= 0)
    return (mselect_print_usage(argc, argv));
  if (argv_ignore == -2)
    return (1);
  if (mselect_term_init(data, env) == -1)
    return (my_error_zero("Unable to initialize shell") + 1);
  if (mselect_load_list(data, argc - 1 - argv_ignore,
			argv + 1 + argv_ignore) == -1)
    return (my_error_zero("Out of memory") + 1);
  mselect_loop(data);
  mselect_exit(data, NULL);
  return (0);
}
