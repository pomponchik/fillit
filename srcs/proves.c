/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proves.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 05:34:23 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/02/25 21:47:11 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static int	letters_prove(t_list *lst)
{
	char	*str;
	size_t	index;

	while (lst)
	{
		str = lst->content;
		index = 0;
		while (str[index])
		{
			if (str[index] == '.' || str[index] == '#')
				index++;
			else
				return (0);
		}
		lst = lst->next;
	}
	return (1);
}

static int	number_lattice_prove(t_list *lst)
{
	size_t index;

	index = 0;
	while (lst)
	{
		index += ft_numch(lst->content, '#');
		lst = lst->next;
	}
	if (index != 4)
		return (0);
	return (1);
}

static int	width_and_height_lst_prove(t_list *lst)
{
	size_t	width_counter;
	size_t	height_counter;

	if (!lst)
		return (0);
	height_counter = 0;
	while (lst)
	{
		width_counter = ft_strlen(lst->content);
		height_counter++;
		if (width_counter != 4)
			return (0);
		lst = lst->next;
	}
	if (height_counter != 4)
		return (0);
	return (1);
}

int			proves(t_list *chain)
{
	if (!width_and_height_lst_prove(chain))
		return (0);
	if (!number_lattice_prove(chain))
		return (0);
	if (!letters_prove(chain))
		return (0);
	if (!links_prove(chain))
		return (0);
	return (1);
}
