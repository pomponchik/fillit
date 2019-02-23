/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proves.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 05:34:23 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/02/20 05:38:34 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static int	letters_prove(t_list *lst) //проверка, что в тетраминках только нужные символы
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

static int	number_lattice_prove(t_list *lst) //проверка, что количество решеток равно 4
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

static int	width_and_height_lst_prove(t_list *lst) //проверка, что считанное поле тетраминки ровно 4х4
{
	size_t	width_counter;
	size_t	height_counter;

	//printf("return: %lu, %lu", width_counter, height_counter);
	if (!lst)
		return (0);
	//printf("return: %lu, %lu", width_counter, height_counter);
	height_counter = 0;
	// printf("width 1\n");
	while (lst)
	{
		// printf("width 2\n");
		width_counter = ft_strlen(lst->content);
		//printf("width 3, counter = %d, <str = %s>\n", (int)width_counter, (char *)(lst->content));
		if (width_counter != 4 || height_counter >= 5)
			return (0);
		// printf("width 4\n");
		height_counter++;
		// printf("width 5\n");
		lst = lst->next;
		// printf("width 6\n");
	}
	//printf("return: %lu, %lu", width_counter, height_counter);
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
