/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:59:35 by gaboidin          #+#    #+#             */
/*   Updated: 2025/02/13 18:14:54 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	apply_projection(t_point *p, t_point *r, t_fdf *data)
{
	if (data->projection == 0)
	{
		p->x = (r->x - r->y) * cos(0.523599) * data->scale + data->offset_x;
		p->y = (r->x + r->y) * sin(0.523599) * data->scale - r->z
			+ data->offset_y;
	}
	else if (data->projection == 1)
	{
		p->x = r->x * data->scale + data->offset_x;
		p->y = r->y * data->scale + data->offset_y;
	}
}
