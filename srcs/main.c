/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:52:17 by fvarrin           #+#    #+#             */
/*   Updated: 2022/03/03 15:39:32 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	parse(
	char **argv,
	t_map *map,
	t_list_el *lst_3d,
	t_window *window
)
{
	lst_3d = NULL;
	parse_file(&lst_3d, argv[1], map);
	window->lst_3d_points = lst_3d;
}

void	init_state(t_window **window, t_map **map, t_camera **camera)
{
	*window = init_window(*window, &handle_key);
	*map = init_map(*map, *window);
	*camera = init_camera(*camera, *window);
}

int	main(int argc, char **argv)
{
	t_window	*window;
	t_camera	*camera;
	t_map		*map;
	t_list_el	*lst_3d;

	if (argc != 2)
		print_usage();
	window = NULL;
	map = NULL;
	camera = NULL;
	init_state(&window, &map, &camera);
	lst_3d = NULL;
	parse(argv, map, lst_3d, window);
	prepare_map(window);
	render_map(window);
	destroy_state(window, map, camera);
}
