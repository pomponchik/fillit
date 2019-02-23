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

	count = 0;
	printf("x: %lu, y: %lu\n", x, y);
	if (y)
		count += str_links_prove(ft_lstsearch_index(lst, (y - 1)), x);
	if (y != 3)
		count += str_links_prove(ft_lstsearch_index(lst, (y + 1)), x);
	if (x)
		count += str_links_prove(ft_lstsearch_index(lst, y), (x - 1));
	if (x != 3)
		count += str_links_prove(ft_lstsearch_index(lst, y), (x + 1));
	if (count)
		return (1);
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
					return (0);
			}
			x++;
		}
		y++;
		temp = temp->next;
	}
	return (1);
}
