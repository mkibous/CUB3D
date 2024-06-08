/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 00:12:49 by aitaouss          #+#    #+#             */
/*   Updated: 2024/06/08 00:56:03 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    init_textures(t_textures *textures)
{
    textures->path = NULL;
    textures->img = NULL;
    textures->width = 0;
    textures->height = 0;
    textures->addr = NULL;
    textures->bpp = 0;
    textures->mlx_texture = NULL;
    textures->size_l = 0;
    textures->endian = 0;
}

unsigned int get_texture_pixel(t_textures *textures, int x, int y)
{
    int bytes_per_pixel = textures->bpp / 8; // bytes per pixel (3 for 24 BPP, 4 for 32 BPP)
    int offset = (y * textures->size_l) + (x * bytes_per_pixel);
    unsigned char *pixel = (unsigned char *)textures->addr + offset;

    if (bytes_per_pixel == 4)
    {
        // 32 BPP (RGBA)
        return *(unsigned int*)pixel;
    } else if (bytes_per_pixel == 3)
    {
        // 24 BPP (RGB)
        unsigned int color = 0;
        color |= pixel[2] << 16; // Red
        color |= pixel[1] << 8;  // Green
        color |= pixel[0];       // Blue
        return color;
    }
    return 0; // Default in case of unsupported BPP
}

void    fille_img_addr(t_data *vars, t_textures *textures)
{
    textures->path = vars->alloc->no_path;
    textures->img = mlx_xpm_file_to_image(vars->mlx, textures->path, &textures->width, &textures->height);
    if (textures->img == NULL)
        print_err_exit("Texture not found", vars->alloc);
    textures->addr = mlx_get_data_addr(textures->img, &textures->bpp, &textures->size_l, &textures->endian);
}
