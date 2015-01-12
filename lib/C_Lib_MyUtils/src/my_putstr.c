/*
** my_putstr.c for myutils in /home/poirie-n/blinux/poirie_n/repo/MyProjects/C_Lib_MyUtils
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Wed Dec 10 13:37:10 2014 Nathan Poirier
** Last update Wed Dec 10 13:52:11 2014 Nathan Poirier
*/

#include "myutils.h"

/*
** Write a string to the file referred to by the file descriptor fd.
**
** Return:
**  On success, the number of bytes written is returned.
**  On error, -1 is returned and errno is set appropriately.
**  If str is NULL, 0 is returned.
*/
size_t		my_putstr_to(int fd, char *str)
{
  if (str == NULL)
    return (0);
  return (write(fd, str, my_strlen(str)));
}

/*
** Write a string on standard output.
**
** Return:
**  On success, the number of bytes written is returned.
**  On error, -1 is returned and errno is set appropriately.
**  If str is NULL, 0 is returned.
*/
size_t		my_putstr(char *str)
{
  if (str == NULL)
    return (0);
  return (write(STDOUT_FILENO, str, my_strlen(str)));
}
