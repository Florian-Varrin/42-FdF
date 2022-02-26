/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:14:02 by fvarrin           #+#    #+#             */
/*   Updated: 2022/02/26 10:44:48 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	put_pixel_to_image(t_image *image, int x, int y, int color)
{
	char	*dst;

	if (0 <= x && x < WINDOW_WIDTH && 0 <= y && y < WINDOW_HEIGHT)
	{
		dst = image->addr
			+ (y * image->line_length + x * (image->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_map(t_image *image, t_map *map, t_2dpoint *points)
{
	int		i;
	int		upper_point;

	i = 0;
	while (i < map->number_of_points)
	{
		if (i % map->line_size != 0)
			draw_line(&(points[i]), &(points[i - 1]), image);
		if (i >= map->line_size)
		{
			upper_point = (i - map->line_size);
			draw_line(&points[i], &points[upper_point], image);
		}
		i++;
	}
}

void	render_map(t_window *window)
{
	t_list_el	*lst_3d;
	t_2dpoint	*points_2d;
	t_camera	*camera;
	t_map		*map;
	t_image		image;

	camera = window->camera;
	lst_3d = window->lst_3d_points;
	map = window->map;
	points_2d = project_3d_to_isometric(&lst_3d, camera, map);
	init_image(window, &image);
	draw_map(&image, map, points_2d);
	mlx_put_image_to_window(window->mlx, window->win, image.img, 0, 0);
	mlx_loop(window->mlx);
}
