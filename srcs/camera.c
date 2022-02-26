/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:41:43 by                   #+#    #+#             */
/*   Updated: 2022/02/26 11:38:35 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

#include <stdlib.h>

t_camera	*init_camera(t_camera *camera, t_window *window)
{
	camera = (t_camera *)malloc(sizeof(t_camera));
	camera->height = 100;
	camera->zoom = -1;
	camera->offset_x = WINDOW_WIDTH / 4;
	camera->offset_y = WINDOW_HEIGHT / 4;
	window->camera = camera;
	return (camera);
}

void	set_camera_zoom(t_boundaries *boundaries, t_camera *camera)
{
	int		x;
	int		y;
	int		delta_x;
	int		delta_y;

	x = -1;
	y = -1;
	delta_x = ((WINDOW_WIDTH / 2) * 100) / 80;
	delta_y = ((WINDOW_HEIGHT / 2) * 100) / 80;
	if (boundaries->max_x - boundaries->min_x != 0)
		x = delta_x / (boundaries->max_x - boundaries->min_x);
	if (boundaries->max_y - boundaries->min_y != 0)
		y = delta_y / (boundaries->max_y - boundaries->min_y);
	if (x != -1 && x < y)
		camera->zoom = x / 2;
	else if (y != -1)
		camera->zoom = y / 2;
	else
		camera->zoom = 1;
	camera->zoom *= ZOOM_BASE;
}
