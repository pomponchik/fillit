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
				// printf("t\n");
    if (line && !ft_strlen(line))
    {
					// printf("1\n");
					lst_chain = ft_lst_turn(lst_chain);
						new = new_tetra(lst_chain);
						new_chain = add_tetra(new, new_chain);
      count = 0;
    }
    else if (line && ft_strlen(line))
    {
					// printf("str add: %s\n", line);
					temp = ft_strdup(line);
					free (line);
      lst = ft_lstnew(temp, ft_strlen(line));
      ft_lstadd(&lst_chain, lst);
						// printf("After: \n");
						//ft_lst_putendl(lst_chain);
						count++;
    }
  }
		// printf("QQ\n");
		//ft_lst_putendl(lst_chain);
		if (count)
		{
			//printf("o\n");
			// printf("QQ2\n");
			lst_chain = ft_lst_turn(lst_chain);
			ft_lst_putendl(lst_chain);
			//printf("len = %d", (int)ft_strlen(lst_chain->content));
			//ft_lst_putendl(lst_chain);
			// printf("QQ3\n");
			new = new_tetra(lst_chain);
			// if (!new)
			// 	printf("low\n");
			// printf("p\n");
			// printf("QQ4\n");
			new_chain = add_tetra(new, new_chain);
			// printf("v\n");
		}
		//printf("QQ\n");
		return (new_chain);
}

int main(int argc, char **argv)
{
	//printf("rrr");
	t_etra *chain;
	int fd = open(argv[1], O_RDONLY);
	// printf("fd = %d, argv = %s\n", fd, argv[1]);
	chain = reader(fd);
	if (!chain)
		printf("\nnot read\n");
	while (chain)
	{
		//printf("rrr");
		if (!(chain->str))
			printf("JJJ\n");
		if (!((chain->str)[0]))
			printf("HHH\n");
		//printf("str = %d\n", (int)ft_strlen((chain->str)[0]));
		//ft_print_two_dimensional_array(chain->str);
		chain = chain->next;
	}
	return 0;
}
