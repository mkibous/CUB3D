/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:22:35 by aitaouss          #+#    #+#             */
/*   Updated: 2024/06/08 01:20:31 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	out_clean(t_alloc *alloc)
{
	free_2d(alloc->element);
	free(alloc->map_path);
	free_2d(alloc->map);
	free_2d(alloc->file);
	free_2d(alloc->split);
	free(alloc->tmp);
	free(alloc->ea_path);
	free(alloc->so_path);
	free(alloc->we_path);
	free(alloc->no_path);
	free(alloc->rgb_c);
	free(alloc->rgb_f);
	free(alloc->textures);
	free(alloc);
}

void	check_element_we(t_alloc *alloc, int i)
{
	int	j;
	int	k;
	int	storage;

	storage = 0;
	k = 0;
	j = 3;
	if (ft_strncmp(alloc->element[i], "WE", 2) == 0)
	{
		while (alloc->element[i][j] == ' ')
			j++;
		k = j;
		while (alloc->element[i][j] != '\n')
		{
			j++;
			storage++;
		}
		free(alloc->tmp);
		alloc->tmp = ft_substr(alloc->element[i], k, storage);
		check_space_and_open(alloc->tmp, "WE");
		if (ft_strlen(alloc->tmp) < 2)
			print_err_exit("WE : Path too short", alloc);
		free(alloc->we_path);
		alloc->we_path = ft_strdup(alloc->tmp);
	}
}

void	check_element_no(t_alloc *alloc, int i)
{
	int	j;
	int	k;
	int	storage;

	storage = 0;
	k = 0;
	j = 3;
	if (ft_strncmp(alloc->element[i], "NO", 2) == 0)
	{
		while (alloc->element[i][j] == ' ')
			j++;
		k = j;
		while (alloc->element[i][j] != '\n')
		{
			j++;
			storage++;
		}
		free(alloc->tmp);
		alloc->tmp = ft_substr(alloc->element[i], k, storage);
		check_space_and_open(alloc->tmp, "NO");
		if (ft_strlen(alloc->tmp) < 2)
			print_err_exit("NO : Path too short", alloc);
		free(alloc->no_path);
		alloc->no_path = ft_strdup(alloc->tmp);
	}
}

void	check_element_so(t_alloc *alloc, int i)
{
	int	j;
	int	k;
	int	storage;

	storage = 0;
	k = 0;
	j = 3;
	if (ft_strncmp(alloc->element[i], "SO", 2) == 0)
	{
		while (alloc->element[i][j] == ' ')
			j++;
		k = j;
		while (alloc->element[i][j] != '\n')
		{
			j++;
			storage++;
		}
		free(alloc->tmp);
		alloc->tmp = ft_substr(alloc->element[i], k, storage);
		check_space_and_open(alloc->tmp, "SO");
		if (ft_strlen(alloc->tmp) < 2)
			print_err_exit("SO : Path too short", alloc);
		free(alloc->so_path);
		alloc->so_path = ft_strdup(alloc->tmp);
	}
}

void	check_element_ea(t_alloc *alloc, int i)
{
	int	j;
	int	k;
	int	storage;

	storage = 0;
	k = 0;
	j = 3;
	if (ft_strncmp(alloc->element[i], "EA", 2) == 0)
	{
		while (alloc->element[i][j] == ' ')
			j++;
		k = j;
		while (alloc->element[i][j] != '\n')
		{
			j++;
			storage++;
		}
		free(alloc->tmp);
		alloc->tmp = ft_substr(alloc->element[i], k, storage);
		check_space_and_open(alloc->tmp, "EA");
		if (ft_strlen(alloc->tmp) < 2)
			print_err_exit("EA : Path too short", alloc);
		free(alloc->ea_path);
		alloc->ea_path = ft_strdup(alloc->tmp);
	}
}
