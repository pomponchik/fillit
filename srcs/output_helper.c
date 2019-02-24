/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 06:33:49 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/02/24 06:40:15 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

size_t			len_without_dot(char *str)
{
	size_t		index;

	index = 0;
	while (*str)
	{
		if (!search_not_dot(str))
			break ;
		index++;
		str++;
	}
	return (index);
}

int				search_not_dot(char *str)
{
	while (*str)
	{
		if (*str != '.')
			return (1);
		str++;
	}
	return (0);
}
