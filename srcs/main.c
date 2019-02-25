/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 06:42:17 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/02/25 21:38:30 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int			main(int argc, char **argv)
{
	t_etra	*chain;
	char	**map;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (ft_check(fd, argc) < 1)
	{
		if (ft_check(fd, argc) == -1)
			ft_putstr_fd("usage: fillit target\n", 1);
		else
			ft_putstr_fd("error\n", 1);
		exit(1);
	}
	chain = reader(fd);
	if (!chain)
	{
		ft_putstr_fd("error\n", 1);
		exit(1);
	}
	letters_painter(chain);
	map = new_map(chain);
	worker(map, chain);
	out(map);
	return (0);
}
