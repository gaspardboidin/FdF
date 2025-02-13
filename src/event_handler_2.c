/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:32:41 by gaboidin          #+#    #+#             */
/*   Updated: 2025/02/13 15:54:46 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	change_color(int key, t_fdf *data)
{
	int	check;

	check = update_color(key, data);
	if (!check)
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

int	switch_projection(int key, t_fdf *data)
{
	if (key == KEY_P)
	{
		data->projection = (data->projection + 1) % 2;
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		data->img_ptr = mlx_new_image(data->mlx_ptr, data->width, data->height);
		data->addr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel,
				&data->line_length, &data->endian);
		draw_map(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0,
			0);
		print_legend(data);
	}
	return (0);
}

// Gère les touches du clavier.
int	handle_key(int key, t_fdf *data)
{
	if (key == KEY_ESC)
		exit_program(data);
	else if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		move_map(key, data);
	else if (key == KEY_PLUS || key == KEY_MINUS)
		zoom_map(key, data);
	else if (key == KEY_SIZEUP || key == KEY_SIZEDOWN)
		change_altitude(key, data);
	else if (key == KEY_R || key == KEY_G || key == KEY_B || key == KEY_C)
		change_color(key, data);
	else if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_Q || key == KEY_E
		|| key == KEY_UP || key == KEY_DOWN)
		rotate_map(key, data);
	else if (key == KEY_P)
		switch_projection(key, data);
	return (0);
}

int	set_color(t_color *color, int r, int g, int b)
{
	color->r = r;
	color->g = g;
	color->b = b;
	return (1);
}

int	update_color(int key, t_fdf *data)
{
	if (key == KEY_R)
		return (set_color(&data->color, 255, 0, 0));
	else if (key == KEY_G)
		return (set_color(&data->color, 0, 255, 0));
	else if (key == KEY_B)
		return (set_color(&data->color, 0, 0, 255));
	else if (key == KEY_C)
		return (set_color(&data->color, 255, 255, 255));
	return (0);
}
