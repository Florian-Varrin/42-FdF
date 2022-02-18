/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:52:17 by fvarrin           #+#    #+#             */
/*   Updated: 2022/02/18 13:29:55 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

t_2dpoint	*parse(
		int argc,
		char **argv,
		t_camera *camera,
		t_map *map
	)
{
	t_list_el	*lst_3d;
	t_list_el	*lst_2d;
	t_2dpoint	*points;

	lst_3d = NULL;
	lst_2d = NULL;
	if (argc != 2)
		print_usage();
	parse_file(&lst_3d, argv[1], map);
	points = project_3d_to_isometric(&lst_3d, &lst_2d, camera, map);
	ft_lstclear(&lst_3d, destroy_point);
	ft_lstclear(&lst_2d, destroy_point);
	return (points);
}

void	display(t_2dpoint *points_2d, t_map *map)
{
	t_window	window;
	t_image		image;

	init_window(&window, &handle_key, &handle_mouse);
	init_image(&window, &image);
	draw_map(&image, map, points_2d);
	mlx_put_image_to_window(window.mlx, window.win, image.img, 0, 0);
	mlx_loop(window.mlx);
}

int	main(int argc, char **argv)
{
	t_camera	camera;
	t_map		map;
	t_2dpoint	*points_2d;

	init_map(&map);
	points_2d = parse(argc, argv, &camera, &map);
	display(points_2d, &map);
	free(points_2d);
}
