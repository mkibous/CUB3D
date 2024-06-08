/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:44:22 by aitaouss          #+#    #+#             */
/*   Updated: 2024/06/05 16:28:18 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	condition_loop(t_alloc *alloc, int *i, int *check)
{
	if (ft_strncmp(alloc->file[*i], "NO", 2) == 0
		&& alloc->file[*i][2] == ' ')
		*check += 1;
	else if (ft_strncmp(alloc->file[*i], "SO", 2) == 0
		&& alloc->file[*i][2] == ' ')
		*check += 1;
	else if (ft_strncmp(alloc->file[*i], "WE", 2) == 0
		&& alloc->file[*i][2] == ' ')
		*check += 1;
	else if (ft_strncmp(alloc->file[*i], "EA", 2) == 0
		&& alloc->file[*i][2] == ' ')
		*check += 1;
	else if (ft_strncmp(alloc->file[*i], "F", 1) == 0
		&& alloc->file[*i][1] == ' ')
		*check += 1;
	else if (ft_strncmp(alloc->file[*i], "C", 1) == 0
		&& alloc->file[*i][1] == ' ')
		*check += 1;
	else
		print_err_exit("Element : Invalid element", alloc);
}

void	loop_check_first(t_alloc *alloc, int *i, int *check, int count)
{
	while (alloc->file[(*i)])
	{
		if (count == 6)
			break ;
		if (alloc->file[*i][0] == '\n')
		{
			(*i)++;
			continue ;
		}
		condition_loop(alloc, i, check);
		(*i)++;
		count++;
	}
}

void	check_first_elem(t_alloc *alloc)
{
	int		i;
	int		check;
	int		fd;
	int		count;

	count = 0;
	fd = 0;
	check = 0;
	i = 0;
	loop_check_first(alloc, &i, &check, count);
	alloc->end_element = i;
	if (check > 6)
		print_err_exit("Element : Duplicate", alloc);
	if (check < 6)
		print_err_exit("Element : Missing element", alloc);
}
