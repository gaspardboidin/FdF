/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:24:09 by gaboidin          #+#    #+#             */
/*   Updated: 2025/02/21 20:04:40 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	exit_program(t_fdf *data)
{
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	if (data->map)
	{
		free_map(data->map, data->max_y);
		free_color_map(data->colors, data->max_y);
	}
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	get_next_line(-1);
	free(data);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;
	int		parsing;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./fdf <map_file.fdf>\n", 2);
		return (1);
	}
	data = init_fdf();
	if (!data)
		return (1);
	data->map = NULL;
	parsing = parse_map(argv[1], data);
	if (!parsing)
	{
		ft_putstr_fd("Error: Map vide ou mal formée.\n", 2);
		exit_program(data);
		return (1);
	}
	draw_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	print_legend(data);
	mlx_hook(data->win_ptr, 2, 1L << 0, handle_key, data);
	mlx_hook(data->win_ptr, 17, 0, exit_program, data);
	mlx_loop(data->mlx_ptr);
}
