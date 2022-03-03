/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_state.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:21:20 by fvarrin           #+#    #+#             */
/*   Updated: 2022/03/03 14:47:47 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

#include <stdlib.h>
#include <stdbool.h>

void	init_3d_point(t_3dpoint *point, double x, double y, double z)
{
	point->x = x;
	point->y = y;
	point->z = z;
}

void	init_2d_point(t_2dpoint *point, double x, double y)
{
	point->x = x;
	point->y = y;
}

t_map	*init_map(t_map *map, t_window *window)
{
	map = (t_map *)malloc(sizeof(map));
	map->line_size = -1;
	map->number_of_points = -1;
	window->map = map;
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
			int (*handle_key)(int, void *),
			int (*handle_mouse)(int, int, int, void *)
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
	mlx_mouse_hook(window->win, handle_mouse, window);
	window->lst_3d_points = NULL;
	window->map = NULL;
	window->mover = init_mover();
	window->roter = init_roter();
	return (window);
}
