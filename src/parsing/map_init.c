/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:28:05 by tgoossen          #+#    #+#             */
/*   Updated: 2025/02/11 15:13:39 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"
#include "../../libs/libft/include/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	is_enclosed_zero(char **map, int i, int j, int map_size[2])
{
	if (i > 0 && (map[i - 1][j] == ' ' || map[i - 1][j] == '\t'))
		return (1);
	if (i < map_size[0] - 1 && (map[i + 1][j] == ' ' || map[i + 1][j] == '\t'))
		return (1);
	if (j > 0 && (map[i][j - 1] == ' ' || map[i][j - 1] == '\t'))
		return (1);
	if (j < map_size[1] - 1 && (map[i][j + 1] == ' ' || map[i][j + 1] == '\t'))
		return (1);
	if (i > 0 && j > 0 && (map[i - 1][j - 1] == ' ' || map[i - 1][j
		- 1] == '\t'))
		return (1);
	if (i > 0 && j < map_size[1] - 1 && (map[i - 1][j + 1] == ' ' || map[i
			- 1][j + 1] == '\t'))
		return (1);
	if (i < map_size[0] - 1 && j > 0 && (map[i + 1][j - 1] == ' ' || map[i
			+ 1][j - 1] == '\t'))
		return (1);
	if (i < map_size[0] - 1 && j < map_size[1] - 1 && (map[i + 1][j + 1] == ' '
		|| map[i + 1][j + 1] == '\t'))
		return (1);
	return (0);
}

int	is_enclosed_player(char **map, int i, int j, int map_size[2])
{
	if (i > 0 && (map[i - 1][j] == ' ' || map[i - 1][j] == '\t'))
		return (1);
	if (i < map_size[0] - 1 && (map[i + 1][j] == ' ' || map[i + 1][j] == '\t'))
		return (1);
	if (j > 0 && (map[i][j - 1] == ' ' || map[i][j - 1] == '\t'))
		return (1);
	if (j < map_size[1] - 1 && (map[i][j + 1] == ' ' || map[i][j + 1] == '\t'))
		return (1);
	if (i > 0 && j > 0 && (map[i - 1][j - 1] == ' ' || map[i - 1][j
		- 1] == '\t'))
		return (1);
	if (i > 0 && j < map_size[1] - 1 && (map[i - 1][j + 1] == ' ' || map[i
			- 1][j + 1] == '\t'))
		return (1);
	if (i < map_size[0] - 1 && j > 0 && (map[i + 1][j - 1] == ' ' || map[i
			+ 1][j - 1] == '\t'))
		return (1);
	if (i < map_size[0] - 1 && j < map_size[1] - 1 && (map[i + 1][j + 1] == ' '
		|| map[i + 1][j + 1] == '\t'))
		return (1);
	return (0);
}

int	check_enclosed_zeros(char **map, int map_size[2])
{
	int	i;
	int	j;

	i = 0;
	while (i < map_size[0])
	{
		j = 0;
		map_size[1] = strlen(map[i]);
		while (j < map_size[1])
		{
			if ((map[i][j] == '0' && is_enclosed_zero(map, i, j, map_size))
				|| ((map[i][j] == 'E' || map[i][j] == 'W' || map[i][j] == 'S'
						|| map[i][j] == 'N') && is_enclosed_player(map, i, j,
						map_size)))
				return (1);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	is_surrounded_by_walls(char **map, int map_height)
{
	char	**temp_map;
	int		map_size[2];

	map_size[0] = map_height;
	temp_map = fill_map(map, map_height);
	if (check_enclosed_zeros(temp_map, map_size) != SUCCESS)
	{
		ft_free_matrix(temp_map);
		return (1);
	}
	ft_free_matrix(temp_map);
	return (SUCCESS);
}

int	check_map(t_parse_data *map_data)
{
	int	i;
	int	map_height;

	i = check_i_map(map_data->input_file);
	map_height = 0;
	while (map_data->input_file[i + map_height])
		map_height++;
	if (check_valid_char(map_data->input_file, map_height, i))
		return (1);
	if (has_valid_starting_position(map_data->input_file + i, map_height,
			map_data) != SUCCESS)
		return (1);
	if (is_surrounded_by_walls(map_data->input_file + i, map_height) != SUCCESS)
	{
		printf("Map is not surrounded by walls\n");
		return (1);
	}
	return (SUCCESS);
}
