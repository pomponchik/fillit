/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:31:05 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/02/24 15:18:03 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		ft_check(int fd, int argc)
{
	if (argc != 2 || fd <= 0)
		return (-1);
	if (read(fd, NULL, 1) == 0)
		return (0);
	close(fd);
	return (1);
}

void	paint_symb(char **figure, char letter)
{
	char	**y;
	char	*x;

	y = figure;
	while (*y)
	{
		x = y[0];
		while (*x)
		{
			if (*x == '#')
				*x = letter;
			x++;
		}
		y++;
	}
}
