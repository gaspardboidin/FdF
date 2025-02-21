/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:56:15 by gaboidin          #+#    #+#             */
/*   Updated: 2025/02/21 20:57:42 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	cleanup_map(t_fdf *data, int rows_allocated)
{
	int	i;

	if (data->map)
	{
		i = 0;
		while (i < rows_allocated)
		{
			if (data->map[i])
				free(data->map[i]);
			i++;
		}
		free(data->map);
		data->map = NULL;
	}
}

static void	cleanup_colors(t_fdf *data, int rows_allocated)
{
	int	i;

	if (data->colors)
	{
		i = 0;
		while (i < rows_allocated)
		{
			if (data->colors[i])
				free(data->colors[i]);
			i++;
		}
		free(data->colors);
		data->colors = NULL;
	}
}

void	cleanup_parsing(t_fdf *data, int rows_allocated)
{
	cleanup_map(data, rows_allocated);
	cleanup_colors(data, rows_allocated);
}
