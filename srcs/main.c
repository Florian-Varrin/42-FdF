/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:52:17 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/08 15:59:10 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void    print_usage(void)
{
        ft_printf("usage: ./fdf [path-to-map]\n");
        exit(-1);
}

void	exit_program_gracefully(t_window *window)
{
	close(window->fd);
	exit(0);
}

int	handle_key(int keycode, t_window *window)
{
	if (window == NULL)
		return (0);
	if (keycode == 53)
		exit_program_gracefully(window);
	return (0);
}

void	init_window(t_window *window, int fd)
{
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	window->fd = fd;
	mlx_key_hook(window->win, handle_key, &window);
}

int	main(int argc, char **argv)
{
	int			fd;
	t_window	window;

	if (argc != 2)
		print_usage();
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_usage();
	init_window(&window, fd);
	mlx_loop(window.mlx);
	exit_program_gracefully(&window);
}
