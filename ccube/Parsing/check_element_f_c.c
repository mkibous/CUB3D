/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element_f_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:50:27 by aitaouss          #+#    #+#             */
/*   Updated: 2024/06/07 00:29:31 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_range_c(t_alloc *alloc, int storage)
{
	alloc->rgb_c[0] = storage;
	if (storage < 0 || storage > 255)
		print_err_exit("C : Out of Range {0,255}", alloc);
	storage = ft_atoi(alloc->split[1], 0);
	alloc->rgb_c[1] = storage;
	if (storage < 0 || storage > 255)
		print_err_exit("C : Out of Range {0,255}", alloc);
	storage = ft_atoi(alloc->split[2], 0);
	alloc->rgb_c[2] = storage;
	if (storage < 0 || storage > 255)
		print_err_exit("C : Out of Range {0,255}", alloc);
}

void	check_range_f(t_alloc *alloc, int storage)
{
	alloc->rgb_f[0] = storage;
	if (storage < 0 || storage > 255)
		print_err_exit("F : Out of Range {0,255}", alloc);
	storage = ft_atoi(alloc->split[1], 0);
	alloc->rgb_f[1] = storage;
	if (storage < 0 || storage > 255)
		print_err_exit("F : Out of Range {0,255}", alloc);
	storage = ft_atoi(alloc->split[2], 0);
	alloc->rgb_f[2] = storage;
	if (storage < 0 || storage > 255)
		print_err_exit("F : Out of Range {0,255}", alloc);
}

void	check_celling_color(t_alloc *alloc, int storage, int i)
{
	if (ft_strncmp(alloc->element[i], "C", 1) == 0)
	{
		if (count_virgule(alloc->element[i]) != 2)
			print_err_exit("C : Usage [0,0,0]", alloc);
		free(alloc->tmp);
		alloc->tmp = skip_space(alloc->element[i], 1);
		if (is_number(alloc->tmp) == 0)
			print_err_exit("C : Digit only", alloc);
		free_2d(alloc->split);
		alloc->split = ft_split(alloc->tmp, ',');
		if (!alloc->split)
			print_err_exit("Split Error", alloc);
		if (check_digit(alloc->split) == 0)
			print_err_exit("C : Digit only", alloc);
		storage = ft_atoi(alloc->split[0], 0);
		check_range_c(alloc, storage);
	}
}

void	check_floor_color(t_alloc *alloc, int storage, int i)
{
	if (ft_strncmp(alloc->element[i], "F", 1) == 0)
	{
		if (count_virgule(alloc->element[i]) != 2)
			print_err_exit("F : Usage [0,0,0]", alloc);
		free(alloc->tmp);
		alloc->tmp = skip_space(alloc->element[i], 1);
		if (is_number(alloc->tmp) == 0)
			print_err_exit("F : Digit only", alloc);
		free_2d(alloc->split);
		alloc->split = ft_split(alloc->tmp, ',');
		if (!alloc->split)
			print_err_exit("Split Error", alloc);
		if (check_digit(alloc->split) == 0)
			print_err_exit("F : Digit only", alloc);
		storage = ft_atoi(alloc->split[0], 0);
		check_range_f(alloc, storage);
	}
}

void	check_f_c(t_alloc *alloc)
{
	int		i;
	char	*tmp;
	int		storage;
	int		j;

	j = 0;
	tmp = NULL;
	i = 0;
	storage = 0;
	check_invalid_elem(alloc, i, j);
	while (alloc->element[i])
	{
		check_element_we(alloc, i);
		check_element_no(alloc, i);
		check_element_so(alloc, i);
		check_element_ea(alloc, i);
		check_floor_color(alloc, storage, i);
		check_celling_color(alloc, storage, i);
		i++;
	}
}
