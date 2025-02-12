/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:30:00 by tgoossen          #+#    #+#             */
/*   Updated: 2025/02/11 15:19:34 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"
#include "../../libs/libft/include/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	longest_line(char **map)
{
	int	i;
	int	max_length;
	int	temp_length;

	i = 0;
	max_length = 0;
	while (map[i])
	{
		temp_length = strlen(map[i]);
		if (temp_length > max_length)
			max_length = temp_length;
		i++;
	}
	return (max_length);
}

char	*map_zero_fill(int length)
{
	char	*line;
	int		i;

	line = (char *)malloc((length + 1) * sizeof(char));
	if (!line)
	{
		perror("Malloc failed");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < length)
	{
		line[i] = ' ';
		i++;
	}
	line[length] = '\0';
	return (line);
}

char	*allocate_and_fill_line(char *old_line, int length)
{
	int		j;
	char	*new_line;

	new_line = (char *)malloc((length + 1) * sizeof(char));
	if (new_line == NULL)
	{
		perror("Malloc failed");
		exit(EXIT_FAILURE);
	}
	new_line[0] = ' ';
	j = 0;
	while (old_line[j])
	{
		new_line[j + 1] = old_line[j];
		j++;
	}
	while (j < length - 1)
	{
		new_line[j + 1] = ' ';
		j++;
	}
	new_line[length - 1] = ' ';
	new_line[length] = '\0';
	return (new_line);
}

char	**allocate_new_map(int height, int length)
{
	char	**newmap;

	newmap = (char **)malloc((height + 3) * sizeof(char *));
	if (newmap == NULL)
	{
		perror("Malloc failed");
		exit(EXIT_FAILURE);
	}
	newmap[0] = map_zero_fill(length);
	newmap[height + 1] = map_zero_fill(length);
	newmap[height + 2] = NULL;
	return (newmap);
}

char	**fill_map(char **oldmap, int height)
{
	int		i;
	int		l;
	char	**newmap;

	l = longest_line(oldmap) + 2;
	newmap = allocate_new_map(height, l);
	i = 0;
	while (i < height)
	{
		newmap[i + 1] = allocate_and_fill_line(oldmap[i], l);
		i++;
	}
	return (newmap);
}
