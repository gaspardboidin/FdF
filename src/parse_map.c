/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:56:20 by gaboidin          #+#    #+#             */
/*   Updated: 2025/02/14 13:22:18 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	parse_map(char *filename, t_fdf *data)
{
	int	result;

	result = count_dimensions(filename, data);
	if (result == 0)
		return (0);
	result = allocate_map(data);
	if (result == 0)
		return (0);
	result = fill_map(filename, data);
	if (result == 0)
		return (0);
	return (1);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_map_partial(int **map, int rows_allocated)
{
	int	i;

	i = 0;
	while (i < rows_allocated)
	{
		free(map[i]);
		i++;
	}
}

void	free_map(int **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
