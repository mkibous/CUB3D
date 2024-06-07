/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 00:12:49 by aitaouss          #+#    #+#             */
/*   Updated: 2024/06/07 19:32:34 by aitaouss         ###   ########.fr       */
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
