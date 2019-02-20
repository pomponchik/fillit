/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 21:47:02 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/02/19 21:47:06 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

typedef struct			s_tetr
{
	char **str;
	size_t height;
 size_t width;
	char letter;
	struct s_tetr		*next;
}						t_etra;

int links_prove(t_list *lst);
int			proves(t_list *chain);
t_etra *new_tetra(t_list *chain);

size_t		new_tetra_number(size_t *s);
t_etra		*create_tetra(size_t x, size_t y);
t_etra		*add_tetra(t_etra *new, t_etra *old);
