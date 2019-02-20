/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 21:47:18 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/02/19 21:47:20 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include <stdio.h>





t_list *reader(int fd)
{
  char *line;
  int r;
  int count;
  t_list *lst;
  t_list *lst_chain;

  count = 0;
  line = NULL;
  lst_chain = NULL;
  while ((r = get_next_line(fd, char &line)))
  {
    if (line && !ft_strlen(line))
    {

      count = 0;
    }
    else if (line && ft_strlen(line))
    {
      lst = ft_lstnew(line, ft_strlen(line));
      ft_lstadd(&lst_chain, lst);
    }
  }
}

//ft_lst_iter(lst)

int main()
{
  printf("%d", letter_prove("...."));
  return 0;
}
