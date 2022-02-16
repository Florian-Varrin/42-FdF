/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:14:02 by fvarrin           #+#    #+#             */
/*   Updated: 2022/02/16 14:44:15 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel_to_image(t_image *image, int x, int y, int color)
{
	char	*dst;
	int		pxl_offset;

	pxl_offset = (y * image->line_length + x * (image->bits_per_pixel / 8));
	dst = image->addr + pxl_offset;
	*(unsigned int *)dst = color;
}
