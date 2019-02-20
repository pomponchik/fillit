/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tetra_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 06:58:55 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/02/20 07:16:40 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

size_t		new_tetra_number(size_t *s)
{
	size_t	index;
	size_t	count;

	index = 0;
	count = 0;
	while (index != 4)
	{
		if (s[index])
			count++;
		index++;
	}
	return (count);
}

t_etra		*create_tetra(size_t x, size_t y)
{
	t_etra	*new;
	size_t	index;

	if (!(new = (t_etra *)malloc(sizeof(t_etra))))
		return (NULL);
	new->height = y;
	new->width = x;
	if (!(new->str = (char **)malloc(sizeof(char *) * (y + 1))))
	{
		free(new);
		return (NULL);
	}
	(new->str)[y] = NULL;
	index = 0;
	while (index != y)
	{
		if (!((new->str)[index] = ft_strnew(x + 1)))
		{
			free(new->str);
			free(new);
			return (NULL);
		}
		index++;
	}
	return (new);
}

t_etra		*add_tetra(t_etra *new, t_etra *old)
{
	t_etra *end;

	end = old;
	if (!old)
	{
		// printf("add\n");
		return (new);
	}
	while (end)
	{
		// printf("add\n");
		if (!end->next)
			break ;
		// printf("add\n");
		end = end->next;
	}
	// printf("add\n");
	end->next = new;
	return (old);
}
