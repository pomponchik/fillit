/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 03:43:23 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/02/24 06:39:33 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static size_t	check_x(char **map)
{
	size_t		index;
	size_t		index_y;
	size_t		temp;

	index = 0;
	index_y = 0;
	while (map[index_y])
	{
		if ((temp = len_without_dot(map[index_y])))
		{
			if (temp > index)
				index = temp;
		}
		else
			break ;
		index_y++;
	}
	return (index);
}

static size_t	check_y(char **map)
{
	size_t		index;

	index = 0;
	while (search_not_dot(map[index]))
		index++;
	return (index);
}

static size_t	x_or_y(size_t x, size_t y)
{
	if (x > y)
		return (x);
	return (y);
}

void			out(char **map)
{
	size_t		size;
	size_t		index_x;
	size_t		index_y;

	size = x_or_y(check_x(map), check_y(map));
	index_y = 0;
	while (index_y < size)
	{
		index_x = 0;
		while (index_x < size)
		{
			ft_putchar(map[index_y][index_x]);
			index_x++;
		}
		index_y++;
		ft_putchar('\n');
	}
}
