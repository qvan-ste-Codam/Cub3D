/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_init_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tgoossen <tgoossen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/11 14:28:46 by tgoossen      #+#    #+#                 */
/*   Updated: 2025/02/14 15:23:50 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	check_i_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] && is_not_map(map[i]))
		i++;
	return (i);
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

int	count_starting_positions(char **map, int map_height, t_parse_data *map_data)
{
	int	x;
	int	y;
	int	start_count;

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
			x++;
		}
		y++;
	}
	return (start_count);
}

int	has_valid_starting_position(char **map, int map_height,
		t_parse_data *map_data)
{
	int	start_count;

	start_count = count_starting_positions(map, map_height, map_data);
	if (start_count == 1)
		return (SUCCESS);
	else
		return (1);
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
