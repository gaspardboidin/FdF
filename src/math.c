/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:49:35 by gaboidin          #+#    #+#             */
/*   Updated: 2025/02/21 19:51:50 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	initialize_bresenham(t_point p1, t_point p2, t_bresenham *b)
{
	b->dx = fabs(p2.x - p1.x);
	b->dy = fabs(p2.y - p1.y);
	get_direction(p1, p2, &b->sx, &b->sy);
	b->err = b->dx - b->dy;
}

void	draw_line_loop(t_fdf *data, t_point p1, t_point p2, t_bresenham *b)
{
	int	err2;
	int	color;

	color = p1.color;
	while (p1.x != p2.x || p1.y != p2.y)
	{
		put_pixel(data, p1.x, p1.y, color);
		err2 = b->err * 2;
		if (err2 > -b->dy)
		{
			b->err -= b->dy;
			p1.x += b->sx;
		}
		if (err2 < b->dx)
		{
			b->err += b->dx;
			p1.y += b->sy;
		}
	}
}

void	draw_line(t_fdf *data, t_point p1, t_point p2)
{
	t_bresenham	b;

	initialize_bresenham(p1, p2, &b);
	draw_line_loop(data, p1, p2, &b);
}
