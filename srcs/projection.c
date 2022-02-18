/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:51:15 by fvarrin           #+#    #+#             */
/*   Updated: 2022/02/18 10:47:47 by                  ###   ########.fr       */
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

void	move_2d_points(t_list_el **lst_2d_points)
{
	t_list_el		*current_el;
	t_boundaries	boundaries;

	set_boundaries(&boundaries, lst_2d_points);
	current_el = *lst_2d_points;
	while (current_el)
	{
		((t_2dpoint *)current_el->content)->x += WINDOW_WIDTH / 2;
		((t_2dpoint *)current_el->content)->y += WINDOW_HEIGHT / 2;
		current_el = current_el->next;
	}
}

void	resize_2d_points(t_list_el **lst_2d_points, t_camera *camera)
{
	t_list_el		*current_el;
	t_boundaries	boundaries;

	set_boundaries(&boundaries, lst_2d_points);
	set_camera(&boundaries, camera);
	current_el = *lst_2d_points;
	while (current_el)
	{
		((t_2dpoint *)current_el->content)->x *= camera->zoom;
		((t_2dpoint *)current_el->content)->y *= camera->zoom;
		current_el = current_el->next;
	}
}

t_2dpoint	*format_2d_points(t_list_el **lst_2d_points, t_map *map)
{
	int			i;
	int			number_of_points;
	t_2dpoint	*formated_points;
	t_list_el	*current_el;

	number_of_points = ft_lstsize(*lst_2d_points);
	map->number_of_points = number_of_points;
	formated_points = ft_calloc(number_of_points + 1, sizeof(t_2dpoint));
	i = 0;
	current_el = *lst_2d_points;
	while (current_el)
	{
		formated_points[i] = *(t_2dpoint *)current_el->content;
		current_el = current_el->next;
	}
	return (formated_points);
}

t_2dpoint	*project_3d_to_isometric(
				t_list_el **lst_3d_points,
				t_list_el **lst_2d_points,
				t_camera *camera,
				t_map *map
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
	resize_2d_points(lst_2d_points, camera);
	move_2d_points(lst_2d_points);
	return (format_2d_points(lst_2d_points, map));
}
