/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:41:43 by                   #+#    #+#             */
/*   Updated: 2022/02/18 10:26:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	set_camera(t_boundaries *boundaries, t_camera *camera)
{
	int		x;
	int		y;
	int		delta_x;
	int		delta_y;

	delta_x = ((WINDOW_WIDTH / 2) * 100) / 80;
	delta_y = ((WINDOW_HEIGHT / 2) * 100) / 80;
	x = delta_x / (boundaries->max_x - boundaries->min_x);
	y = delta_y / (boundaries->max_y - boundaries->min_y);
	if (x < y)
		camera->zoom = x / 2;
	else
		camera->zoom = y / 2;
}
