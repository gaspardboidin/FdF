/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:59:35 by gaboidin          #+#    #+#             */
/*   Updated: 2025/02/13 17:36:38 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	apply_projection(t_point *p, double new_x, double new_y, double new_z,
		t_fdf *data)
{
	if (data->projection == 0)
	{
		p->x = (new_x - new_y) * cos(0.523599) * data->scale + data->offset_x;
		p->y = (new_x + new_y) * sin(0.523599) * data->scale - new_z
			+ data->offset_y;
	}
	else if (data->projection == 1)
	{
		p->x = new_x * data->scale + data->offset_x;
		p->y = new_y * data->scale + data->offset_y;
	}
}
