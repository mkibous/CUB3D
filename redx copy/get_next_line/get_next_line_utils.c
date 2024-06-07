/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:08:55 by aitaouss          #+#    #+#             */
/*   Updated: 2024/06/02 21:20:50 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

size_t	ft_strlen_next(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_next(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen_next(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin_next(char *line, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!line)
	{
		line = (char *)malloc(1 * sizeof(char));
		if (line)
			line[0] = '\0';
	}
	if (!line || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen_next(line) + ft_strlen_next(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (line)
		while (line[++i] != '\0')
			str[i] = line[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen_next(line) + ft_strlen_next(buff)] = '\0';
	free(line);
	return (str);
}
