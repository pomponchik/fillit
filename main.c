/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 06:42:17 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/02/24 06:48:31 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int			main(int argc, char **argv)
{
	t_etra	*chain;
	char	**map;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	chain = reader(fd);
	letters_painter(chain);
	map = new_map(chain);
	worker(map, chain);
	out(map);
	return (0);
}
