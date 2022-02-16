/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:52:17 by fvarrin           #+#    #+#             */
/*   Updated: 2022/02/16 15:47:14 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	print_usage(void)
{
	ft_perror("usage: ./fdf [path-to-map]\n");
	exit(-1);
}

void	exit_program_gracefully(void)
{
	exit(0);
}

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

int	main(int argc, char **argv)
{
	t_window	window;
	t_image		image;

	if (argc != 2)
		print_usage();
	(void) argv;
	init_window(&window, &handle_key, &handle_mouse);
	init_image(&window, &image);
	mlx_loop(window.mlx);
	exit_program_gracefully();
}
