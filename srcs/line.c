/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:41:59 by fvarrin           #+#    #+#             */
/*   Updated: 2022/02/16 15:56:50 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	swap_points(t_2dpoint *start, t_2dpoint *end)
{
	t_2dpoint	tmp;

	tmp = *start;
	*start = *end;
	*end = tmp;
}

void	_compute_number(int *computed_number, int slope)
{
	if (slope > 1)
		(*computed_number)++;
	else
		(*computed_number)--;
}

void	draw_slope_compute_y(
			t_2dpoint *start,
			t_2dpoint *end,
			int slope,
			t_image *image
		)
{
	int	dx;
	int	dy;
	int	p;
	int	x;
	int	y;

	if (start->x > end->x)
		swap_points(start, end);
	dx = ft_abs((end->x) - (start->x));
	dy = ft_abs((end->y) - (start->y));
	p = (2 * dy) - dx;
	x = start->x;
	y = start->y;
	while (x <= end->x)
	{
		put_pixel_to_image(image, x, y, COLOR);
		if (p >= 1)
		{
			_compute_number(&y, slope);
			p += (2 * dy) - (2 * dx);
		}
		else
			p += (2 * dy);
		x++;
	}
}

void	draw_slope_compute_x(
			t_2dpoint *start,
			t_2dpoint *end,
			int slope,
			t_image *image
		)
{
	int	dx;
	int	dy;
	int	p;
	int	x;
	int	y;

	if (start->y > end->y)
		swap_points(start, end);
	dx = ft_abs((end->x) - (start->x));
	dy = ft_abs((end->y) - (start->y));
	p = (2 * dx) - dy;
	x = start->x;
	y = start->y;
	while (y <= end->y)
	{
		put_pixel_to_image(image, x, y, COLOR);
		if (p >= 1)
		{
			_compute_number(&x, slope);
			p += (2 * dx) - (2 * dy);
		}
		else
			p += (2 * dx);
		y++;
	}
}

void	draw_line(t_2dpoint *start, t_2dpoint *end, t_image *image)
{
	int	slope;

	if (end->x - start->x == 0)
		slope = (end->y - start->y);
	else
		slope = (double)(end->y - start->y) / (end->x - start->x);
	if (ft_abs(slope) < 1)
		draw_slope_compute_y(start, end, slope, image);
	else
		draw_slope_compute_x(start, end, slope, image);
}
