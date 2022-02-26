/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:17:35 by fvarrin           #+#    #+#             */
/*   Updated: 2022/02/26 14:05:44 by                  ###   ########.fr       */
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
	mlx_destroy_window(window->mlx, window->win);
	ft_lstclear(&(window->lst_3d_points), destroy_point);
	free(window->current_image);
	free(window);
	free(map);
	free(camera);
}
