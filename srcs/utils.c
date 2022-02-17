/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:20 by fvarrin           #+#    #+#             */
/*   Updated: 2022/02/17 13:36:15 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

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

void	exit_program_gracefully(void)
{
	exit(0);
}
