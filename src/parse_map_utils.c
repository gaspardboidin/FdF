/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:35:47 by gaboidin          #+#    #+#             */
/*   Updated: 2025/02/13 15:12:32 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// Compte le nombre de colonnes dans une ligne.
int	count_columns(char *line)
{
	int		count;
	char	**split;
	int		i;

	count = 0;
	split = ft_split(line, ' ');
	if (!split)
		return (0);
	while (split[count])
		count++;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (count);
}

// Compte le nombre de lignes et colonnes dans le fichier .fdf.
int	count_dimensions(char *filename, t_fdf *data)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	data->max_y = 0;
	data->max_x = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (data->max_x == 0)
			data->max_x = count_columns(line);
		data->max_y++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

// Alloue la memoire pour la map
int	allocate_map(t_fdf *data)
{
	data->map = malloc(sizeof(int *) * data->max_y);
	if (!data->map)
		return (0);
	return (1);
}

// Remplit une ligne de 'map' a partir du fichier .fdf
void	fill_map_row(char *line, t_fdf *data, int row)
{
	char	**split;
	int		col;

	split = ft_split(line, ' ');
	if (!split)
		return ;
	data->map[row] = malloc(sizeof(int) * data->max_x);
	if (!data->map[row])
		return ;
	col = 0;
	while (col < data->max_x)
	{
		data->map[row][col] = ft_atoi(split[col]);
		free(split[col]);
		col++;
	}
	free(split);
}

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
		fill_map_row(line, data, row);
		free(line);
		row++;
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}
