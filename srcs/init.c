/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:21:20 by fvarrin           #+#    #+#             */
/*   Updated: 2022/03/05 12:09:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

#include <stdlib.h>

void	init_3d_point(t_3dpoint *point, double x, double y, double z)
{
	point->x = x;
	point->y = y;
	point->z = z;
}

t_colors	*init_colors(t_colors *colors)
{
	colors = (t_colors *)malloc(sizeof(t_colors));
	colors->number_of_colors = NUMBER_OF_COLORS;
	colors->current_color_index = 0;
	colors->available_colors = (int *)malloc(sizeof(int) * NUMBER_OF_COLORS);
	colors->available_colors[0] = COLOR_0;
	colors->available_colors[1] = COLOR_1;
	colors->available_colors[2] = COLOR_2;
	colors->available_colors[3] = COLOR_3;
	colors->available_colors[4] = COLOR_4;
	return (colors);
}

t_map	*init_map(t_map *map, t_window *window)
{
	map = (t_map *)malloc(sizeof(map));
	map->line_size = -1;
	map->number_of_points = -1;
	window->map = map;
	map->colors = init_colors(map->colors);
	return (map);
}

t_image	*init_image(t_window *window, t_image *image)
{
	image = (t_image *)malloc(sizeof(t_image));
	image->img = mlx_new_image(window->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	image->addr = mlx_get_data_addr(
			image->img,
			&(image->bits_per_pixel),
			&(image->line_length),
			&(image->endian)
			);
	return (image);
}

t_window	*init_window(
			t_window *window,
			int (*handle_key)(int, void *)
		)
{
	window = (t_window *)malloc(sizeof(t_window));
	window->mlx = mlx_init();
	window->win = mlx_new_window(
			window->mlx,
			WINDOW_WIDTH,
			WINDOW_HEIGHT,
			WINDOW_NAME
			);
	mlx_key_hook(window->win, handle_key, window);
	window->lst_3d_points = NULL;
	window->map = NULL;
	window->current_image = NULL;
	window->arr_2d_points = NULL;
	return (window);
}
