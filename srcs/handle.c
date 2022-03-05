/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:50:28 by fvarrin           #+#    #+#             */
/*   Updated: 2022/03/05 12:19:43 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"

#include <stdbool.h>
#include <stdlib.h>

int	zoom_handler(int keycode, t_window *window)
{
	if (keycode == KEY_MINUS && window->camera->zoom > ZOOM_STEP)
		window->camera->zoom -= ZOOM_STEP;
	if (keycode == KEY_PLUS)
		window->camera->zoom += ZOOM_STEP;
	render_map(window);
	return (0);
}

int	height_handler(int keycode, t_window *window)
{
	if (keycode == KEY_DIVIDE)
		window->camera->height -= HEIGHT_STEP;
	if (keycode == KEY_MULTIPLY)
		window->camera->height += HEIGHT_STEP;
	render_map(window);
	return (0);
}

int	move_handler(int keycode, t_window *window)
{
	if (keycode == KEY_DOWN)
		window->camera->offset_y += MOVE_STEP;
	else if (keycode == KEY_UP)
		window->camera->offset_y -= MOVE_STEP;
	else if (keycode == KEY_LEFT)
		window->camera->offset_x -= MOVE_STEP;
	else if (keycode == KEY_RIGHT)
		window->camera->offset_x += MOVE_STEP;
	render_map(window);
	return (0);
}

int	rotate_handler(int keycode, t_window *window)
{
	if (keycode == KEY_NUMPAD_DOWN)
		window->camera->angle_x -= ANGLE_STEP;
	else if (keycode == KEY_NUMPAD_UP)
		window->camera->angle_x += ANGLE_STEP;
	else if (keycode == KEY_NUMPAD_LEFT)
		window->camera->angle_y -= ANGLE_STEP;
	else if (keycode == KEY_NUMPAD_RIGHT)
		window->camera->angle_y += ANGLE_STEP;
	render_map(window);
	return (0);
}

int	color_handler(t_window *window)
{
	t_colors	*colors;
	int			next_index;

	colors = window->map->colors;
	next_index = colors->current_color_index + 1;
	if (next_index == colors->number_of_colors - 1)
		next_index = 0;
	colors->current_color_index = next_index;
	render_map(window);
	return (0);
}
