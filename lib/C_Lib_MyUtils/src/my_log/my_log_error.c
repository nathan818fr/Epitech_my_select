/*
** my_log_error.c for myutils in /home/poirie-n/blinux/poirie_n/repo/MyProjects/C_Lib_MyUtils/src/my_log
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Mon Dec 15 17:13:56 2014 Nathan Poirier
** Last update Mon Dec 15 17:16:35 2014 Nathan Poirier
*/

#include "myutils_log.h"
#include "myutils.h"

void		my_error(char *msg, ...)
{
  va_list	ap;

  va_start(ap, msg);
  _my_log_exec(MY_LOG_ERROR, msg, ap);
  va_end(ap);
}

int		my_error_zero(char *msg, ...)
{
  va_list	ap;

  va_start(ap, msg);
  _my_log_exec(MY_LOG_ERROR, msg, ap);
  va_end(ap);
  return (0);
}

void		*my_error_null(char *msg, ...)
{
  va_list	ap;

  va_start(ap, msg);
  _my_log_exec(MY_LOG_ERROR, msg, ap);
  va_end(ap);
  return (NULL);
}
