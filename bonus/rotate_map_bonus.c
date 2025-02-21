/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:45:23 by gaboidin          #+#    #+#             */
/*   Updated: 2025/02/20 11:47:39 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/fdf_bonus.h"

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
