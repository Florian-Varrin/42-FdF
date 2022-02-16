/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:50:28 by fvarrin           #+#    #+#             */
/*   Updated: 2022/02/16 17:50:51 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"

int	handle_key(int keycode, void *window)
{
	if (window == NULL)
		return (0);
	if (keycode == KEY_Q)
		exit_program_gracefully();
	return (0);
}

int	handle_mouse(int mouse, int x, int y, void *window)
{
	(void) mouse;
	(void) window;
	ft_printf("(%d, %d)\n", x, y);
	return (0);
}
