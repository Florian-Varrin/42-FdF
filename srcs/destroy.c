/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:17:35 by fvarrin           #+#    #+#             */
/*   Updated: 2022/03/03 15:38:25 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

#include <stdlib.h>
#include <mlx.h>

void	destroy_point(void *content)
{
	free(content);
}

void	destroy_state(t_window *window, t_map *map, t_camera *camera)
{
	mlx_destroy_image(window->mlx, window->current_image->img);
	mlx_destroy_window(window->mlx, window->win);
	ft_lstclear(&(window->lst_3d_points), destroy_point);
	free(window->current_image);
	free(window);
	free(map->colors->available_colors);
	free(map->colors);
	free(map);
	free(camera);
}
