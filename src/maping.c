/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:21:41 by gaboidin          #+#    #+#             */
/*   Updated: 2025/02/14 13:39:35 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	cleanup_map(t_fdf *data, char **split, int row)
{
	free_split(split);
	free_map_partial(data->map, row);
	free(data->map);
	data->map = NULL;
}

static int	prepare_map_row(char *line, t_fdf *data, int row, char ***psplit)
{
	int	actual_cols;

	*psplit = ft_split(line, ' ');
	if (!*psplit)
		return (0);
	actual_cols = 0;
	while ((*psplit)[actual_cols])
		actual_cols++;
	if (actual_cols < data->max_x)
	{
		cleanup_map(data, *psplit, row);
		return (0);
	}
	data->map[row] = malloc(sizeof(int) * data->max_x);
	if (!data->map[row])
	{
		cleanup_map(data, *psplit, row);
		return (0);
	}
	return (1);
}

static int	fill_map_row_data(t_fdf *data, int row, char **split)
{
	int	col;

	col = 0;
	while (col < data->max_x)
	{
		data->map[row][col] = ft_atoi(split[col]);
		free(split[col]);
		col++;
	}
	return (1);
}

int	fill_map_row(char *line, t_fdf *data, int row)
{
	char	**split;

	split = NULL;
	if (!prepare_map_row(line, data, row, &split))
		return (0);
	fill_map_row_data(data, row, split);
	free(split);
	return (1);
}
