/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:29:11 by                   #+#    #+#             */
/*   Updated: 2022/02/27 17:03:17 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <math.h>
#include <stdlib.h>

t_3dpoint	*do_matrix_multiplication(t_3dpoint *point, double matrix[3][3])
{
	double		x;
	double		y;
	double		z;

	x = point->x;
	y = point->y;
	z = point->z;
	x = (x * matrix[0][0]) + (x * matrix[1][0]) + (x * matrix[2][0]);
	y = (y * matrix[0][1]) + (y * matrix[1][1]) + (y * matrix[2][1]);
	z = (z * matrix[0][2]) + (z * matrix[1][2]) + (z * matrix[2][2]);
	init_3d_point(point, (int)x, (int)y, (int)z);
	return (point);
}

t_3dpoint	*rotate_x_axis(t_3dpoint *point)
{
	double	matrix[3][3];

	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = cos(35.264);
	matrix[1][2] = sin(35.264);
	matrix[2][0] = 0;
	matrix[2][1] = -sin(35.264);
	matrix[2][2] = cos(35.264);
	return (do_matrix_multiplication(point, matrix));
}

t_3dpoint	*rotate_y_axis(t_3dpoint *point)
{
	double	matrix[3][3];

	matrix[0][0] = cos(45);
	matrix[0][1] = 0;
	matrix[0][2] = -sin(45);
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[2][0] = sin(45);
	matrix[2][1] = 0;
	matrix[2][2] = cos(45);
	return (do_matrix_multiplication(point, matrix));
}

void	do_projection(t_3dpoint *point_3d, t_2dpoint *point_2d)
{
	double		matrix[3][3];
	t_3dpoint	*projected_point_3d;

	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 0;
	projected_point_3d = do_matrix_multiplication(point_3d, matrix);
	point_2d->x = projected_point_3d->x;
	point_2d->y = projected_point_3d->y;
}
