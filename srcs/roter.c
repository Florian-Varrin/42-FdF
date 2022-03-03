/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:45:10 by                   #+#    #+#             */
/*   Updated: 2022/03/03 14:52:51 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdlib.h>
#include <stdbool.h>

t_roter	*init_roter(void)
{
	t_roter	*roter;

	roter = (t_roter *)malloc(sizeof(roter));
	roter->x_angle = 1;
	roter->y_angle = 1;
	return (roter);
}

t_roter	*reset_roter(t_roter *current_roter)
{
	free(current_roter);
	return (init_roter());
}
