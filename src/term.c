/*
** term.c for my_select in /home/poirie-n/blinux/poirie_n/repo/B1/Syst_Unix/PSU_2014_my_select
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Mon Jan  5 19:03:11 2015 Nathan Poirier
** Last update Sun Jan 11 17:36:23 2015 Nathan Poirier
*/

#include "my_select.h"

void	mselect_term_sighandler(int sid)
{
  if (sid == SIGINT)
    mselect_exit(mselect_get_data(), NULL);
  else if (sid == SIGWINCH)
    {
      if (signal(SIGWINCH, &mselect_term_sighandler) == SIG_ERR)
	mselect_exit(mselect_get_data(), "Unable to handle SIGWINCH signal.");
    }
}

int	mselect_term_init(t_data *data, char **env)
{
  char	*term_name;

  if ((data->tty_fd = open("/dev/tty", O_RDWR | O_NOCTTY | O_SYNC)) == -1)
    return (-1);
  if (signal(SIGWINCH, &mselect_term_sighandler) == SIG_ERR ||
      signal(SIGINT, &mselect_term_sighandler) == SIG_ERR)
    return (-1);
  if ((term_name = my_getenv(env, "TERM")) == NULL)
    {
      my_warn("Environment variable 'TERM' don't exists. Try with: TERM=xterm");
      term_name = "xterm";
    }
  if (tgetent(NULL, term_name) == ERR)
    return (-1);
  if (tcgetattr(0, &(data->term)) == -1)
    return (-1);
  data->term.c_lflag &= ~(ICANON);
  data->term.c_lflag &= ~(ECHO);
  data->term.c_cc[VMIN] = 1;
  data->term.c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSADRAIN, &(data->term)) == -1)
    return (-1);
  return (0);
}

int	mselect_term_reset(t_data *data)
{
  if (tcgetattr(0, &(data->term)) == -1)
    return (-1);
  data->term.c_lflag = (ICANON | ECHO);
  if (tcsetattr(0, 0, &(data->term)) == -1)
    return (-1);
  return (0);
}

int	mselect_term_putc(int c)
{
  mselect_putchar(mselect_get_data(), c);
  return (0);
}

int	mselect_term_cmd(t_data *data, char *cmd)
{
  char	*res;

  if ((res = tgetstr(cmd, NULL)) == NULL)
    return (mselect_exit(data, "Runtime error: tgetstr"));
  tputs(res, 0, mselect_term_putc);
  return (0);
}
