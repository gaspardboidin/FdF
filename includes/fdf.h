/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:58:49 by gaboidin          #+#    #+#             */
/*   Updated: 2025/02/13 17:33:02 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>  // Pour malloc, free
# include <stdio.h>   // Pour printf (debug)
# include "../libft/libft.h" // Pour mes propres fonctions
# include <unistd.h>  // Pour close, read
# include <fcntl.h>   // Pour open (fichiers .fdf)
# include <math.h>    // Pour sin, cos (rotations)
# include "mlx.h"     // MiniLibX

// Structure représentant un point dans l'espace 3D.
// Ce sera utilisé pour transformer les coordonnées de la carte.
typedef struct s_point
{
    int     x;  // Coordonnée X (horizontale)
    int     y;  // Coordonnée Y (verticale)
    int     z;  // Coordonnée Z (altitude)
    int     color;
} t_point;


// Structure représentant une couleur en RGB.
// On l'utilisera pour gérer la couleur des lignes de fil de fer.
typedef struct s_color
{
    int r;  // Rouge (0-255)
    int g;  // Vert (0-255)
    int b;  // Bleu (0-255)
} t_color;

// Structure représentant la caméra et la rotation.
// Permet d'appliquer une rotation à la carte.
typedef struct s_cam
{
    double rx;  // Rotation autour de l'axe X (inclinaison)
    double ry;  // Rotation autour de l'axe Y (vue latérale)
    double rz;  // Rotation autour de l'axe Z (rotation sur elle-même)
} t_cam;

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}	t_bresenham;

// Structure principale contenant toutes les informations de la carte et de l'affichage.
typedef struct s_fdf
{
    void    *mlx_ptr; 
    void    *win_ptr;
    void    *img_ptr;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    int     altitude;
    int     width;
    int     height;
    int     **map;
    int     max_x;
    int     max_y;
    int     min_z;
    int     max_z;
    int     scale;
    int     offset_x;
    int     offset_y;
    int     projection;
    int     dynamic_color;
    t_color color;
    t_cam   cam;
} t_fdf;

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
# define KEY_LEFT 123  // Flèche gauche
# define KEY_RIGHT 124  // Flèche droite
# define KEY_Q 12   // Touche Q
# define KEY_E 14   // Touche E
# define KEY_R 15   // Lettre R pour Rouge
# define KEY_G 5    // Lettre G pour Vert
# define KEY_B 11   // Lettre B pour Bleu
# define KEY_C 8  // Touche pour remettre la couleur en blanc
# define KEY_P 35  // 🔄 Basculer entre isométrique et parallèle
# define KEY_L 37  // Touche L pour activer/désactiver les couleurs dynamiques

// Declaration des fonctions
t_fdf   *init_fdf(void);
int     init_fdf_2(t_fdf *data);
void    print_legend(t_fdf *data);
int     exit_program(t_fdf *data);
int     move_map(int key, t_fdf *data);
int     zoom_map(int key, t_fdf *data);
int     handle_key(int key, t_fdf *data);
char	**ft_split(const char *s, char c);
int     parse_map(char *filename, t_fdf *data);
int     fill_map(char *filename, t_fdf *data);
void    fill_map_row(char *line, t_fdf *data, int row);
int     allocate_map(t_fdf *data);
int     count_columns(char *line);
int     parse_map(char *filename, t_fdf *data);
int     count_dimensions(char *filename, t_fdf *data);
void    draw_map(t_fdf *data);
void    put_pixel(t_fdf *data, int x, int y, int color);
int     hange_color(int key, t_fdf *data);
int	    update_color(int key, t_fdf *data);
int	    change_altitude(int key, t_fdf *data);
int	    rotate_map(int key, t_fdf *data);
void	apply_rotations(t_point *r, t_fdf *data);
void    apply_rotation_x(double *y, double *z, double rx);
void    apply_rotation_y(double *x, double *y, double ry);
void    apply_rotation_z(double *x, double *y, double rz);
void	draw_line(t_fdf *data, t_point p1, t_point p2);
void    get_direction(t_point p1, t_point p2, int *sx, int *sy);
void    apply_projection(t_point *p, double new_x, double new_y, double new_z, t_fdf *data);
# endif