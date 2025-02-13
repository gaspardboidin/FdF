/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:24:09 by gaboidin          #+#    #+#             */
/*   Updated: 2025/02/13 17:37:56 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// Ferme proprement la fenêtre et libère la mémoire.
int	exit_program(t_fdf *data)
{
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	free(data);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;
	int		parsing;

	if (argc != 2)
		return (1);
	data = init_fdf();
	if (!data)
		return (1);
	data->map = NULL;
	parsing = parse_map(argv[1], data);
	if (!parsing)
		return (1);
	draw_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	print_legend(data);
	mlx_hook(data->win_ptr, 2, 1L << 0, handle_key, data);
	mlx_hook(data->win_ptr, 17, 0, exit_program, data);
	mlx_loop(data->mlx_ptr);
}
