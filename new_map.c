/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 21:01:29 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/02/22 21:01:32 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static size_t ft_math_degree_size_t(size_t num, size_t index)
{
	size_t num_temp;

	if (!index)
		return (1);
	num_temp = num;
	while (index)
	{
		if (num * num_temp >= num)
			num *= num_temp;
		else
			return (0);
		index--;
	}
	return (num);
}

static size_t size_edge(t_etra *tets)
{
	size_t count;
	size_t edge;

	count = 0;
	while (tets)
	{
		count += 16;
		tets = tets->next;
	}
	edge = 2;
	while (ft_math_degree_size_t(edge, 2) < count)
	{
		edge++;
	}
	return (edge);
}

static char **x_generate(char **y, size_t edge)
{
	size_t index;
	size_t width;

	index = 0;
	width = edge;
	while (edge)
	{
		if (!(y[index] = (char *)malloc(width + 1)))
			return (NULL);
		y[index][width] = '\0';
		index++;
		edge--;
	}
	return (y);
}

char **new_map(t_etra *tets)
{
	size_t edge;
	char **y;
	size_t index;

	edge = size_edge(tets);
	if (!(y = (char **)malloc((edge + 1) * (sizeof(char *)))))
		return (NULL);
	y[edge] = NULL;
	if (!(y = x_generate(y, edge)))
		return (NULL);
	return (y);
}
