/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:52:17 by fvarrin           #+#    #+#             */
/*   Updated: 2022/02/17 09:44:11 by fvarrin          ###   ########.fr       */
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

void	exit_error(char *message)
{
	ft_perror(message);
	exit(-1);
}

void	exit_program_gracefully(void)
{
	exit(0);
}

int	main(int argc, char **argv)
{
	t_window	window;
	t_image		image;
	t_list_el	*lst_points_3d;

	lst_points_3d = NULL;
	if (argc != 2)
		print_usage();
	parse_file(&lst_points_3d, argv[1]);
	init_window(&window, &handle_key, &handle_mouse);
	init_image(&window, &image);
	mlx_loop(window.mlx);
	ft_lstclear(&lst_points_3d, destroy_3dpoint);
}
