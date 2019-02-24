/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 21:47:18 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/02/24 07:06:27 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void		paint_symb(char **figure, char letter)
{
	char		**y;
	char		*x;

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

static void		read_nuller_begin(t_read *i)
{
	i->lst_chain = NULL;
	i->lst = NULL;
	i->count = 0;
	i->line = NULL;
	i->new_chain = NULL;
	i->work_indicate = 0;
}

static void		read_nuller(t_read *i)
{
	i->lst_chain = NULL;
	i->lst = NULL;
	i->count = 0;
}

static void		read_helper(t_read *i)
{
	i->temp = ft_strdup(i->line);
	free(i->line);
	i->lst = ft_lstnew(i->temp, ft_strlen(i->temp));
	ft_lstadd(&(i->lst_chain), i->lst);
	i->count++;
}

static int		read_helper_2(t_read *i)
{
	if (!proves(i->lst_chain))
		return (0);
	i->lst_chain = ft_lst_turn(i->lst_chain);
	i->new = new_tetra(i->lst_chain);
	i->new_chain = add_tetra(i->new, i->new_chain);
	ft_lst_free_chain(i->lst_chain);
	read_nuller(i);
	return (1);
}

t_etra			*reader(int fd)
{
	t_read		i;

	read_nuller_begin(&i);
	while ((i.in = get_next_line(fd, &(i.line))) > 0)
	{
		if (i.line && !ft_strlen(i.line))
		{
			if (!read_helper_2(&i))
				return (NULL);
		}
		else if (i.line && ft_strlen(i.line))
			read_helper(&i);
	}
	if (!ft_strlen(i.line))
		return (NULL);
	if (i.count)
	{
		if (!proves(i.lst_chain))
			return (0);
		i.lst_chain = ft_lst_turn(i.lst_chain);
		i.new = new_tetra(i.lst_chain);
		i.new_chain = add_tetra(i.new, i.new_chain);
	}
	return (i.new_chain);
}
