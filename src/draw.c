/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:51:37 by gaboidin          #+#    #+#             */
/*   Updated: 2025/02/21 21:34:55 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_direction(t_point p1, t_point p2, int *sx, int *sy)
{
	if (p1.x < p2.x)
		*sx = 1;
	else
		*sx = -1;
	if (p1.y < p2.y)
		*sy = 1;
	else
		*sy = -1;
}

t_point	get_point(int x, int y, int z, t_fdf *data)
{
	t_point	p;
	t_point	r;
	double	new_x;
	double	new_y;
	double	new_z;

	new_x = x;
	new_y = y;
	new_z = z * data->altitude;
	apply_rotation_y(&new_x, &new_y, data->cam.ry);
	apply_rotation_x(&new_y, &new_z, data->cam.rx);
	apply_rotation_z(&new_x, &new_y, data->cam.rz);
	r.x = new_x;
	r.y = new_y;
	r.z = new_z;
	apply_projection(&p, &r, data);
	p.x = (int)round(p.x);
	p.y = (int)round(p.y);
	p.z = new_z;
	p.color = data->colors[y][x];
	return (p);
}

void	draw_connections(t_fdf *data, int x, int y)
{
	t_point	p1;
	t_point	p2;

	p1 = get_point(x, y, data->map[y][x], data);
	if (x < data->max_x - 1)
	{
		p2 = get_point(x + 1, y, data->map[y][x + 1], data);
		draw_line(data, p1, p2);
	}
	if (y < data->max_y - 1)
	{
		p2 = get_point(x, y + 1, data->map[y + 1][x], data);
		draw_line(data, p1, p2);
	}
}

void	draw_map(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->max_y)
	{
		x = 0;
		while (x < data->max_x)
		{
			draw_connections(data, x, y);
			x++;
		}
		y++;
	}
}

void	put_pixel(t_fdf *data, int x, int y, int color)
{
	if (x >= 0 && x < data->width && y >= 0 && y < data->height)
	{
		*(int *)(data->addr + (y * data->line_length
					+ x * (data->bits_per_pixel / 8))) = color;
	}
}
