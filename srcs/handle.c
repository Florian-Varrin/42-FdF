/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:50:28 by fvarrin           #+#    #+#             */
/*   Updated: 2022/02/26 14:02:56 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"

#include <stdbool.h>
#include <stdlib.h>

int	zoom_handler(int mouse, t_window *window)
{
	if (mouse == MOUSE_WHEEL_DOWN && window->camera->zoom > ZOOM_STEP)
		window->camera->zoom -= ZOOM_STEP;
	if (mouse == MOUSE_WHEEL_UP)
		window->camera->zoom += ZOOM_STEP;
	render_map(window);
	return (0);
}

int	height_handler(int keycode, t_window *window)
{
	if (keycode == KEY_DOWN)
		window->camera->height -= HEIGHT_STEP;
	if (keycode == KEY_UP)
		window->camera->height += HEIGHT_STEP;
	render_map(window);
	return (0);
}

int	move_handler(int x, int y, t_window *window)
{
	t_mover		*mover;
	t_camera	*camera;
	t_2dpoint	*new_point;

	mover = window->mover;
	camera = window->camera;
	new_point = malloc(sizeof(t_2dpoint));
	if (mover->is_moving)
	{
		init_2d_point(new_point, x, y);
		mover->end = new_point;
		camera->offset_x += mover->end->x - mover->start->x;
		camera->offset_y += mover->end->y - mover->start->y;
		window->mover = reset_mover(mover);
		render_map(window);
	}
	else
	{
		mover->is_moving = true;
		init_2d_point(new_point, x, y);
		mover->start = new_point;
	}
	return (0);
}

int	handle_key(int keycode, void *config)
{
	t_window	*window;

	window = config;
	if (window == NULL)
		return (0);
	if (keycode == KEY_Q || keycode == KEY_ESC)
		exit_program_gracefully(window);
	if (keycode == KEY_UP || keycode == KEY_DOWN)
		return (height_handler(keycode, window));
	return (0);
}

int	handle_mouse(int mouse, int x, int y, void *config)
{
	t_window	*window;

	window = config;
	if (window == NULL)
		return (0);
	if (mouse == MOUSE_CLICK)
		return (move_handler(x, y, window));
	if (mouse == MOUSE_WHEEL_UP || mouse == MOUSE_WHEEL_DOWN)
		return (zoom_handler(mouse, window));
	return (0);
}
