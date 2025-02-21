/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:21:41 by gaboidin          #+#    #+#             */
/*   Updated: 2025/02/21 21:12:19 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	cleanup_map(t_fdf *data, char **split, int row)
{
	free_split(split);
	free_map_partial(data->map, row);
	free(data->map);
	data->map = NULL;
}

static void	parse_token(char *token, int *altitude, int *color_val, t_fdf *data)
{
	char	*color_str;

	color_str = ft_strchr(token, ',');
	if (color_str != NULL)
	{
		*color_str = '\0';
		color_str++;
		*altitude = ft_atoi(token);
		if (ft_strncmp(color_str, "0x", 2) == 0
			|| ft_strncmp(color_str, "0X", 2) == 0)
			color_str = color_str + 2;
		*color_val = ft_atoi_base(color_str, "0123456789ABCDEF");
	}
	else
	{
		*altitude = ft_atoi(token);
		*color_val = ((data->color.r << 16) | (data->color.g << 8)
				| data->color.b);
	}
}

int	fill_map_row_data(t_fdf *data, int row, char **split)
{
	int		col;
	char	*token;

	col = 0;
	while (col < data->max_x)
	{
		token = split[col];
		parse_token(token, &data->map[row][col],
			&data->colors[row][col], data);
		free(token);
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

int	rgb_to_bgr(int color)
{
	int	r;
	int	g;
	int	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = (color) & 0xFF;
	return ((b << 16) | (g << 8) | r);
}
