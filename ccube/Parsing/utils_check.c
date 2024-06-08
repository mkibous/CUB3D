/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 01:16:38 by aitaouss          #+#    #+#             */
/*   Updated: 2024/06/08 01:21:50 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	join_double_pointer(t_alloc *alloc, char **tmp, char **tmp_2)
{
	int	i;

	i = -1;
	while (alloc->map[++i])
	{
		free(*tmp_2);
		*tmp_2 = NULL;
		*tmp_2 = ft_strdup(*tmp);
		free(*tmp);
		*tmp = ft_strjoin(*tmp_2, alloc->map[i]);
		if (!tmp)
			print_err_exit("Malloc failed", alloc);
		if (alloc->map[i + 1] == NULL)
			free(*tmp_2);
	}
}

int	count_line(t_alloc *alloc)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(alloc->map_path, O_RDONLY);
	if (fd == -1)
		print_err_exit("Error in opening Map file", alloc);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (i);
}
