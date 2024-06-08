/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:08:09 by mkibous           #+#    #+#             */
/*   Updated: 2024/06/08 16:52:50 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
float ft_get_angle(char c)
{
	if (c == 'N')
		return (M_PI_2);
	if (c == 'S')
		return ((3 * M_PI) / 2);
	if (c == 'E')
		return (0);
	if (c == 'W')
		return (M_PI);
	return (0);
}
void ft_get_size(t_data *vars)
{
	int i;
	int j;
	int max;
	int len;

	i = 0;
	max = 0;
	while (vars->map[i])
	{
		j = 0;
		len = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'N' || vars->map[i][j] == 'S' || vars->map[i][j] == 'E' || vars->map[i][j] == 'W')
			{
				vars->view = ft_get_angle(vars->map[i][j]);
				(1) && (vars->x = j, vars->y = i);
				vars->map[i][j] = '0';
				(1) && (vars->x += 0.5, vars->y += 0.5);
			}
			len++;
			j++;
		}
		if (len > max)
			max = len;
		i++;
	}
	vars->width = max;
	vars->height = i;
}
int ft_close(t_data *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}
int ft_check(t_data *vars, float add_x, float add_y)
{
	int sx;
	int sy;
	int a;
	int b;

	if (add_x < (float)0)
		sx = 1;
	else
		sx = -1;
	if (add_y < (float)0)
		sy = 1;
	else
		sy = -1;
	if (vars->y + add_y < 0 || vars->y + add_y > vars->height)
		return (1);
	if (vars->x + add_x < 0 || vars->x + add_x > vars->width)
		return (1);
	if (vars->map[(int)(vars->y + add_y)][(int)(vars->x + add_x)] != '0')
		return (1);
	if (vars->map[(int)(vars->y + add_y)][(int)(vars->x + add_x)] == '0')
	{
		if (vars->map[(int)(vars->y + add_y + sy)][(int)(vars->x + add_x)] == '1' && vars->map[(int)(vars->y + add_y)][(int)(vars->x + add_x + sx)] == '1')
		{
			a = (int)vars->y;
			b = (int)(vars->y + add_y + (0.001 * sy));
			if (a == b)
				return (0);
			a = (int)vars->x;
			b = (int)(vars->x + add_x + (0.001 * sx));
			if (a == b)
				return (0);
			return (1);
		}
	}
	return (0);
}
void ft_w(t_data *vars)
{
	vars->add_x = ((cos(vars->view) * 0.07));
	vars->add_y = ((sin(vars->view) * 0.07));
}
void ft_s(t_data *vars)
{
	vars->add_x = cos((vars->view + M_PI)) * 0.07;
	vars->add_y = sin(vars->view + M_PI) * 0.07;
}
void ft_d(t_data *vars)
{
	vars->add_x = cos((vars->view + (M_PI / 2))) * 0.07;
	vars->add_y = sin((vars->view + (M_PI / 2))) * 0.07;
}
void ft_a(t_data *vars)
{
	vars->add_x = cos((vars->view - (M_PI / 2))) * 0.07;
	vars->add_y = sin((vars->view - (M_PI / 2))) * 0.07;
}

int ft_key(int key, t_data *vars)
{
	if (key == 13)
		vars->w = 1;
	if (key == 1)
		vars->s = 1;
	if (key == 0)
		vars->a = 1;
	if (key == 2)
		vars->d = 1;
	if (key == 124)
	{
		vars->add_a = 0.03;
	}
	if (key == 123)
	{
		vars->add_a = -0.03;
	}
	if (key == 53)
		ft_close(vars);
	return (0);
}
int ft_rel(int key, t_data *vars)
{
	if (key == 13 || key == 1 || key == 0 || key == 2)
	{
		vars->add_x = 0;
		vars->add_y = 0;
	}
	if (key == 13)
		vars->w = 0;
	if (key == 1)
		vars->s = 0;
	if (key == 0)
		vars->a = 0;
	if (key == 2)
		vars->d = 0;
	if (key == 123 || key == 124)
		vars->add_a = 0;
	return (0);
	return (0);
}
void my_pixel_put(t_data *vars, int x, int y, int color)
{
	char *dst;

	dst = vars->addr + (y * vars->size_l + x * (vars->bpp / 8));
	*(unsigned int *)dst = color;
}
void my_pixel_put2(t_data *vars, int x, int y, int color)
{
	char *dst;

	dst = vars->addr2 + (y * vars->size_l2 + x * (vars->bpp2 / 8));
	*(unsigned int *)dst = color;
}
int ft_checkmed(t_data *vars)
{
	if ((int)vars->x_r == vars->xrm)
		return (0);
	return (1);
}

void ft_get_color(t_data *vars, int *color)
{
	float a;
	float b;
	// int n = 0x2d5a4b;
	// int s = 0x6F00FF;
	int e = 0x4E88A4;
	int w = 0x7F8E72;

	a = vars->x_r - ((int)(vars->x_r + 0.1));
	b = vars->y_r - ((int)(vars->y_r + 0.1));

	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	// if(a == b)
	// {
	//     if(h >= vars->prev_h - 4 && h <= vars->prev_h + 4)
	//         *color = vars->prev_color;
	//     return;}
	// if(vars->x3  == 1)
	// {
	//     printf("a = %f\n", a);
	//     printf("b = %f\n", b);
	//     if(a > b)
	//         printf("s\n");
	//     exit(0);
	// }
	if ((int)((a * 10) + 0.01) == (int)((b * 10) + 0.01))
	{
		*color = 0x000000;
		return;
	}
	*color = 0x000000;
	if (sin(vars->view) > 0)
	{
		if (cos(vars->view) > 0)
		{
			if (a > (b + 0.001))
				vars->wall_side = 's';
			else if ((a + 0.001) < b)
				*color = e;
			else
				*color = 0x000000;
		}
		else if (cos(vars->view) < 0)
		{
			if (a > (b + 0.001))
				vars->wall_side = 's';
			else if ((a + 0.001) < b)
				*color = w;
			else
				*color = 0x000000;
		}
	}
	else if (sin(vars->view) < 0)
	{
		if (cos(vars->view) > 0)
		{
			if (a > b)
				vars->wall_side = 'n';
			else if (a < b)
				*color = e;
			else
				*color = 0x000000;
		}
		else
		{
			if (a > b)
				vars->wall_side = 'n';
			else if (a < b)
				*color = w;
			else
				*color = 0x000000;
		}
	}
}
// void ft_drawline(t_data *vars, int x, int y, int color, int h2)
// {
//     int j = 0;

//     while (j < h2)
//     {
//         if(x < 0)
//             x = 0;
//         if(x >= vars->width * vars->size)
//             x = (vars->width * vars->size) - 1;
//         if(y < 0)
//             y = 0;
//         if(y >= vars->height * vars->size)
//             y = (vars->height * vars->size) - 1;
//         my_pixel_put(vars, x, y + j, color);
//         j++;
//     }
// }

// void ft_drawline(t_data *vars, int x, int y, int color, int h2)
// {
// 	int j = 0;

// 	while (j < h2)
// 	{
// 		if (x < 0)
// 			x = 0;
// 		if (x >= vars->width * vars->size)
// 			x = (vars->width * vars->size);
// 		if (y < 0)
// 			y = 0;
// 		if (y >= vars->height * vars->size)
// 			y = (vars->height * vars->size);
// 		my_pixel_put(vars, x, y + j, color);
// 		j++;
// 	}
// }
// int ft_checkblack(t_data *vars, int h)
// {
// 	if (h >= vars->r_black - 4 && h <= vars->r_black + 4)
// 		return (1);
// 	return (0);
// }
// void ft_draw_ray(t_data *vars)
// {
// 	float i;
// 	float j;
// 	int h = 0;
// 	int h2 = 0;
// 	float a;
// 	float b;
// 	float tmp;
// 	int color;

// 	i = 0;
// 	j = 0;
// 	while (1)
// 	{
// 		if (ft_check(vars, ((i) / (float)vars->size), ((j) / (float)vars->size)))
// 			break;
// 		my_pixel_put2(vars, (vars->x + (i / vars->size)) * vars->size2, (vars->y + (j / vars->size)) * vars->size2, 0x00FF00);
// 		i += (float)cos(vars->view);
// 		j += (float)sin(vars->view);
// 	}
// 	vars->x_r = vars->x + (i / (float)vars->size);
// 	vars->y_r = vars->y + (j / (float)vars->size);
// 	a = vars->x_r - vars->x;
// 	b = vars->y_r - vars->y;
// 	if (a < 0)
// 		a = -a;
// 	if (b < 0)
// 		b = -b;
// 	vars->c = sqrt((a * a) + (b * b)) * cos(vars->al);
// 	h2 = (((30) / vars->c) * 40);
// 	if (h2 > vars->height * vars->size)
// 		h2 = (vars->height * vars->size);
// 	vars->med = (float)(((vars->height * vars->size)) / 2);
// 	tmp = 0;
// 	h = (vars->med + (h2 / (float)2));
// 	tmp = h - h2;
// 	if (vars->x3 <= 0)
// 		vars->x3 = 0;
// 	ft_get_color(vars, &color);
// 	vars->prev_color = color;
// 	vars->prev_h = h2;
// 	if (color == 0x000000)
// 	{
// 		vars->black++;
// 		if (vars->f_black == 0)
// 			vars->r_black = h2;
// 		if (h2 > vars->r_black)
// 			vars->r_black = h2;
// 		if (vars->f_black == 0)
// 			vars->f_black = vars->x3;
// 		vars->prev_black = h2;
// 	}
// 	if ((color != 0x000000 && vars->black > 0))
// 	{
// 		// ft_drawline(vars, vars->f_black - (vars->black / 2), vars->med - (vars->r_black / 2), 0xFFFFFF, vars->r_black);
// 		vars->black = 0;
// 		vars->f_black = 0;
// 		vars->r_black = 0;
// 		vars->prev_black = 0;
// 	}
// 	// 9bl ma dkhol katkon fl tht d ray
// 	// vars. med - (h2 / 2) top
// 	init_textures(vars->textures);
// 	vars->textures->path = vars->alloc->no_path;
// 	vars->textures->img = mlx_xpm_file_to_image(vars->mlx, vars->textures->path, &vars->textures->width, &vars->textures->height);
// 	if (!vars->textures->img)
// 		print_err_exit("Texture : not found", vars->alloc);
// 	vars->textures->addr = mlx_get_data_addr(vars->textures->img, &vars->textures->bpp, &vars->textures->size_l, &vars->textures->endian);
// 	get_texture_pixel(vars->textures, 0, 0);
	// while (h >= vars->med - (h2 / 2) && h >= 0)
	// {
	// 	if (h < 0)
	// 		h = 0;
	// 	if (h >= vars->height * vars->size)
	// 		h = (int)(vars->height * vars->size) - 1;
	// 	if (vars->x3 < 0)
	// 		vars->x3 = 0;
	// 	if (vars->x3 >= vars->width * vars->size)
	// 		vars->x3 = (vars->width * vars->size);
	// 	// lbdya d render
	// 	my_pixel_put(vars, vars->x3, h, color);
	// 	h--;
	// }
// 	vars->x3 -= 1;
// }

void ft_draw_ray(t_data *vars)
{
    float i;
    float j;
    int h = 0;
    int h2 = 0;
    float a;
    float b;
    float tmp;
    int color;

    i = 0;
    j = 0;
    while (1)
    {
        if (ft_check(vars, ((i) / (float)vars->size), ((j) / (float)vars->size)))
            break;
        my_pixel_put2(vars, (vars->x + (i / vars->size)) * vars->size2, (vars->y + (j / vars->size)) * vars->size2, 0x00FF00);
        i += (float)cos(vars->view);
        j += (float)sin(vars->view);
    }
    vars->x_r = vars->x + (i / (float)vars->size);
    vars->y_r = vars->y + (j / (float)vars->size);
    a = vars->x_r - vars->x;
    b = vars->y_r - vars->y;
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    vars->c = sqrt((a * a) + (b * b)) * cos(vars->al);
    h2 = (((30) / vars->c) * 40);
    if (h2 > vars->height * vars->size)
        h2 = (vars->height * vars->size);
    vars->med = (float)(((vars->height * vars->size)) / 2);
    tmp = 0;
    h = (vars->med + (h2 / (float)2));
    tmp = h - h2;
    if (vars->x3 <= 0)
        vars->x3 = 0;
    ft_get_color(vars, &color);
    vars->prev_color = color;
    vars->prev_h = h2;
    if (color == 0x000000)
    {
        vars->black++;
        if (vars->f_black == 0)
            vars->r_black = h2;
        if (h2 > vars->r_black)
            vars->r_black = h2;
        if (vars->f_black == 0)
            vars->f_black = vars->x3;
        vars->prev_black = h2;
    }
    if ((color != 0x000000 && vars->black > 0))
    {
        vars->black = 0;
        vars->f_black = 0;
        vars->r_black = 0;
        vars->prev_black = 0;
    }
	int x_offset;
	int y_offset;

	x_offset = (vars->x_r - floor(vars->x_r)) * vars->size;
	y_offset = (vars->y_r - floor(vars->y_r)) * vars->size;
	if (vars->wall_side == 'n')
	{
    	get_texture_pixel(vars->textures, 0, 0);
    	while (h >= vars->med - (h2 / 2) && h >= 0)
    	{
    	    if (h < 0)
    	        h = 0;
    	    if (h >= vars->height * vars->size)
    	        h = (int)(vars->height * vars->size) - 1;
    	    if (vars->x3 < 0)
    	        vars->x3 = 0;
    	    if (vars->x3 >= vars->width * vars->size)
    	        vars->x3 = (vars->width * vars->size);
    	    int tex_x = (vars->x3 * vars->textures->width) / (vars->width * vars->size);
    	    int tex_y = ((h - vars->med + (h2 / 2)) * vars->textures->height) / (vars->height * vars->size);
    	    unsigned int color = get_texture_pixel(vars->textures, tex_x, tex_y);
    	    my_pixel_put(vars, vars->x3, h, color);
    	    h--;
    	}
		vars->wall_side = '0';
	}
	if (vars->wall_side == 's')
	{
    	get_texture_pixel(vars->textures, 0, 0);
    	while (h >= vars->med - (h2 / 2) && h >= 0)
    	{
    	    if (h < 0)
    	        h = 0;
    	    if (h >= vars->height * vars->size)
    	        h = (int)(vars->height * vars->size) - 1;
    	    if (vars->x3 < 0)
    	        vars->x3 = 0;
    	    if (vars->x3 >= vars->width * vars->size)
    	        vars->x3 = (vars->width * vars->size);
    	    int tex_x = (vars->x3 * vars->textures->width) / (vars->width * vars->size);
    	    int tex_y = ((h - vars->med + (h2 / 2)) * vars->textures->height) / (vars->height * vars->size);
    	    unsigned int color = get_texture_pixel(vars->textures, tex_x, tex_y);
    	    my_pixel_put(vars, vars->x3, h, color);
    	    h--;
    	}
		vars->wall_side = '0';
	}
	else
	{
		while (h >= vars->med - (h2 / 2) && h >= 0)
		{
			if (h < 0)
				h = 0;
			if (h >= vars->height * vars->size)
				h = (int)(vars->height * vars->size) - 1;
			if (vars->x3 < 0)
				vars->x3 = 0;
			if (vars->x3 >= vars->width * vars->size)
				vars->x3 = (vars->width * vars->size);
			// lbdya d render
			my_pixel_put(vars, vars->x3, h, color);
			h--;
		}
	}
    vars->x3 -= 1;
}

void ft_add(t_data *vars)
{
	if (vars->w)
		ft_w(vars);
	if (vars->s)
		ft_s(vars);
	if (vars->a)
		ft_a(vars);
	if (vars->d)
		ft_d(vars);
}
void ft_color(t_data *vars)
{
	int i;
	int j;

	i = 0;
	while (i < vars->width * vars->size)
	{
		j = 0;
		while (j < vars->height * vars->size)
		{
			if (j < vars->height * vars->size / 2)
				my_pixel_put(vars, i, j, vars->alloc->color_c);
			else
				my_pixel_put(vars, i, j, vars->alloc->color_f);
			j++;
		}
		i++;
	}
}
void ft_med(t_data *vars)
{
	float i;
	float j;
	float a;
	float b;

	i = 0;
	j = 0;
	vars->med_view = vars->view;
	while (1)
	{
		i += cos(vars->view);
		j += sin(vars->view);
		if (ft_check(vars, ((i + cos(vars->view)) / vars->size), ((j + sin(vars->view)) / vars->size)))
			break;
	}
	vars->x_r = vars->x + (i / vars->size);
	vars->y_r = vars->y + (j / vars->size);
	vars->xrm = vars->x_r;
	vars->yrm = vars->y_r;
	a = vars->x_r - vars->x;
	b = vars->y_r - vars->y;
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	vars->c = sqrt((a * a) + (b * b));
	if (vars->c < 0.1)
		vars->c = 0.1;
	vars->mid_ray = (((float)(30) / vars->c) * (float)50);
}
int ft_player(t_data *vars)
{
	int i;
	int j;
	float v;
	float tmp;

	vars->view += vars->add_a;
	ft_add(vars);
	if (ft_check(vars, vars->add_x, vars->add_y) == 0)
	{
		vars->x += vars->add_x;
		vars->y += vars->add_y;
	}
	ft_med(vars);
	tmp = vars->view - vars->angle / 2;
	v = vars->view;
	vars->view = v + vars->angle / 2;
	if (vars->img)
		mlx_destroy_image(vars->mlx, vars->img);
	if (vars->img2)
		mlx_destroy_image(vars->mlx, vars->img2);
	vars->img2 = mlx_new_image(vars->mlx, vars->width * vars->size2, vars->height * vars->size2);
	vars->addr2 = mlx_get_data_addr(vars->img2, &vars->bpp2, &vars->size_l2, &vars->endian2);
	vars->img = mlx_new_image(vars->mlx, vars->width * vars->size, vars->height * vars->size);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bpp, &vars->size_l, &vars->endian);
	ft_color(vars);
	vars->x3 = ((float)(vars->width * vars->size)) - 1;
	vars->prev_color = 0;
	while (tmp < vars->view)
	{
		vars->al = vars->view - vars->med_view;
		ft_draw_ray(vars);
		vars->view -= (((float)1) / (float)(((vars->width * vars->size))));
	}
	vars->view = v;
	i = -2;
	while (i < 3)
	{
		j = -2;
		while (j < 3)
		{
			my_pixel_put2(vars, (vars->x + (i / vars->size)) * vars->size2, (vars->y + (j / vars->size)) * vars->size2, 0xE87F83);
			j++;
		}
		i++;
	}
	ft_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img2, 0, 0);
	return (0);
}

void ft_wall(t_data *vars, int x, int y)
{
	int i;
	int j;

	i = 1;
	while (i < vars->size2 - 1)
	{
		j = 1;
		while (j < vars->size2 - 1)
		{
			my_pixel_put2(vars, (x * vars->size2) + i, (y * vars->size2) + j, 0xFFFFFFF);
			j++;
		}
		i++;
	}
}

void ft_map(t_data *vars)
{
	int i;
	int j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == '1')
			{
				ft_wall(vars, j, i);
			}
			j++;
		}
		i++;
	}
}

void ft_execute(t_alloc *alloc)
{
	t_data vars;

	ft_memset(&vars, 0, sizeof(t_data));
	vars.map = alloc->map;
	vars.alloc = alloc;
	vars.textures = alloc->textures;
	init_textures(vars.textures);
	ft_get_size(&vars);
	vars.mlx = mlx_init();
	vars.angle = M_PI / 3;
	vars.size = 40;
	vars.size2 = 10;
	vars.win = mlx_new_window(vars.mlx, vars.width * vars.size, vars.height * vars.size, "Cub3D");
	fille_img_addr(&vars, vars.textures);
	mlx_hook(vars.win, 17, 1, ft_close, &vars);
	mlx_hook(vars.win, 2, 1L << 0, ft_key, &vars);
	mlx_hook(vars.win, 3, 1L << 1, ft_rel, &vars);
	mlx_loop_hook(vars.mlx, ft_player, &vars);
	mlx_loop(vars.mlx);
}