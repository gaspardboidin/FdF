/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:56:20 by gaboidin          #+#    #+#             */
/*   Updated: 2025/02/13 15:02:18 by gaboidin         ###   ########.fr       */
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
