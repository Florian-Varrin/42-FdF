/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:21:20 by fvarrin           #+#    #+#             */
/*   Updated: 2022/02/16 15:48:13 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	init_point(t_2dpoint *point, int x, int y)
{
	point->x = x;
	point->y = y;
}

void	init_image(t_window *window, t_image *image)
{
	image->img = mlx_new_image(window->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	image->addr = mlx_get_data_addr(
			image->img,
			&(image->bits_per_pixel),
			&(image->line_length),
			&(image->endian)
			);
}

void	init_window(
			t_window *window,
			int (*handle_key)(int, void *),
			int (*handle_mouse)(int, int, int, void *)
		)
{
	window->mlx = mlx_init();
	window->win = mlx_new_window(
			window->mlx,
			WINDOW_WIDTH,
			WINDOW_HEIGHT,
			WINDOW_NAME
			);
	mlx_key_hook(window->win, handle_key, window);
	mlx_mouse_hook(window->win, handle_mouse, window);
}
