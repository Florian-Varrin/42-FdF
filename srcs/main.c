/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:52:17 by fvarrin           #+#    #+#             */
/*   Updated: 2022/02/26 13:03:57 by                  ###   ########.fr       */
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

void	init(t_window **window, t_map **map, t_camera **camera)
{
	*window = init_window(*window, &handle_key, &handle_mouse);
	*map = init_map(*map, *window);
	*camera = init_camera(*camera, *window);
}

void	destroy(t_window *window, t_map *map, t_camera *camera)
{
	free(window->current_image);
	free(window);
	free(map);
	free(camera);
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
	init(&window, &map, &camera);
	lst_3d = NULL;
	parse(argv, map, lst_3d, window);
	render_map(window);
	ft_lstclear(&lst_3d, destroy_point);
	destroy(window, map, camera);
}
