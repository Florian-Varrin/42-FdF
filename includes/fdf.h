/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:53:38 by fvarrin           #+#    #+#             */
/*   Updated: 2022/03/05 13:47:02 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"

# define WINDOW_WIDTH 1400
# define WINDOW_HEIGHT 1000
# define WINDOW_NAME "FdF"
# define ZOOM_BASE 100
# define ZOOM_STEP 25
# define HEIGHT_BASE 100
# define HEIGHT_STEP 10
# define MOVE_STEP 25
# define ANGLE_STEP 0.1
# define X_BASE_ANGLE 51
# define Y_BASE_ANGLE 31

# define NUMBER_OF_COLORS 5
# define COLOR_0 0x00FFFFFF;
# define COLOR_1 0x00e06060;
# define COLOR_2 0x008ab4f8;
# define COLOR_3 0x0082c682;
# define COLOR_4 0x00e2e286;

# define MSG_INVALID_FILE "Invalid file\n"

# ifdef __APPLE__
#  define KEY_Q 12
#  define KEY_P 35
#  define KEY_N 45
# else
#  define KEY_Q 113
#  define KEY_P 112
#  define KEY_N 110
#  define KEY_C 99
#  define KEY_ESC 65307
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_NUMPAD_UP 65431
#  define KEY_NUMPAD_DOWN 65433
#  define KEY_NUMPAD_LEFT 65430
#  define KEY_NUMPAD_RIGHT 65432
#  define KEY_MINUS 65453
#  define KEY_PLUS 65451
#  define KEY_DIVIDE 65455
#  define KEY_MULTIPLY 65450
# endif

typedef struct s_2dpoint {
	double	x;
	double	y;
}	t_2dpoint;

typedef struct s_3dpoint {
	double	x;
	double	y;
	double	z;
}	t_3dpoint;

typedef struct s_matrix {
	int	rows;
	int	columns;
	int	*matrix;
}	t_matrix;

typedef struct s_boundaries {
	int	max_x;
	int	min_x;
	int	max_y;
	int	min_y;
}	t_boundaries;

typedef struct s_camera {
	int		zoom;
	int		height;
	int		offset_x;
	int		offset_y;
	double	angle_x;
	double	angle_y;
}	t_camera;

typedef struct s_colors {
	int	*available_colors;
	int	number_of_colors;
	int	current_color_index;
}	t_colors;

typedef struct s_map {
	int			number_of_points;
	int			line_size;
	t_colors	*colors;
}	t_map;

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_window {
	void		*mlx;
	void		*win;
	t_image		*current_image;
	t_map		*map;
	t_camera	*camera;
	t_list_el	*lst_3d_points;
	t_2dpoint	*arr_2d_points;
}	t_window;

// General
void		exit_error(char *message);
void		exit_program_gracefully(t_window *window);
void		print_usage(void);
void		destroy_state(t_window *window, t_map *map, t_camera *camera);

// Init
t_image		*init_image(t_window *window, t_image *image);
t_window	*init_window(t_window *window, int (*handle_key)(int, void *));
void		init_3d_point(t_3dpoint *point, double x, double y, double z);
t_map		*init_map(t_map *map, t_window *window);

// Draw
void		put_pixel_to_image(t_image *image, int x, int y, int color);
void		draw_line(
				t_2dpoint *start,
				t_2dpoint *end,
				t_image *image,
				t_colors *colors);
void		draw_map(t_image *image, t_map *map, t_2dpoint *points);
void		render_map(t_window *window);
void		prepare_map(t_window *window);

// Parse
void		parse_file(t_list_el **lst_3d_points, char *path, t_map *map);

// Destroy
void		destroy_point(void *content);

// Projection
t_2dpoint	*project_3d_to_isometric(
				t_list_el **lst_3d_points,
				t_2dpoint *arr_2d_points,
				t_window *window);

// Camera
t_camera	*init_camera(t_camera *camera, t_window *window);
void		set_camera_zoom(t_boundaries *boundaries, t_camera *camera);

// Handle
int			handle_key(int keycode, void *window);

// Boundaries
void		set_boundaries(
				t_boundaries *boundaries,
				t_window *window,
				t_2dpoint *arr_2d_points);

// Matrices
t_3dpoint	*rotate_x_axis(t_3dpoint *point, double angle);
t_3dpoint	*rotate_y_axis(t_3dpoint *point, double angle);
void		do_projection(t_3dpoint *point_3d, t_2dpoint *point_2d);

// Handle
int			zoom_handler(int keycode, t_window *window);
int			height_handler(int keycode, t_window *window);
int			move_handler(int keycode, t_window *window);
int			rotate_handler(int keycode, t_window *window);
int			color_handler(t_window *window);
#endif
