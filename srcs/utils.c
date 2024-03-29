/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:20 by fvarrin           #+#    #+#             */
/*   Updated: 2022/03/05 13:48:36 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"

#include <stdlib.h>

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

void	exit_program_gracefully(t_window *window)
{
	destroy_state(window, window->map, window->camera);
	exit(0);
}
