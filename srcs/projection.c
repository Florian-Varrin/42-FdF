/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:51:15 by fvarrin           #+#    #+#             */
/*   Updated: 2022/02/26 11:37:54 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

t_2dpoint	*create_2d_point(t_3dpoint *point_3d, t_camera *camera)
{
	int			x;
	int			y;
	int			z;
	t_2dpoint	*point_2d;

	point_2d = malloc(sizeof(t_2dpoint));
	x = point_3d->x;
	y = point_3d->y;
	z = (point_3d->z * camera->height) / 100;
	point_2d->x = (int)((x - z) / sqrt(2));
	point_2d->y = (int)((x + (2 * y) + z) / sqrt(6));
	return (point_2d);
}

void	move_2d_points(t_list_el **lst_2d_points, t_camera *camera)
{
	t_list_el		*current_el;
	t_boundaries	boundaries;

	set_boundaries(&boundaries, lst_2d_points);
	current_el = *lst_2d_points;
	while (current_el)
	{
		((t_2dpoint *)current_el->content)->x += camera->offset_x;
		((t_2dpoint *)current_el->content)->y += camera->offset_y;
		current_el = current_el->next;
	}
}

void	resize_2d_points(t_list_el **lst_2d_points, t_camera *camera)
{
	t_list_el		*current_el;
	t_boundaries	boundaries;

	if (camera->zoom < 0)
	{
		set_boundaries(&boundaries, lst_2d_points);
		set_camera_zoom(&boundaries, camera);
	}
	current_el = *lst_2d_points;
	while (current_el)
	{
		((t_2dpoint *)current_el->content)->x *= camera->zoom;
		((t_2dpoint *)current_el->content)->x /= ZOOM_BASE;
		((t_2dpoint *)current_el->content)->y *= camera->zoom;
		((t_2dpoint *)current_el->content)->y /= ZOOM_BASE;
		current_el = current_el->next;
	}
}

t_2dpoint	*format_2d_points(t_list_el **lst_2d_points, t_map *map)
{
	int			i;
	int			number_of_points;
	t_2dpoint	*points_array;
	t_list_el	*current_el;

	number_of_points = ft_lstsize(*lst_2d_points);
	map->number_of_points = number_of_points;
	points_array = ft_calloc(number_of_points + 1, sizeof(t_2dpoint));
	i = 0;
	current_el = *lst_2d_points;
	while (current_el)
	{
		points_array[i++] = *(t_2dpoint *)current_el->content;
		current_el = current_el->next;
	}
	return (points_array);
}

t_2dpoint	*project_3d_to_isometric(
				t_list_el **lst_3d_points,
				t_camera *camera,
				t_map *map
			)
{
	t_2dpoint	*point_2d;
	t_2dpoint	*points_2d;
	t_list_el	*current_el;
	t_list_el	*lst_2d_points;

	lst_2d_points = NULL;
	current_el = *lst_3d_points;
	while (current_el)
	{
		point_2d = create_2d_point(current_el->content, camera);
		ft_lstadd_back(&lst_2d_points, ft_lstnew(point_2d));
		current_el = current_el->next;
	}
	resize_2d_points(&lst_2d_points, camera);
	move_2d_points(&lst_2d_points, camera);
	points_2d = format_2d_points(&lst_2d_points, map);
	ft_lstclear(&lst_2d_points, destroy_point);
	return (points_2d);
}
