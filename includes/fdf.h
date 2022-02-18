/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:53:38 by fvarrin           #+#    #+#             */
/*   Updated: 2022/02/18 10:48:02 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"

# define WINDOW_WIDTH 700
# define WINDOW_HEIGHT 700
# define WINDOW_NAME "FdF"
# define COLOR 0x00FF0000

# define MSG_INVALID_FILE "Invalid file\n"

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
}	t_2dpoint;

typedef struct s_3dpoint {
	int	x;
	int	y;
	int	z;
}	t_3dpoint;

typedef struct s_boundaries {
	int	max_x;
	int	min_x;
	int	max_y;
	int	min_y;
}	t_boundaries;

typedef struct s_camera {
	int	zoom;
}	t_camera;

typedef struct s_map {
	int	number_of_points;
	int	line_size;
}	t_map;

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

// General
void		exit_error(char *message);
void		exit_program_gracefully(void);
void		print_usage(void);

// Init
void		init_image(t_window *window, t_image *image);
void		init_window(t_window *window, int (*handle_key)(int, void *), int (*handle_mouse)(int, int, int, void *));
void		init_3d_point(t_3dpoint *point, int x, int y, int z);
void		init_2d_point(t_2dpoint *point, int x, int y);
void		init_map(t_map *map);

// Draw
void		put_pixel_to_image(t_image *image, int x, int y, int color);
void		draw_line(t_2dpoint *start, t_2dpoint *end, t_image *image);
void		draw_map(t_image *image, t_map *map, t_2dpoint *points);

// Parse
void		parse_file(t_list_el **lst_3d_points, char *path, t_map *map);

// Destroy
void		destroy_point(void *content);

// Projection
t_2dpoint	*project_3d_to_isometric(t_list_el **lst_3d_points, t_list_el **lst_2d_points, t_camera *camera, t_map *map);

// Camera
void		set_camera(t_boundaries *boundaries, t_camera *camera);

// Debug
void		print_2d_point(void *point);
void		print_3d_point(void *point);
void		print_boundaries(t_boundaries *boundaries);
void		print_map(t_map *map);

// Handle
int			handle_key(int keycode, void *window);
int			handle_mouse(int mouse, int x, int y, void *window);

// Boundaries
void		set_boundaries(t_boundaries *boundaries, t_list_el **lst_2d_points);
#endif
