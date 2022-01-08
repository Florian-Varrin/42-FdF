/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:52:17 by fvarrin           #+#    #+#             */
/*   Updated: 2022/01/08 15:37:25 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx-wrapper.h"

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void    print_usage(void)
{
        ft_printf("usage: ./fdf [path-to-map]\n");
        exit(-1);
}

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
}
