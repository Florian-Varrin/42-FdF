/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:05:56 by fvarrin           #+#    #+#             */
/*   Updated: 2022/02/16 17:59:11 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

#include <fcntl.h>
#include <stdlib.h>

int	create_point(char *line_position, int x, int y, t_list_el **lst_points)
{
	int			count;
	int			z;
	t_3dpoint	*point;
	char		*digit;

	point = malloc(sizeof(t_3dpoint));
	count = 0;
	while (ft_isdigit(line_position[count]))
		count++;
	digit = ft_substr(line_position, 0, count + 1);
	z = ft_atoi(digit);
	free(digit);
	init_3d_point(point, x, y, z);
	ft_lstadd_back(lst_points, ft_lstnew((void *)point));
	return (count);
}

void	create_points_for_line(char *line, int y, t_list_el **lst_points)
{
	int			i;
	int			x;

	(void) lst_points;
	i = 0;
	x = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
		{
			x++;
			i += create_point(&line[i], x, y, lst_points);
		}
		i++;
	}
}

void	parse_file(t_list_el **lst_3d_points, char *path)
{
	int		fd;
	char	*line;
	int		line_num;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_error(MSG_INVALID_FILE);
	line = ft_get_next_line(fd);
	line_num = 0;
	while (line)
	{
		create_points_for_line(line, line_num, lst_3d_points);
		line = ft_get_next_line(fd);
		line_num++;
	}
}
