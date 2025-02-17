/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:35:42 by tgoossen          #+#    #+#             */
/*   Updated: 2025/02/17 13:39:59 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"
#include "../../libs/libft/include/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	init_floor_ceiling(char *line, int *color)
{
	if (color[0] != -1)
	{
		ft_printf_fd(2, "Error\nDouble path: %s\n", line);
		return (1);
	}
	if (parse_color(line, color) != SUCCESS)
	{
		ft_printf_fd(2, "Error\nInvalid floor/ceiling color\n");
		return (1);
	}
	return (SUCCESS);
}

int	init_texture(char *line, t_parse_data *map_data)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (init_path(line, &map_data->texture_paths[NORTH]));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (init_path(line, &map_data->texture_paths[SOUTH]));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (init_path(line, &map_data->texture_paths[WEST]));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (init_path(line, &map_data->texture_paths[EAST]));
	if (ft_strncmp(line, "F ", 2) == 0)
		return (init_floor_ceiling(line, map_data->floor_color));
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (init_floor_ceiling(line, map_data->ceiling_color));
	return (SUCCESS);
}

int	init_texpath(char **map, t_parse_data *map_data)
{
	int	i;

	i = 0;
	while (map[i] && is_not_map(map[i]))
	{
		if (init_texture(map[i], map_data) != SUCCESS)
			return (1);
		i++;
	}
	return (SUCCESS);
}

int	check_if_init(t_parse_data *map_data)
{
	if (map_data->texture_paths[NORTH] == NULL
		|| map_data->texture_paths[SOUTH] == NULL
		|| map_data->texture_paths[WEST] == NULL
		|| map_data->texture_paths[EAST] == NULL
		|| map_data->floor_color[0] == -1
		|| map_data->ceiling_color[0] == -1)
		return (1);
	return (SUCCESS);
}

void	free_textures(t_parse_data *map_data)
{
	if (map_data->texture_paths[NORTH])
		free(map_data->texture_paths[NORTH]);
	if (map_data->texture_paths[SOUTH])
		free(map_data->texture_paths[SOUTH]);
	if (map_data->texture_paths[WEST])
		free(map_data->texture_paths[WEST]);
	if (map_data->texture_paths[EAST])
		free(map_data->texture_paths[EAST]);
}
