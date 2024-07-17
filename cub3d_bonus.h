/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:06:47 by mkibous           #+#    #+#             */
/*   Updated: 2024/07/17 13:10:46 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
#define CUB3D_BONUS_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE INT_MAX
#endif
#include "libft/libft.h"
#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <limits.h>
#include <stddef.h>

#define FOV 60
#define FOV_ANGLE (FOV * (M_PI / 180))

// define color
#define RESET "\033[0m"
#define RESOLVE 100000
#define RED "\033[1;31m"
#define G "\033[1;32m"
#define Y "\033[1;33m"
#define B "\033[1;34m"
#define M "\033[1;35m"
#define C "\033[1;36m"
#define W "\033[1;37m"

typedef struct s_alloc t_alloc;
typedef struct s_data t_data;
#define POV 1.0471975512
#define TILE 50
#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 720
#define MINIMAP_WIDTH 14
// mkibous
typedef struct s_data
{
	char	**map;
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	int		map_tsize;
	int		med;
	int		control;
	double	x;
	double	y;
	double	hx;
	double	hy;
	double	vx;
	double	vy;
	double	wallx;
	double	wally;
	double	wallhit;
	int		hit_index;
	int		xs;
	int		ys;
	int		xstep;
	int		ystep;
	double	hc;
	double	vc;
	double	an;
	double	view;
	double	angle;
	double	speed;
	void	*img;
	char	*addr;
	int		bpp;
	int		size_l;
	int		endian;
	void	*img_map;
	char	*addr_map;
	int		bpp_map;
	int		size_lmap;
	int		endian_map;
	double	up_down_x;
	double	up_down_y;
	double	lr_x;
	double	lr_y;
	double	view_speed;
	double	c;
	int		px_x;
	double	al;
	int		color;
	int		w;
	int		a;
	int		s;
	int		d;
	double	wall_height;
	t_alloc	*alloc;
	int		mouse_on;
	int		door;
} t_data;

typedef struct s_alloc
{
	char	**file;
	int		end_element;
	char	**element;
	char	**map;
	char	*map_path;
	char	**split;
	char	*tmp;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	player;
	int		*rgb_c;
	int		*rgb_f;
	int		color_c;
	int		color_f;
} t_alloc;

void ft_execute(t_alloc *alloc);
void ft_map(t_data *vars);
int ft_player(t_data *vars);
void ft_draw_ray(t_data *vars);
void ft_wall(t_data *vars, int x, int y, int color);
int ft_check_wall(t_data *vars, double x, double y, int wall);
int ft_open_door(t_data *vars);
int ft_close_door(t_data *vars);

// aitaouss
void get_map(t_alloc *alloc);
char *get_next_line(int fd);
char *ft_strjoin_next(char *line, char *buff);
char *ft_strchr_next(char *s, int c);
size_t ft_strlen_next(char *s);
char *ft_getline(char *line);
char *readline(int fd, char *line);
char *ft_newline(char *line);
void loop_check_first(t_alloc *alloc, int *i, int *check, int count);
void check_first_elem(t_alloc *alloc);
void check_f_c(t_alloc *alloc);

// utils
void free_2d(char **str);
int ft_strlen_2d(char **str);
char *skip_space(char *str, int flag);
int count_virgule(char *str);
int check_digit(char **str);
void print_err_exit(char *str, t_alloc *alloc);
void print_2d(char **str);
int check_space(char *str);
char **convert_tabs_space(char **str);
void check_space_and_open(char *str, char *element);
int ft_strlen_2d_d(char **str);
int is_number(char *str);
char **ft_strdup_2d(char **str);
void print_element_map(t_alloc *alloc);
void check_invalid_elem(t_alloc *alloc, int i, int j);
void check_closed(t_alloc *alloc, int flag, int i, int j);
void check_arround(t_alloc *alloc);

// clear
void out_clean(t_alloc *alloc);

// check elem
void check_element_we(t_alloc *alloc, int i);
void check_element_so(t_alloc *alloc, int i);
void check_element_ea(t_alloc *alloc, int i);
void check_element_no(t_alloc *alloc, int i);

// Map
void check_map(t_alloc *alloc);

#endif