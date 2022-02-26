/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:50:28 by fvarrin           #+#    #+#             */
/*   Updated: 2022/02/26 13:21:58 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"

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

int	handle_key(int keycode, void *window)
{
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
	(void) x;
	(void) y;
	if (mouse == MOUSE_WHEEL_UP || mouse == MOUSE_WHEEL_DOWN)
		return (zoom_handler(mouse, window));
	return (0);
}
