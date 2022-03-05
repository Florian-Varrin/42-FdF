/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boundaries.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:30:07 by                   #+#    #+#             */
/*   Updated: 2022/03/05 11:48:50 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdbool.h>

void	update_boundaries(
		t_boundaries *boundaries,
		t_2dpoint *point,
		_Bool first_point
)
{
	if (first_point || boundaries->max_x < point->x)
		boundaries->max_x = point->x;
	if (first_point || boundaries->min_x > point->x)
		boundaries->min_x = point->x;
	if (first_point || boundaries->max_y < point->y)
		boundaries->max_y = point->y;
	if (first_point || boundaries->min_y > point->y)
		boundaries->min_y = point->y;
}

void	set_boundaries(
		t_boundaries *boundaries,
		t_window *window,
		t_2dpoint *arr_2d_points
)
{
	int		i;

	i = 0;
	update_boundaries(boundaries, &arr_2d_points[i], true);
	while (i < window->map->number_of_points)
	{
		update_boundaries(boundaries, &arr_2d_points[i], false);
		i++;
	}
}
