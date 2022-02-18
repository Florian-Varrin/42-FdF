/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boundaries.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:30:07 by                   #+#    #+#             */
/*   Updated: 2022/02/18 10:31:22 by                  ###   ########.fr       */
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
		t_list_el **lst_2d_points
)
{
	t_list_el		*current_el;

	current_el = *lst_2d_points;
	update_boundaries(boundaries, current_el->content, true);
	while (current_el)
	{
		update_boundaries(boundaries, current_el->content, false);
		current_el = current_el->next;
	}
}
