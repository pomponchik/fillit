/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 22:43:13 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/02/22 22:43:18 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

typedef struct			s_puter
{
	size_t x;
	size_t y;
	size_t size;
}						t_put;

int size_prove(t_put squad, t_etra *tet)
{
	if (squad.size < squad.x + tet->width + 1)
		return (0);
	if (squad.size < squad.y + tet->height + 1)
		return (0);
	return (1);
}



int try_to_put(char **map, t_etra	*tets, t_put put)
{
	char **figure;
	char *line;
	//Сначала место под фигуру и проверить, что все нужные клетки свободны
	//если все ок, ставим фигуру и возвращаем 0
	figure = tets->str;
	while(*figure)
	{
		line = *figure;
		while (*line)
		{
			if ()
			line++;
		}
		put.y++;
		figure++;
	}
}

int algorithm(char **map, t_etra	*tets, size_t size)
{
	t_put i;

	i.y = 0;
	i.size = size;

	if (!tets)
		return (1);
	while (y < (size - 1))
	{
		i.x = 0;
		while (i.x + 1 < i.size)
		{
			if (size_prove(i, tets) && try_to_put)
			{
				;
				if (algorithm(map, tets->next, size))
					return (1);
			}
			i.x++;
		}
		y++;
	}
}
