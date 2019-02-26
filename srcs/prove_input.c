/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prove_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 05:34:07 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/02/26 06:04:05 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int			is_it_empty_file(char *file_name)
{
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd <= 0)
	{
		ft_putstr("usage: fillit target\n");
		close(fd);
		return (0);
	}
	if (!read(fd, NULL, 1))
	{
		ft_putstr("error\n");
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
