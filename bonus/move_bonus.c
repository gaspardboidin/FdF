/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:50:02 by gaboidin          #+#    #+#             */
/*   Updated: 2025/02/20 12:32:26 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/fdf_bonus.h"

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
