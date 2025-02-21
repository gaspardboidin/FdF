/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:47:14 by gaboidin          #+#    #+#             */
/*   Updated: 2025/02/20 11:47:34 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/fdf_bonus.h"

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
