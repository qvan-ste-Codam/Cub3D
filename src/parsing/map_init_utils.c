/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:28:46 by tgoossen          #+#    #+#             */
/*   Updated: 2025/02/11 15:17:32 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"
#include "../../libs/libft/include/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	check_i_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] && is_not_map(map[i]))
		i++;
	return (i);
}

int	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ' || c == '\t');
}

void	cam_xy(int y, int x, char var, t_parse_data *map_data)
{
	map_data->start_pos_x = x;
	map_data->start_pos_y = y;
	if (var == 'N')
	{
		map_data->view_direction = NORTH;
	}
	else if (var == 'S')
	{
		map_data->view_direction = SOUTH;
	}
	else if (var == 'E')
	{
		map_data->view_direction = EAST;
	}
	else if (var == 'W')
	{
		map_data->view_direction = WEST;
	}
}

int	has_valid_starting_position(char **map, int map_height,
		t_parse_data *map_data)
{
	int	x;
	int	y;
	int	start_count;

	x = 0;
	y = 0;
	start_count = 0;
	while (y < map_height)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E'
				|| map[y][x] == 'W')
			{
				cam_xy(x, y, map[y][x], map_data);
				start_count++;
			}
			if (start_count > 1)
				return (1);
			x++;
		}
		y++;
	}
	return (SUCCESS);
}

int	check_valid_char(char **map, int map_height, int i)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < map_height)
	{
		x = 0;
		while (map[i + y][x])
		{
			if (!is_valid_map_char(map[i + y][x]))
				return (1);
			x++;
		}
		y++;
	}
	return (SUCCESS);
}
