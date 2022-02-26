/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mover.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:46:40 by                   #+#    #+#             */
/*   Updated: 2022/02/26 13:51:11 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdlib.h>
#include <stdbool.h>

t_mover	*init_mover(void)
{
	t_mover	*mover;

	mover = (t_mover *)malloc(sizeof(mover));
	mover->is_moving = false;
	mover->start = NULL;
	mover->end = NULL;
	return (mover);
}

t_mover	*reset_mover(t_mover *current_mover)
{
	free(current_mover->start);
	free(current_mover->end);
	free(current_mover);
	return (init_mover());
}
