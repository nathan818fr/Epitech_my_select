/*
** my_log.c for myutils in /home/poirie-n/blinux/poirie_n/repo/MyProjects/C_Lib_MyUtils/src/my_log
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Mon Dec 15 15:33:57 2014 Nathan Poirier
** Last update Sun Dec 21 16:18:50 2014 Nathan Poirier
*/

#include <stdlib.h>
#include "myutils_printf.h"
#include "myutils_log.h"
#include "myutils.h"

char	*_my_log_get_prefix(t_my_logtype type)
{
  if (type == MY_LOG_TRACE)
    return ("Trace");
  if (type == MY_LOG_DEBUG)
    return ("Debug");
  if (type == MY_LOG_INFO)
    return ("Info");
  if (type == MY_LOG_WARN)
    return ("Warning");
  if (type == MY_LOG_ERROR)
    return ("Error");
  if (type == MY_LOG_FATAL)
    return ("Fatal Error");
  return ("?");
}

int	_my_log_fatal()
{
  my_putstr_to(STDERR_FILENO, "\n*** Fatal Error: An error has occurred while\
displaying a log message. This may come from a lack of memory. ***\n");
  return (-1);
}

int	_my_log_exec(t_my_logtype type, char *msg, va_list ap)
{
  char	*format;

  if (MYUTILS_OPT_PROGRAMNAME != NULL)
    format = my_strjoin(MYUTILS_OPT_PROGRAMNAME, ": ",
			_my_log_get_prefix(type), ": ", msg, "\n");
  else
    format = my_strjoin(_my_log_get_prefix(type), ": ", msg, "\n");
  if (format == NULL)
    return (_my_log_fatal());
  if (my_vfprintf(STDERR_FILENO, format, ap) == -1)
    return (_my_log_fatal());
  free(format);
  return (0);
}

void		my_log(t_my_logtype type, char *msg, ...)
{
  va_list	ap;

  va_start(ap, msg);
  _my_log_exec(type, msg, ap);
  va_end(ap);
}
