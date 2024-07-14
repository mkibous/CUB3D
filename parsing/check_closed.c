/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:22:00 by aitaouss          #+#    #+#             */
/*   Updated: 2024/06/05 16:22:03 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_closed(t_alloc *alloc, int flag, int i, int j)
{
	if (flag)
	{
		if (alloc->map[i][j] == '0')
		{
			if (alloc->map[i][j + 1] == ' ' || alloc->map[i][j - 1] == ' '
				|| alloc->map[i + 1][j] == ' ' || alloc->map[i - 1][j] == ' '
				|| alloc->map[i][j + 1] == '\0' || alloc->map[i][j - 1] == '\0'
				|| alloc->map[i + 1][j] == '\0' || alloc->map[i - 1][j] == '\0')
				print_err_exit("Map Invalid : Floor not closed", alloc);
		}
	}
	else
	{
		if (alloc->map[i][j] == alloc->player)
		{
			if (alloc->map[i][j + 1] == ' ' || alloc->map[i][j - 1] == ' '
				|| alloc->map[i + 1][j] == ' ' || alloc->map[i - 1][j] == ' '
				|| alloc->map[i][j + 1] == '\0' || alloc->map[i][j - 1] == '\0'
				|| alloc->map[i + 1][j] == '\0' || alloc->map[i - 1][j] == '\0')
				print_err_exit("Map Invalid : Map not closed", alloc);
		}
	}
}

void	check_arround(t_alloc *alloc)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (alloc->map[++i])
	{
		j = -1;
		while (alloc->map[i][++j])
		{
			if (alloc->map[i][j] == '0')
				check_closed(alloc, 1, i, j);
			if (alloc->map[i][j] == alloc->player)
				check_closed(alloc, 0, i, j);
		}
	}
}
