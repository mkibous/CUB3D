/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:06:47 by mkibous           #+#    #+#             */
/*   Updated: 2024/06/08 16:54:21 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE INT_MAX
# endif
# include "libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>
# include <stddef.h>

# define FOV 60
# define FOV_ANGLE (FOV * (M_PI / 180))

// define color
# define RESET    "\033[0m"
# define RED	"\033[1;31m"
# define G      "\033[1;32m"
# define Y      "\033[1;33m"
# define B      "\033[1;34m"
# define M      "\033[1;35m"
# define C      "\033[1;36m"
# define W      "\033[1;37m"

typedef struct  s_alloc t_alloc;
typedef struct  s_data t_data;
typedef struct  s_textures t_textures;

//mkibous
typedef struct  s_data
{
    char **map;
    void    *mlx;
    void    *win;
    int     height;
    int     width;
    int    size;
    int    size2;
    float  med;
    float   x;
    float   y;
    float   view;
    float   angle;
    float   speed;
    void   *img;
    char *addr;
    int   bpp;
    int   size_l;
    int   endian;
    void *img2;
    char *addr2;
    int   bpp2;
    int   size_l2;
    int   endian2;
    float add_x;
    float add_y;
    float add_a;
    float view_x;
    int key;
    float x_r;
    float y_r;
    float c;
    float x3;
    int fix;
    float med_view;
    float al;
    float mid_ray;
    int xrm;
    int yrm;
    int xp;
    int yp;
    float prevz;
    int color;
    int prev_h;
    int prev_color;
    int w;
    int a;
    int s;
    int d;
    int black;
    int f_black;
    int r_black;
    int prev_black;
    char wall_side;
    t_alloc *alloc;
    t_textures  *textures;
}               t_data;

typedef struct	s_alloc
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
    t_textures  *textures;
}				t_alloc;

typedef struct s_textures
{
    char    *path;
    void    *img;
    void    *mlx_texture;
    char    *addr;
    int     bpp;
    int     size_l;
    int     endian;
    int     width;
    int     height;
    int     color;
    int     x;
    int     y;
}            t_textures;

void    ft_execute(t_alloc *alloc);
void    ft_map(t_data *vars);
int     ft_player(t_data *vars);
void    ft_draw_ray(t_data *vars);
void    ft_wall(t_data *vars, int x, int y);

//aitaouss
void    get_map(t_alloc *alloc);
char	*get_next_line(int fd);
char	*ft_strjoin_next(char *line, char *buff);
char	*ft_strchr_next(char *s, int c);
size_t	ft_strlen_next(char *s);
char	*ft_getline(char *line);
char	*readline(int fd, char *line);
char	*ft_newline(char *line);
void	loop_check_first(t_alloc *alloc, int *i, int *check, int count);
void    check_first_elem(t_alloc *alloc);
void	check_f_c(t_alloc *alloc);

// utils
void	free_2d(char **str);
int		ft_strlen_2d(char **str);
char	*skip_space(char *str, int flag);
int		count_virgule(char *str);
int		check_digit(char **str);
void	print_err_exit(char *str, t_alloc *alloc);
void	print_2d(char **str);
int		check_space(char *str);
char    **convert_tabs_space(char **str);
void    check_space_and_open(char *str, char *element);
int		ft_strlen_2d_d(char **str);
int		is_number(char *str);
char	**ft_strdup_2d(char **str);
void	print_element_map(t_alloc *alloc);
void	check_invalid_elem(t_alloc *alloc, int i, int j);
void	check_closed(t_alloc *alloc, int flag, int i, int j);
void	check_arround(t_alloc *alloc);
void	join_double_pointer(t_alloc *alloc, char **tmp, char **tmp_2);
int     count_line(t_alloc *alloc);

// clear
void	out_clean(t_alloc *alloc);

// check elem
void	check_element_we(t_alloc *alloc, int i);
void	check_element_so(t_alloc *alloc, int i);
void	check_element_ea(t_alloc *alloc, int i);
void	check_element_no(t_alloc *alloc, int i);

// textures
void        init_textures(t_textures *textures);
unsigned int get_texture_pixel(t_textures *textures, int x, int y);
void        fille_img_addr(t_data *vars, t_textures *textures);

// Map
void    check_map(t_alloc *alloc);

#endif