/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:11:50 by aitaouss          #+#    #+#             */
/*   Updated: 2024/07/15 15:26:49 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	check_imposter(t_alloc *alloc, int i, int j, int flag)
{
	if (alloc->map[0] == NULL)
		print_err_exit("Map Invalid : Map empty", alloc);
	while (alloc->map[++i])
	{
		j = 0;
		while (alloc->map[i][j] != '\0' && alloc->map[i][j] == '\n' && flag)
		{
			i++;
			if (alloc->map[i] == NULL)
				print_err_exit("Map Invalid : Map With just new line", alloc);
		}
		flag = 0;
		if (alloc->map[i][j] == '\n')
			print_err_exit("Map Invalid : New line detected", alloc);
		while (alloc->map[i][j])
		{
			if (alloc->map[i][j] != '1' && alloc->map[i][j] != '0'
				&& alloc->map[i][j] != ' '
				&& alloc->map[i][j] != 'S' && alloc->map[i][j] != 'N'
				&& alloc->map[i][j] != 'W' && alloc->map[i][j] != 'D'
				&& alloc->map[i][j] != 'E' && alloc->map[i][j] != '\n')
				print_err_exit("Map Invalid : Unknown symbol", alloc);
			j++;
		}
	}
}

void	check_valid_map(char *tmp, t_alloc *alloc)
{
	int	i;
	int	j;
	int	store;

	j = 0;
	i = 0;
	free_2d(alloc->split);
	alloc->split = ft_split(tmp, '\n');
	while (alloc->split[i] && alloc->split[i][0] == '\n')
		i++;
	store = i;
	while (alloc->split[i])
	{
		j = 0;
		while (alloc->split[i][j] && store == i)
		{
			if (alloc->split[i][j] != '1' && alloc->split[i][j] != ' ')
			{
				free(tmp);
				print_err_exit("Map not closed in first line", alloc);
			}
			j++;
		}
		i++;
	}
}

void	check_player(char *tmp, t_alloc *alloc)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tmp[i])
	{
		if (tmp[i] == 'W' || tmp[i] == 'E' || tmp[i] == 'S' || tmp[i] == 'N')
		{
			alloc->player = tmp[i];
			count++;
		}
		i++;
	}
	if (count == 0)
		print_err_exit("Map Invalid : Need one player", alloc);
	if (count > 1)
		print_err_exit("Map Invalid : One player only", alloc);
}

void	check_last_line(char *tmp, t_alloc *alloc)
{
	int	i;
	int	len;

	i = 0;
	free_2d(alloc->map);
	alloc->map = ft_split(tmp, '\n');
	len = ft_strlen_2d(alloc->map);
	while (alloc->map[len - 1][i])
	{
		if (alloc->map[len -1][i] != '1' && alloc->map[len -1][i] != ' ')
		{
			free(tmp);
			print_err_exit("Map Invalid : Map not closed in last line", alloc);
		}
		i++;
	}
}

void	check_map(t_alloc *alloc)
{
	int		i;
	char	*tmp;

	tmp = malloc(sizeof(char) * ft_strlen_2d_d(alloc->map) + 1);
	if (!tmp)
		print_err_exit("Malloc failed in Check_map", alloc);
	i = -1;
	check_imposter(alloc, -1, 0, 1);
	while (alloc->map[++i])
	{
		free(alloc->tmp);
		alloc->tmp = ft_strdup(tmp);
		free(tmp);
		tmp = ft_strjoin(alloc->tmp, alloc->map[i]);
		if (!tmp)
			print_err_exit("Malloc failed in Join Check_map", alloc);
	}
	check_valid_map(tmp, alloc);
	check_player(tmp, alloc);
	check_last_line(tmp, alloc);
	free(tmp);
	check_arround(alloc);
}
