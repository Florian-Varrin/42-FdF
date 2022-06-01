/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:33:59 by fvarrin           #+#    #+#             */
/*   Updated: 2022/03/05 13:47:20 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_key(int keycode, void *config)
{
	t_window	*window;

	window = config;
	if (window == NULL)
		return (0);
	if (keycode == KEY_Q || keycode == KEY_ESC)
		exit_program_gracefully(window);
	if (keycode == KEY_MULTIPLY || keycode == KEY_DIVIDE)
		return (height_handler(keycode, window));
	if (keycode == KEY_UP || keycode == KEY_DOWN
		|| keycode == KEY_LEFT || keycode == KEY_RIGHT)
		return (move_handler(keycode, window));
	if (keycode == KEY_NUMPAD_UP || keycode == KEY_NUMPAD_DOWN
		|| keycode == KEY_NUMPAD_LEFT || keycode == KEY_NUMPAD_RIGHT)
		return (rotate_handler(keycode, window));
	if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		return (zoom_handler(keycode, window));
	if (keycode == KEY_C)
		return (color_handler(window));
	return (0);
}

int handle_close(void *config)
{
	t_window	*window;

	window = config;
	exit_program_gracefully(window);
	return (0);
}