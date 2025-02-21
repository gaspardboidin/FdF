/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maping2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:41:37 by gaboidin          #+#    #+#             */
/*   Updated: 2025/02/21 21:02:27 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	fill_map(char *filename, t_fdf *data)
{
	int		fd;
	char	*line;
	int		row;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	row = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!fill_map_row(line, data, row))
		{
			free(line);
			close(fd);
			cleanup_parsing(data, row);
			return (0);
		}
		free(line);
		row++;
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

static int	error_prepare(t_fdf *data, char ***psplit, int row)
{
	free_split(*psplit);
	cleanup_parsing(data, row);
	return (0);
}

static int	error_alloc(t_fdf *data, char ***psplit, int row)
{
	if (data->map[row])
		free(data->map[row]);
	if (data->colors[row])
		free(data->colors[row]);
	free_split(*psplit);
	cleanup_parsing(data, row);
	return (0);
}

int	prepare_map_row(char *line, t_fdf *data, int row, char ***psplit)
{
	int	actual_cols;
	int	i;

	*psplit = ft_split(line, ' ');
	if (!(*psplit))
		return (0);
	actual_cols = 0;
	i = 0;
	while ((*psplit)[i])
	{
		actual_cols = actual_cols + 1;
		i++;
	}
	if (actual_cols < data->max_x)
		return (error_prepare(data, psplit, row));
	data->map[row] = malloc(sizeof(int) * data->max_x);
	data->colors[row] = malloc(sizeof(int) * data->max_x);
	if (!data->map[row] || !data->colors[row])
		return (error_alloc(data, psplit, row));
	return (1);
}
