/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:52:17 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/09 11:26:37 by fvarrin          ###   ########.fr       */
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

void	init_image(t_window *window, t_image *image)
{
	image->img = mlx_new_image(window->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	image->addr = mlx_get_data_addr(image->img, &(image->bits_per_pixel), &(image->line_length), &(image->endian));
}

void	init_window(t_window *window, int fd)
{
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	window->fd = fd;
	mlx_key_hook(window->win, handle_key, &window);
}

void	put_pixel_to_image(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void drawline(t_image *image, int x0, int x1, int y0, int y1)
{
	int dx;
	int dy;
	int p;
	int x;
	int	y;

	dx = x1 - x0;
	dy = y1 - y0;
 	x = x0;
	y = y0;
 	p = 2 * dy - dx;
 
	ft_printf("x: %d, x1: %d", x, x1);
	while(x < x1)
	{
		if(p >= 0)
		{
			ft_printf("(%d, %d)\n", x, y);
			put_pixel_to_image(image, x, y, COLOR);
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			ft_printf("(%d, %d)\n", x, y);
			put_pixel_to_image(image, x, y, COLOR);
			p = p + 2 * dy;
		}
		x = x + 1;
	}
}

int	main(int argc, char **argv)
{
	int			fd;
	t_window	window;
	t_image		image;

	if (argc != 2)
		print_usage();
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_usage();
	init_window(&window, fd);
	init_image(&window, &image);
	drawline(&image, 0, 0, 25, 25);
	mlx_put_image_to_window(window.mlx, window.win, image.img, 0, 0);
	mlx_loop(window.mlx);
	exit_program_gracefully(&window);
}
