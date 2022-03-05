/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:41:59 by fvarrin           #+#    #+#             */
/*   Updated: 2022/03/05 12:12:08 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	draw_linex(t_2dpoint *start, t_2dpoint *end, t_image *image, int color)
{
	int		x;
	int		y;
	int		dif;
	double	m;

	dif = 1;
	if (start->x > end->x)
		dif = -1;
	x = 0;
	m = (double)(end->y - start->y) / (end->x - start->x);
	y = start->y;
	while (ft_abs(x) < ft_abs(end->x - start->x))
	{
		y = (int)(m * x) + start->y;
		put_pixel_to_image(image, x + start->x, y, color);
		x += dif;
	}
}

void	draw_liney(t_2dpoint *start, t_2dpoint *end, t_image *image, int color)
{
	int		x;
	int		y;
	int		dif;
	double	m;

	dif = 1;
	if (start->y > end->y)
		dif = -1;
	y = 0;
	m = (double)(end->x - start->x) / (end->y - start->y);
	while (ft_abs(y) < ft_abs(end->y - start->y))
	{
		x = (int)(m * y) + start->x;
		put_pixel_to_image(image, x, y + start->y, color);
		y += dif;
	}
}

void	draw_line(
		t_2dpoint *start,
		t_2dpoint *end,
		t_image *image,
		t_colors *colors
	)
{
	int		color;
	int		xdif;
	int		ydif;

	color = colors->available_colors[colors->current_color_index];
	if ((start->x < 0 && end->x < 0) || (start->y < 0 && end->y < 0)
		|| (start->x > WINDOW_WIDTH && end->x > WINDOW_WIDTH)
		|| (start->y > WINDOW_HEIGHT && end->y > WINDOW_HEIGHT))
		return ;
	xdif = ft_abs(end->x - start->x);
	ydif = ft_abs(end->y - start->y);
	if (xdif && xdif > ydif)
		draw_linex(start, end, image, color);
	else if (ydif)
		draw_liney(start, end, image, color);
}
