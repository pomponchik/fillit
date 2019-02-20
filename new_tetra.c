/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tetra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 01:09:24 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/02/20 08:50:44 by ahalmon-         ###   ########.fr       */
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

void print_size_t(size_t *i)
{
	int index;

	index = 0;
	while (index != 4)
	{
		printf("%lu", i[index]);
		index++;
	}
	printf("\n");
}

int tetra_indent(size_t *arr)
{
	int index;

	index = 0;
	while (!arr[index])
		index++;
	return (index);
}

void priuuu(char **str)
{
	int index = 0;

	while (str[index])
	{
		printf("%s\n", str[index]);
		index++;
	}
}

static void		tetra_copy(t_etra *new, size_t *x_s, size_t *y_s, t_list *lst)
{
	size_t		index_y;
	size_t		index_x;
	char		**stri;
	size_t x_count;
	size_t y_count;

	index_y = 0; //new_tetra_number(x_s)
	y_count = 0;
	//printf("tetra_copy 1\n");
	stri = new->str;
	//printf("tetra_copy 2\n");
ft_lst_putendl(lst);
printf("\n");
print_size_t(x_s);
print_size_t(y_s);

while (lst)
{
	if (y_s[index_y])
	{
		index_x = 0;
		while (index_x < 4)
		{
			if (x_s[index_x])
				stri[y_count][index_x - tetra_indent(x_s)] = ((char *)(lst->content))[index_x];
			index_x++;
		}
		y_count++;
	}
	index_y++;
	lst = lst->next;
}
priuuu(stri);


//
//
// while (index_y != 4)
// {
// 	if (y_s[index_y])
// 	{
// 		index_x = 0;
//
// 		while (index_x != 4)
// 		{
// 			x_count = 0;
// 			if (x_s[index_x])
// 			{
// 				stri[y_count][x_count] = ((char *)(lst->content))[index_x];
// 				x_count++;
// 			}
// 			index_x++;
// 		}
// 		y_count++;
// 		lst=lst->next;
// 	}
// 	index_y++;
// }
//






	// while (index_y != 4)
	// {
	// 	//printf("tetra_copy while\n");
	// 	if (y_s[index_y] && y_count)
	// 	{
	// 		//printf("tetra_copy if\n");
	//
	// 		index_x = 0;
	// 		y_count--;
	// 		while (index_x != 4)
	// 		{
	// 			printf("tetra_copy while 2, %lu\n", index_x);
	//
	// 			if (x_s[index_x] && x_count)
	// 			{
	// 				printf("if 2, x = %d, y = %d\n", (int)index_x, (int)index_y);
	// 				stri[index_y][index_x] = ((char *)(lst->content))[index_x];
	// 				x_count--;
	// 			}
	// 			index_x++;
	// 		}
	// 	}
	// 	index_y++;
	// 	lst = lst->next;
	// }
	printf("result\n");
	//ft_print_two_dimensional_array(new->str);
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
