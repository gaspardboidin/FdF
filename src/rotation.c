/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:18:31 by gaboidin          #+#    #+#             */
/*   Updated: 2025/02/13 17:33:40 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	apply_rotation_x(double *y, double *z, double rx)
{
	double	tmp_y;

	tmp_y = *y;
	*y = tmp_y * cos(rx) - *z * sin(rx);
	*z = tmp_y * sin(rx) + *z * cos(rx);
}

void	apply_rotation_y(double *x, double *y, double ry)
{
	double	tmp_x;

	tmp_x = *x;
	*x = tmp_x * cos(ry) + *y * sin(ry);
	*y = -tmp_x * sin(ry) + *y * cos(ry);
}

void	apply_rotation_z(double *x, double *y, double rz)
{
	double	tmp_x;

	tmp_x = *x;
	*x = tmp_x * cos(rz) - *y * sin(rz);
	*y = tmp_x * sin(rz) + *y * cos(rz);
}
