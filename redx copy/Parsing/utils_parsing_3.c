/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:25:41 by aitaouss          #+#    #+#             */
/*   Updated: 2024/06/06 18:37:10 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strlen_2d_d(char **str)
{
	int	i;
	int	j;
	int	count;

	(1) && (i = -1, j = 0, count = 0);
	while (str[++i])
	{
		j = 0;
		while (str[i][j])
		{
			count++;
			j++;
		}
	}
	return (count);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i > 0 && str[i - 1] && str[i - 1] == ',')
		{
			if (ft_isdigit(str[i]) == 0 && str[i] != ',')
				return (0);
		}
		i++;
	}
	return (1);
}

char	**ft_strdup_2d(char **str)
{
	int		i;
	char	**tmp;

	i = 0;
	while (str[i])
		i++;
	tmp = malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (str[++i])
		tmp[i] = ft_strdup(str[i]);
	tmp[i] = NULL;
	return (tmp);
}

void	print_element_map(t_alloc *alloc)
{
	printf("Element-------\n");
	print_2d(alloc->element);
	printf("Map-------\n");
	print_2d(alloc->map);
}

void	check_invalid_elem(t_alloc *alloc, int i, int j)
{
	while (alloc->element[i])
	{
		if (ft_strncmp(alloc->element[i], "F", 1) == 0)
			j++;
		if (ft_strncmp(alloc->element[i], "C", 1) == 0)
			j++;
		if (ft_strncmp(alloc->element[i], "NO", 2) == 0)
			j++;
		if (ft_strncmp(alloc->element[i], "SO", 2) == 0)
			j++;
		if (ft_strncmp(alloc->element[i], "WE", 2) == 0)
			j++;
		if (ft_strncmp(alloc->element[i], "EA", 2) == 0)
			j++;
		i++;
	}
	if (j > 6)
		print_err_exit("Element : There is a duplicate", alloc);
	if (j < 6)
		print_err_exit("Element : Invalid element", alloc);
}
