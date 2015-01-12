/*
** help.c for my_select in /home/poirie-n/blinux/poirie_n/repo/B1/Syst_Unix/PSU_2014_my_select
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Mon Jan  5 14:33:30 2015 Nathan Poirier
** Last update Sun Jan 11 15:41:00 2015 Nathan Poirier
*/

#include "my_select.h"

void	mselect_print_usage_additional()
{
  my_putstr("\n");
  my_putstr("Selection can be reverted with tab.\n");
  my_putstr("PageUp/PageDown jump cursor at first/last element.\n");
  my_putstr("Ctrl-A select/deselect all elements.\n");
  my_putstr("You can search dynamically by typping letter or word at all ");
  my_putstr("times.\n");
}

int	mselect_print_usage(int argc, char **argv)
{
  char	*program;

  program = (argc > 0) ? argv[0] : "./PROGRAM";
  my_putstr(my_strjoin("Usage: ", program, " [OPTION]... [ELEMENT]...\n\n"));
  my_putstr("Display an interactive list of ELEMENTs.\n");
  my_putstr("Can move with arrows and select ELEMENTs with space.\n");
  my_putstr("Value of selected ELEMENTs are returned on STDOUT when pressing");
  my_putstr(" enter.\nCtrl-D or escape can be used to exit the program.\n");
  mselect_print_usage_additional();
  my_putstr("\n");
  my_putstr("  -C, --col-width=COLS        set maximum column width to");
  my_putstr(" COLS (default: 32)\n");
  my_putstr("                              too large elements will be");
  my_putstr(" trimmed\n");
  my_putstr("  -V, --val-delemiter=DELIM   use DELIM as value delimiter\n");
  my_putstr("                              element is separated in two part");
  my_putstr(" by DELIM, first\n");
  my_putstr("                              is displayed and second is the");
  my_putstr(" returned value\n");
  my_putstr("                              if DELIM is not present, value ");
  my_putstr("and element are\n                              the same ");
  my_putstr("(default: no delimiter)\n");
  my_putstr("      --help                  display this help and exit\n");
  my_putstr("\nAuthor: Nathan Poirier <nathan@poirier.io>\n");
  return (0);
}

int	mselect_print_resizeinfo(t_data *data)
{
  char	*alert;
  int	i;

  alert = "Please expand the window.";
  mselect_putstr(data, BASH_BG_RED);
  mselect_putstr(data, alert);
  i = my_strlen(alert);
  while (i < data->win_width * data->win_height)
    {
      mselect_putchar(data, ' ');
      i++;
    }
  mselect_putstr(data, BASH_BG_RESET);
  return (-1);
}
