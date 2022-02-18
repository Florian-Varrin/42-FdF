/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:14:02 by fvarrin           #+#    #+#             */
/*   Updated: 2022/02/18 16:14:29 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	print_2d_point(points);
	while (i < map->number_of_points)
	{
		put_pixel_to_image(image, points[i].x, points[i].y, 0x0000FF00);
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
