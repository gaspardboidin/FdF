/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:54:59 by gaboidin          #+#    #+#             */
/*   Updated: 2025/02/20 12:36:58 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

int	change_altitude(int key, t_fdf *data);
int	change_color(int key, t_fdf *data);
int	set_color(t_color *color, int r, int g, int b);
int	update_color(int key, t_fdf *data);
int	move_map(int key, t_fdf *data);
int	rotate_map(int key, t_fdf *data);
int	zoom_map(int key, t_fdf *data);
int	update_scale(int key, t_fdf *data);

#endif