/*
** myutils_printf.h for myutils in /home/poirie-n/blinux/poirie_n/repo/MyProjects/C_Lib_MyUtils/include
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Sun Dec 14 15:58:24 2014 Nathan Poirier
** Last update Fri Jan  9 11:15:09 2015 Nathan Poirier
*/

#ifndef MYUTILS_PRINTF_H_
# define MYUTILS_PRINTF_H_

# include <stdarg.h>
# include <stdlib.h>

# define MYUTILS_PRINTF_FLAGS 4

typedef int	(*t_printf_func)(void *pf, va_list ap);

typedef	struct	s_my_printf
{
  char		*tab_flag;
  t_printf_func	*tab_func;
  int		fd;
  char		*str;
  int		printed;
}		t_my_printf;

int	my_printf(const char *format, ...);
int	my_fprintf(int fd, const char *format, ...);
int	my_sprintf(char *str, const char *format, ...);
int	my_vprintf(const char *format, va_list ap);
int	my_vfprintf(int fd, const char *format, va_list ap);
int	my_vsprintf(char *str, const char *format, va_list ap);

int	_my_printf(int fd, char *str, const char *format, va_list ap);
void	_my_printf_exec(t_my_printf *pf, const char *format,
			va_list ap, int i);

int	_my_printf_putchar_at(t_my_printf *pf, char c, int pos);
int	_my_printf_putchar(t_my_printf *pf, char c);
int	_my_printf_putstr(t_my_printf *pf, char *str);

int     _my_printf_flag_perc(t_my_printf *arg, va_list ap);
int     _my_printf_flag_c(t_my_printf *arg, va_list ap);
int     _my_printf_flag_s(t_my_printf *arg, va_list ap);
int	_my_printf_flag_d(t_my_printf *arg, va_list ap);

#endif /* !MYUTILS_PRINTF_H_ */
