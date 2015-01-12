/*
** my_putchar.c for myutils in /home/poirie-n/blinux/poirie_n/repo/MyProjects/C_Lib_MyUtils
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Wed Dec 10 13:16:34 2014 Nathan Poirier
** Last update Wed Dec 10 13:49:06 2014 Nathan Poirier
*/

#include "myutils.h"

/*
** Write a single character to the file referred to by the file descriptor fd.
** 
** Return:
**  On success, the number of bytes written is returned.
**  On error, -1 is returned and errno is set appropriately.
*/
ssize_t	my_putchar_to(int fd, char c)
{
  return (write(fd, &c, 1));
}

/*
** Write a single character on standard output.
**
** Return:
**  On success, the number of bytes written is returned.
**  On error, -1 is returned and errno is set appropriately.
*/
ssize_t	my_putchar(char c)
{
  return (write(STDOUT_FILENO, &c, 1));
}
