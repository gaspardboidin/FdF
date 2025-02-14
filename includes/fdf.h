/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:58:49 by gaboidin          #+#    #+#             */
/*   Updated: 2025/02/14 13:19:36 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "mlx.h"
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
	int		max_x;
	int		max_y;
	int		min_z;
	int		max_z;
	int		scale;
	int		offset_x;
	int		offset_y;
	int		projection;
	int		dynamic_color;
	t_color	color;
	t_cam	cam;
}			t_fdf;

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_PLUS 24
# define KEY_MINUS 27
# define KEY_SIZEUP 47
# define KEY_SIZEDOWN 43
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123 // Flèche gauche
# define KEY_RIGHT 124 // Flèche droite
# define KEY_Q 12 // Touche Q
# define KEY_E 14 // Touche E
# define KEY_R 15 // Lettre R pour Rouge
# define KEY_G 5 // Lettre G pour Vert
# define KEY_B 11 // Lettre B pour Bleu
# define KEY_C 8 // Touche pour remettre la couleur en blanc
# define KEY_P 35 // 🔄 Basculer entre isométrique et parallèle
# define KEY_L 37 // Touche L pour activer/désactiver les couleurs dynamiques

// Declaration des fonctions
t_fdf		*init_fdf(void);
int			init_fdf_2(t_fdf *data);
void		print_legend(t_fdf *data);
int			exit_program(t_fdf *data);
int			move_map(int key, t_fdf *data);
int			zoom_map(int key, t_fdf *data);
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
int			hange_color(int key, t_fdf *data);
int			update_color(int key, t_fdf *data);
int			change_altitude(int key, t_fdf *data);
int			rotate_map(int key, t_fdf *data);
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

#endif