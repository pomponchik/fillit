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


void priuuu(char **str)
{
	int index = 0;

	while (str[index])
	{
		printf("%s\n", str[index]);
		index++;
	}
}

t_etra *reader(int fd)
{
  char *line;
  int in;
  int count;
  t_list *lst;
  t_list *lst_chain;
		t_etra *new;
		t_etra *new_chain;
		char *temp;

  count = 0;
  line = NULL;
  lst_chain = NULL;
		new_chain = NULL;
  while ((in = get_next_line(fd, &line)) > 0)
  {
    if (line && !ft_strlen(line))
    {
					lst_chain = ft_lst_turn(lst_chain);
					new = new_tetra(lst_chain);
					new_chain = add_tetra(new, new_chain);
     count = 0;
					ft_lst_free_chain(lst_chain);
					lst_chain = NULL;
					lst = NULL;
    }
    else if (line && ft_strlen(line))
    {
					temp = ft_strdup(line);
					free (line);
     lst = ft_lstnew(temp, ft_strlen(temp));
     ft_lstadd(&lst_chain, lst);
					count++;
    }
  }
		if (count)
		{
			lst_chain = ft_lst_turn(lst_chain);
			new = new_tetra(lst_chain);
			new_chain = add_tetra(new, new_chain);
		}
		return (new_chain);
}

int main(int argc, char **argv)
{
	t_etra *chain;
	int fd = open(argv[1], O_RDONLY);
	chain = reader(fd);
	if (!chain)
		printf("\nnot read\n");
	while (chain)
	{
		priuuu(chain->str);
		printf("\n");
		if (!(chain->str))
			printf("JJJ\n");
		if (!((chain->str)[0]))
			printf("HHH\n");
		chain = chain->next;
	}
	return 0;
}
