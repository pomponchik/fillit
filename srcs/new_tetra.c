/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tetra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 01:09:24 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/02/24 06:26:08 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static void		horizontal_lst_check(t_list *lst, size_t *y_s)
{
	size_t		index;

	index = 0;
	while (lst)
	{
		if (ft_strchr(lst->content, '#'))
			y_s[index] = 1;
		index++;
		lst = lst->next;
	}
}

static int		vertical_lst_check(t_list *lst, size_t index)
{
	while (lst)
	{
		if (((char *)(lst->content))[index] == '#')
			return (1);
		lst = lst->next;
	}
	return (0);
}

static void		new_tetra_count_lines(t_list *lst, size_t *x_s, size_t *y_s)
{
	size_t		index;

	index = 0;
	ft_bzero(x_s, sizeof(size_t) * 4);
	ft_bzero(y_s, sizeof(size_t) * 4);
	while (index != 4)
	{
		if (vertical_lst_check(lst, index))
			x_s[index] = 1;
		index++;
	}
	horizontal_lst_check(lst, y_s);
}

static void		tetra_copy(t_etra *new, size_t *x_s, size_t *y_s, t_list *lst)
{
	size_t		index_y;
	size_t		i_x;
	char		**st;
	size_t		y_c;

	index_y = 0;
	y_c = 0;
	st = new->str;
	while (lst)
	{
		if (y_s[index_y])
		{
			i_x = 0;
			while (i_x < 4)
			{
				if (x_s[i_x])
					st[y_c][i_x - t_in(x_s)] = ((char *)(lst->content))[i_x];
				i_x++;
			}
			y_c++;
		}
		index_y++;
		lst = lst->next;
	}
}

t_etra			*new_tetra(t_list *lst)
{
	t_etra		*new;
	size_t		x_s[4];
	size_t		y_s[4];

	if (!proves(lst))
		return (NULL);
	new_tetra_count_lines(lst, x_s, y_s);
	if (!(new = create_tetra(new_tetra_number(x_s), new_tetra_number(y_s))))
		return (NULL);
	tetra_copy(new, x_s, y_s, lst);
	new->next = NULL;
	return (new);
}
