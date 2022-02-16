/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:53:38 by fvarrin           #+#    #+#             */
/*   Updated: 2022/02/16 15:45:42 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WINDOW_WIDTH 700
# define WINDOW_HEIGHT 700
# define WINDOW_NAME "FdF"
# define COLOR 0x00FF0000

# ifdef __APPLE__
#  define KEY_Q 12
#  define KEY_P 35
#  define KEY_N 45
# else
#  define KEY_Q 113
#  define KEY_P 112
#  define KEY_N 110
# endif

typedef struct s_2dpoint {
	int	x;
	int	y;
} t_2dpoint;

typedef struct s_window {
	void		*mlx;
	void		*win;
}	t_window;

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

// Init
void		init_image(t_window *window, t_image *image);
void	init_window(t_window *window, int (*handle_key)(int, void *), int (*handle_mouse)(int, int, int, void *));
void		init_point(t_2dpoint *point, int x, int y);

// Draw
void		put_pixel_to_image(t_image *image, int x, int y, int color);
void		draw_line(t_2dpoint *start, t_2dpoint *end, t_image *image);
#endif
