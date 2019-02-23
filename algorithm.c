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

int square_prove(t_put squad, t_etra *tet)
{
	if (squad.size < squad.x + tet->width + 1)
		return (0);
	if (squad.size < squad.y + tet->height + 1)
		return (0);
	return (1);
}

void clear_square(char **map, t_etra	*tets, t_put put)
{
	char **figure;
	char *line;
	size_t ys;
	size_t xs;

	figure = tets->str;
	ys = 0;
	while(*figure)
	{
		line = *figure;
		xs = 0;
		while (*line)
		{
			if (map[put.y + ys][put.x + xs] == tets->letter)
				map[put.y + ys][put.x + xs] = '.';
			xs++;
			line++;
		}
		ys++;
		figure++;
	}
}

int try_to_put(char **map, t_etra	*tets, t_put put)
{
	char **figure;
	char *line;
	size_t ys;
	size_t xs;
	//Сначала место под фигуру и проверить, что все нужные клетки свободны
	//если все ок, ставим фигуру и возвращаем 0
	if (!square_prove(put, tets))
		return (0);
	figure = tets->str;

	ys = 0;
	while(*figure)
	{
		line = *figure;
		xs = 0;
		while (*line)
		{
			if (*line != '.' && map[put.y + ys][put.x + xs] == '.')
				map[put.y + ys][put.x + xs] = tets->letter;
			else if (*line != '.' && map[put.y + ys][put.x + xs] != '.')
			{
				clear_square(map, tets, put);
				return (0);
			}
			xs++;
			line++;
		}
		ys++;
		figure++;
	}
	return (1);



















	// figure = tets->str;
	//
	// ys = 0;
	// while(*figure && ys <= put.y)
	// {
	// 	line = *figure;
	// 	xs = 0;
	// 	while (*line && xs <= put.x)
	// 	{
	// 		if ()
	// 		xs++;
	// 		line++;
	// 	}
	// 	ys++;
	// 	figure++;
	// }
}

int algorithm(char **map, t_etra	*tets, size_t size)
{
	t_put i;

	i.y = 0;
	i.size = size;

	if (!tets)
		return (1);
	while (i.y < (size - 1))
	{
		i.x = 0;
		while (i.x + 1 < i.size)
		{
			if (try_to_put(map, tets, i) && algorithm(map, tets->next, size))
				return (1);
			else
			{
				clear_square(map, tets, i);
			}
			i.x++;
		}
		i.y++;
	}
	return (0);
}

void worker(char **map, t_etra	*tets)
{
	size_t size;

	size = 2;
	while (!algorithm(map, tets, size))
		size++;
}
