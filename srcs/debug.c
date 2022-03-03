/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:20:40 by fvarrin           #+#    #+#             */
/*   Updated: 2022/03/03 14:29:33 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

#include <stdio.h>

void	print_2d_point(void *content)
{
	t_2dpoint	*point;

	point = content;
	printf("(%f, %f)\n", point->x, point->y);
}

void	print_3d_point(void *content)
{
	t_3dpoint	*point;

	point = content;
	printf("(%f, %f, %f)\n", point->x, point->y, point->z);
}

void	print_3d_points(t_list_el **lst)
{
	t_list_el		*current_el;

	current_el = *lst;
	while (current_el)
	{
		print_3d_point(current_el->content);
		current_el = current_el->next;
	}
}

void	print_matrix(double matrix[3][3], char *message)
{
	printf("%s\n", message);
	printf("[\n");
	printf("  [%f, %f, %f],\n", matrix[0][0], matrix[0][1], matrix[0][2]);
	printf("  [%f, %f, %f],\n", matrix[1][0], matrix[1][1], matrix[1][2]);
	printf("  [%f, %f, %f]\n", matrix[2][0], matrix[2][1], matrix[2][2]);
	printf("]\n");
}

void	print_boundaries(t_boundaries *boundaries)
{
	ft_printf("x ==> %d - %d\n", boundaries->min_x, boundaries->max_x);
	ft_printf("y ==> %d - %d'\n", boundaries->min_y, boundaries->max_y);
}

void	print_map(t_map *map)
{
	ft_printf("line_size %d\n", map->line_size);
	ft_printf("number_of_points %d\n", map->number_of_points);
}
