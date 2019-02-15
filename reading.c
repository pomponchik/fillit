#include <stdio.h>

int letter_prove(char *str)
{
  while(*str)
  {
    if (*str == '.' || *str == '#')
      str++;
    else
      return (0);
  }
  return (1);
}

ft_lst_iter(lst)
