/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:44:27 by aitaouss          #+#    #+#             */
/*   Updated: 2024/06/05 16:19:50 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	element_map(t_alloc *alloc, int i, int j)
{
	alloc->element = malloc(sizeof(char *) * 100);
	while (i < alloc->end_element)
	{
		alloc->element[i] = ft_strdup(alloc->file[i]);
		i++;
	}
	alloc->element[i] = NULL;
	alloc->map = malloc(sizeof(char *) * 100);
	while (alloc->file[i])
	{
		alloc->map[j] = ft_strdup(alloc->file[i]);
		i++;
		j++;
	}
	alloc->map[j] = NULL;
}

void	fill_file(t_alloc *alloc, char *line, int i, int fd)
{
	while (line != NULL)
	{
		alloc->file[i] = ft_strdup(line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	alloc->file[i] = NULL;
}

void	check_duplicate(t_alloc *alloc)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (alloc->element[i])
	{
		j = 0;
		while (alloc->element[j])
		{
			if (ft_strncmp(alloc->element[i], alloc->element[j], 2) == 0)
				count++;
			j++;
		}
		if (count > 1)
			print_err_exit("Element : There is a duplicate", alloc);
		count = 0;
		i++;
	}
}

void	get_color(t_alloc *alloc)
{
	alloc->color_c = (alloc->rgb_c[0] << 16)
		+ (alloc->rgb_c[1] << 8) + alloc->rgb_c[2];
	alloc->color_f = (alloc->rgb_f[0] << 16)
		+ (alloc->rgb_f[1] << 8) + alloc->rgb_f[2];
}

void	get_map(t_alloc *alloc)
{
	int		fd;
	char	*line;
	int		i;
	int		j;
	char	**tmp;

	alloc->file = malloc(sizeof(char *) * 100);
	(1) && (i = 0, j = 0);
	fd = open(alloc->map_path, O_RDONLY);
	if (fd == -1)
		print_err_exit("Error in opening Map file", alloc);
	line = get_next_line(fd);
	fill_file(alloc, line, i, fd);
	close(fd);
	tmp = ft_strdup_2d(alloc->file);
	free_2d(alloc->file);
	alloc->file = convert_tabs_space(tmp);
	free_2d(tmp);
	check_first_elem(alloc);
	element_map(alloc, 0, 0);
	check_f_c(alloc);
	check_duplicate(alloc);
	check_map(alloc);
	get_color(alloc);
}
