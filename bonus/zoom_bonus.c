/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:43:11 by gaboidin          #+#    #+#             */
/*   Updated: 2025/02/20 11:47:54 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/fdf_bonus.h"

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
