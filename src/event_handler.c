/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:23:47 by gaboidin          #+#    #+#             */
/*   Updated: 2025/02/13 15:54:49 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// Gère les déplacements avec W A S D.
int	move_map(int key, t_fdf *data)
{
	int	move_speed;

	move_speed = 10;
	if (key == KEY_A)
		data->offset_x += move_speed;
	else if (key == KEY_D)
		data->offset_x -= move_speed;
	else if (key == KEY_W)
		data->offset_y += move_speed;
	else if (key == KEY_S)
		data->offset_y -= move_speed;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->width, data->height);
	data->addr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	draw_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	print_legend(data);
	return (0);
}

int	update_scale(int key, t_fdf *data)
{
	if (key == KEY_PLUS && data->scale < 100)
		data->scale += 2;
	else if (key == KEY_MINUS && data->scale > 2)
		data->scale -= 2;
	else
		return (0);
	return (1);
}

int	zoom_map(int key, t_fdf *data)
{
	int	scale_updated;

	scale_updated = update_scale(key, data);
	if (scale_updated == 0)
		return (0);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->width, data->height);
	data->addr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	draw_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	print_legend(data);
	return (0);
}

int	change_altitude(int key, t_fdf *data)
{
	if (key == KEY_SIZEUP)
		data->altitude += 1;
	else if (key == KEY_SIZEDOWN)
		data->altitude -= 1;
	else
		return (0);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->width, data->height);
	data->addr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	draw_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	print_legend(data);
	return (0);
}

int	rotate_map(int key, t_fdf *data)
{
	double	rotation_step;

	rotation_step = 0.05;
	if (key == KEY_LEFT)
		data->cam.ry -= rotation_step;
	else if (key == KEY_RIGHT)
		data->cam.ry += rotation_step;
	else if (key == KEY_UP)
		data->cam.rx -= rotation_step;
	else if (key == KEY_DOWN)
		data->cam.rx += rotation_step;
	else if (key == KEY_Q)
		data->cam.rz -= rotation_step;
	else if (key == KEY_E)
		data->cam.rz += rotation_step;
	else
		return (0);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->width, data->height);
	data->addr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	draw_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	print_legend(data);
	return (0);
}
