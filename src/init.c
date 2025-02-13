/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:15:14 by gaboidin          #+#    #+#             */
/*   Updated: 2025/02/13 17:38:11 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_fdf	*init_fdf(void)
{
	t_fdf	*data;
	int		init_result;

	data = malloc(sizeof(t_fdf));
	if (!data)
		return (NULL);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		free(data);
		return (NULL);
	}
	data->width = 1600;
	data->height = 900;
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width, data->height,
			"FdF");
	if (!data->win_ptr)
	{
		free(data);
		return (NULL);
	}
	init_result = init_fdf_2(data);
	if (init_result == 0)
		return (NULL);
	return (data);
}

int	init_fdf_2(t_fdf *data)
{
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->width, data->height);
	if (!data->img_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data);
		return (0);
	}
	data->addr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->scale = 20;
	data->offset_x = data->width / 2;
	data->offset_y = data->height / 4;
	data->color.r = 255;
	data->color.g = 255;
	data->color.b = 255;
	data->altitude = 1;
	data->cam.rx = 0;
	data->cam.ry = 0;
	data->cam.rz = 0;
	data->max_x = 0;
	data->max_y = 0;
	data->min_z = 0;
	data->max_z = 0;
	data->projection = 0;
	return (1);
}

void	print_legend(t_fdf *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 10, 0x4C4178,
		"Move: W A S D");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 30, 0x4C4178,
		"RGB Color: R G B C");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 50, 0x4C4178,
		"Zoom: + / -");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 70, 0x4C4178,
		"Rotate: Up / Left / Right / Down / Q / E");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 90, 0x4C4178,
		"Altitute: < / >");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 110, 0x4C4178,
		"Change projection type: P");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 130, 0x4C4178,
		"Exit: Esc");
	return ;
}
