/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:51:15 by fvarrin           #+#    #+#             */
/*   Updated: 2022/03/05 11:53:48 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

#include <math.h>
#include <stdlib.h>

t_2dpoint	*create_2d_point(
		t_3dpoint *point_3d,
		t_2dpoint *point_2d,
		t_camera *camera
	)
{
	t_3dpoint	projected_3d_point;

	init_3d_point(&projected_3d_point, point_3d->x, point_3d->y, point_3d->z);
	projected_3d_point.z = (projected_3d_point.z * camera->height) / 100;
	rotate_x_axis(&projected_3d_point, camera->angle_x);
	rotate_y_axis(&projected_3d_point, camera->angle_y);
	do_projection(&projected_3d_point, point_2d);
	return (point_2d);
}

void	move_2d_points(t_2dpoint *arr_2d_points, t_window *window)
{
	int				i;
	t_camera		*camera;

	camera = window->camera;
	i = 0;
	while (i < window->map->number_of_points)
	{
		(arr_2d_points[i]).x += camera->offset_x;
		(arr_2d_points[i]).y += camera->offset_y;
		i++;
	}
}

void	resize_2d_points(t_2dpoint *arr_2d_points, t_window *window)
{
	int				i;
	t_camera		*camera;
	t_boundaries	boundaries;

	camera = window->camera;
	if (camera->zoom < 0)
	{
		set_boundaries(&boundaries, window, arr_2d_points);
		set_camera_zoom(&boundaries, camera);
	}
	i = 0;
	while (i < window->map->number_of_points)
	{
		(arr_2d_points[i]).x *= camera->zoom;
		(arr_2d_points[i]).x /= ZOOM_BASE;
		(arr_2d_points[i]).y *= camera->zoom;
		(arr_2d_points[i]).y /= ZOOM_BASE;
		i++;
	}
}

t_2dpoint	*project_3d_to_isometric(
				t_list_el **lst_3d_points,
				t_2dpoint *arr_2d_points,
				t_window *window
			)
{
	int			i;
	t_list_el	*current_el;
	t_camera	*camera;

	camera = window->camera;
	i = 0;
	current_el = *lst_3d_points;
	while (current_el)
	{
		create_2d_point(current_el->content, &(arr_2d_points[i]), camera);
		current_el = current_el->next;
		i++;
	}
	resize_2d_points(arr_2d_points, window);
	move_2d_points(arr_2d_points, window);
	return (arr_2d_points);
}
