/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:53:38 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/09 10:15:11 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WINDOW_WIDTH 700
# define WINDOW_HEIGHT 700
# define WINDOW_NAME "FdF"
# define COLOR 0x00FF0000

typedef struct	s_window {
	void	*mlx;
	void	*win;
	int		fd;
}	t_window;

typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;
#endif
