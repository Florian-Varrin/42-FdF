/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:20:40 by fvarrin           #+#    #+#             */
/*   Updated: 2022/02/17 13:36:09 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

void	print_2d_point(void *content)
{
	t_2dpoint	*point;

	point = content;
	ft_printf("(%d, %d)\n", point->x, point->y);
}

void	print_3d_point(void *content)
{
	t_3dpoint	*point;

	point = content;
	ft_printf("(%d, %d, %d)\n", point->x, point->y, point->z);
}

void	print_boundaries(t_boundaries *boundaries)
{
	ft_printf("x ==> %d - %d\n", boundaries->min_x, boundaries->max_x);
	ft_printf("y ==> %d - %d'\n", boundaries->min_y, boundaries->max_y);
}
