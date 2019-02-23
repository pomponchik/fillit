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

// static float		rooter(float num, unsigned int root_index)
// {
// 	float		num_temp;
//
// 	num_temp = num;
// 	while (root_index != 1)
// 	{
// 		num *= num_temp;
// 		root_index--;
// 	}
// 	return (num);
// }
//

static size_t ft_math_degree_size_t(size_t num, size_t index)
{
	size_t num_temp;

	if (!index)
		return (1);
	num_temp = num;
	while (index != 1)
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
	if (!tets)
		printf("oh...\n");
	while (tets)
	{
		printf("loop\n");
		count += 16;
		tets = tets->next;
	}
	edge = 2;
	printf("root: %lu\n", ft_math_degree_size_t(edge, 2));
	printf("count: %lu\n", count);
	while (ft_math_degree_size_t(edge, 2) < count)
	{
		printf("++\n");
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
		ft_memset(y[index], '.', width);
		index++;
		edge--;
	}
	return (y);
}

char **new_map(t_etra *tets)
{
	size_t edge;
	char **y;

	edge = size_edge(tets) + 1;
	if (!tets)
		printf("!tets\n");
	printf("edge size: %lu\n", edge);
	if (!(y = (char **)malloc((edge + 1) * (sizeof(char *)))))
		return (NULL);
	y[edge] = NULL;
	if (!(y = x_generate(y, edge)))
		return (NULL);
	printf("map:\n");
	priuuu(y);
	printf("map end\n");
	return (y);
}
