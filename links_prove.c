/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links_prove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 05:50:11 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/02/20 06:24:48 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static int	str_links_prove(t_list *lst, size_t x)
{
	char	*str;

	str = (char *)lst->content;
	if (str[x] == '#')
		return (1);
	return (0);
}

static int	links_prove_helper(t_list *lst, size_t x, size_t y)
{
	size_t	count;

	//printf("lph, x = %d, y = %d\n", (int)x, (int)y);
	count = 0;
	if (y)
		count += str_links_prove(ft_lstsearch_index(lst, (y - 1)), x);
	// printf("ou1\n");
	if (y != 3)
	{
		// printf("count = %d, x = %d, y = %d\n", (int)count, (int)x, (int)y + 1);
		//
		// t_list *temp = ft_lstsearch_index(lst, (y + 1));
		// if (!(temp))
		// 	printf("taks\n");
		// printf("ok, str = %s\n", (char *)(temp->content));
		count += str_links_prove(ft_lstsearch_index(lst, (y + 1)), x);

	}
	//printf("ou2\n");
	if (x)
		count += str_links_prove(ft_lstsearch_index(lst, y), (x - 1));
	// printf("ou3\n");
	if (x != 3)
		count += str_links_prove(ft_lstsearch_index(lst, y), (x + 1));
	// printf("ou4\n");
	if (count)
		return (1);
	// printf("ou\n");
	return (0);
}

int			links_prove(t_list *lst)
{
	size_t	x;
	size_t	y;
	t_list	*temp;

	y = 0;
	temp = lst;
	while (y != 4)
	{
		x = 0;
		while (x != 4)
		{
			if (((char *)(temp->content))[x] == '#')
			{
				if (!links_prove_helper(lst, x, y))
				{
					return (0);
				}
			}
			x++;
		}
		y++;
		// printf("end, y = %d\n", (int)y);
		temp = temp->next;
		// if (!temp)
		// 	printf("error\n");
	}
	return (1);
}
