/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:06:44 by mkibous           #+#    #+#             */
/*   Updated: 2024/07/15 15:27:57 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void    init_alloc(t_alloc *alloc, char **argv)
{
	alloc->file = NULL;
	alloc->end_element = 0;
	alloc->element = NULL;
	alloc->map = NULL;
	alloc->map_path = ft_strdup(argv[1]);
	alloc->split = NULL;
	alloc->tmp = NULL;
	alloc->ea_path = NULL;
	alloc->so_path = NULL;
	alloc->we_path = NULL;
	alloc->no_path = NULL;
	alloc->player = 0;
	alloc->rgb_c = malloc(sizeof(int) * 3);
	alloc->rgb_f = malloc(sizeof(int) * 3);
	alloc->color_c = 0;
	alloc->color_f = 0;
}

void	f()
{
	system("leaks cub3D");
}

void	print_stat(t_alloc *alloc, int i)
{
	printf("Map-------------\n");
	while (alloc->map[i])
	{
		printf("%s\n", alloc->map[i]);
		i++;
	}
	printf("Element------------\n");
	print_2d(alloc->element);
	printf("RGB_F------------\n");
	printf("%d\n", alloc->rgb_f[0]);
	printf("%d\n", alloc->rgb_f[1]);
	printf("%d\n", alloc->rgb_f[2]);
	printf("RGB_C------------\n");
	printf("%d\n", alloc->rgb_c[0]);
	printf("%d\n", alloc->rgb_c[1]);
	printf("%d\n", alloc->rgb_c[2]);
	printf("Color_c------------\n");
	printf("%d\n", alloc->color_c);
	printf("Color_f------------\n");
	printf("%d\n", alloc->color_f);
	printf("Path------------\n");
	printf("NO : %s\n", alloc->no_path);
	printf("SO : %s\n", alloc->so_path);
	printf("WE : %s\n", alloc->we_path);
	printf("EA : %s\n", alloc->ea_path);
}

void	check_extension(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] != 'b' || str[i - 2] != 'u' || str[i - 3] != 'c' || str[i - 4] != '.')
	{
		printf(RED"Error\n"W"Invalid extension\n");
		exit(1);
	}
}

int    main(int argc, char **argv)
{
	// (void)argc;
	// (void)argv;
	t_alloc *alloc;

	// atexit(f);
	if (argc != 2)
	{
		printf(RED"Error\n"W"Invalid number of arguments\n");
		return (1);
	}
	check_extension(argv[1]);
	alloc = malloc(sizeof(t_alloc));
	init_alloc(alloc, argv);
	get_map(alloc);
	// print_stat(alloc, 0);
	ft_execute(alloc);
	out_clean(alloc);
	return (0);
}
