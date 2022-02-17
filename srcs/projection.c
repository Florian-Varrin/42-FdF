/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:51:15 by fvarrin           #+#    #+#             */
/*   Updated: 2022/02/17 13:35:34 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

t_2dpoint	*create_2d_point(t_3dpoint *point_3d)
{
	int			x;
	int			y;
	int			z;
	t_2dpoint	*point_2d;

	point_2d = malloc(sizeof(t_2dpoint));
	x = point_3d->x;
	y = point_3d->y;
	z = point_3d->z;
	point_2d->x = (int)((x - z) / sqrt(2));
	point_2d->y = (int)((x + (2 * y) + z) / sqrt(6));
	return (point_2d);
}

void	update_boundaries(
			t_boundaries *boundaries,
			t_2dpoint *point,
			_Bool first_point
		)
{
	if (first_point || boundaries->max_x < point->x)
		boundaries->max_x = point->x;
	if (first_point || boundaries->min_x > point->x)
		boundaries->min_x = point->x;
	if (first_point || boundaries->max_y < point->y)
		boundaries->max_y = point->y;
	if (first_point || boundaries->min_y > point->y)
		boundaries->min_y = point->y;
}

void	resize_2d_points(t_list_el **lst_2d_points)
{
	t_boundaries	boundaries;
	t_list_el		*current_el;

	current_el = *lst_2d_points;
	update_boundaries(&boundaries, current_el->content, true);
	while (current_el)
	{
		update_boundaries(&boundaries, current_el->content, false);
		current_el = current_el->next;
	}
	current_el = *lst_2d_points;
	while (current_el)
	{
		current_el = current_el->next;
	}
}

t_list_el	**project_3d_to_isometric(
				t_list_el **lst_3d_points,
				t_list_el **lst_2d_points
			)
{
	t_2dpoint	*point_2d;
	t_list_el	*current_el;

	if (!lst_2d_points)
		return (NULL);
	current_el = *lst_3d_points;
	while (current_el)
	{
		point_2d = create_2d_point(current_el->content);
		ft_lstadd_back(lst_2d_points, ft_lstnew(point_2d));
		current_el = current_el->next;
	}
	resize_2d_points(lst_2d_points);
	return (lst_2d_points);
}
