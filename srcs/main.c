/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:52:17 by fvarrin           #+#    #+#             */
/*   Updated: 2022/02/17 13:33:34 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	parse(int argc, char **argv, t_list_el **lst_2d_points)
{
	t_list_el	*lst_3d_points;

	lst_3d_points = NULL;
	if (argc != 2)
		print_usage();
	parse_file(&lst_3d_points, argv[1]);
	project_3d_to_isometric(&lst_3d_points, lst_2d_points);
	ft_lstclear(&lst_3d_points, destroy_point);
}

void	display(void)
{
	t_window	window;
	t_image		image;

	init_window(&window, &handle_key, &handle_mouse);
	init_image(&window, &image);
	mlx_loop(window.mlx);
}

int	main(int argc, char **argv)
{
	t_list_el	*lst_2d_points;

	lst_2d_points = NULL;
	parse(argc, argv, &lst_2d_points);
	ft_lstiter(lst_2d_points, print_2d_point);
	display();
	ft_lstclear(&lst_2d_points, destroy_point);
}
