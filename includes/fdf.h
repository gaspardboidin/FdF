/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:58:49 by gaboidin          #+#    #+#             */
/*   Updated: 2025/02/21 21:42:53 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "/home/gaboidin/42/minilibx/minilibx-linux/mlx.h"
# include <X11/X.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}			t_point;

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
}			t_color;

typedef struct s_cam
{
	double	rx;
	double	ry;
	double	rz;
}			t_cam;

typedef struct s_bresenham
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
}			t_bresenham;

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		altitude;
	int		width;
	int		height;
	int		**map;
	int		**colors;
	int		max_x;
	int		max_y;
	int		min_z;
	int		max_z;
	int		scale;
	int		offset_x;
	int		offset_y;
	int		projection;
	t_color	color;
	t_cam	cam;
}			t_fdf;

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_PLUS 61
# define KEY_MINUS 45
# define KEY_SIZEUP 46
# define KEY_SIZEDOWN 44
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_Q 113
# define KEY_E 101
# define KEY_R 114
# define KEY_G 103
# define KEY_B 98
# define KEY_C 99
# define KEY_P 112

// Declaration des fonctions
t_fdf		*init_fdf(void);
int			init_fdf_2(t_fdf *data);
void		print_legend(t_fdf *data);
int			exit_program(t_fdf *data);
int			handle_key(int key, t_fdf *data);
char		**ft_split(const char *s, char c);
int			parse_map(char *filename, t_fdf *data);
int			fill_map(char *filename, t_fdf *data);
int			fill_map_row(char *line, t_fdf *data, int row);
int			allocate_map(t_fdf *data);
int			count_columns(char *line);
int			parse_map(char *filename, t_fdf *data);
int			count_dimensions(char *filename, t_fdf *data);
void		draw_map(t_fdf *data);
void		put_pixel(t_fdf *data, int x, int y, int color);
void		apply_rotations(t_point *r, t_fdf *data);
void		apply_rotation_x(double *y, double *z, double rx);
void		apply_rotation_y(double *x, double *y, double ry);
void		apply_rotation_z(double *x, double *y, double rz);
void		draw_line(t_fdf *data, t_point p1, t_point p2);
void		get_direction(t_point p1, t_point p2, int *sx, int *sy);
void		apply_projection(t_point *p, t_point *r, t_fdf *data);
void		free_map_partial(int **map, int rows_allocated);
void		free_split(char **split);
void		free_map(int **map, int rows);
void		free_color_map(int **colors, int rows);
int			rgb_to_bgr(int color);
void		cleanup_parsing(t_fdf *data, int rows_allocated);
int			prepare_map_row(char *line, t_fdf *data, int row, char ***psplit);

#endif