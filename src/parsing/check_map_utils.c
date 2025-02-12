/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:35:42 by tgoossen          #+#    #+#             */
/*   Updated: 2025/02/11 15:18:50 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"
#include "../../libs/libft/include/libft.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	init_floor_ceiling(char *line, int *color)
{
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
		return (init_path(line, &map_data->no_texture));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (init_path(line, &map_data->so_texture));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (init_path(line, &map_data->we_texture));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (init_path(line, &map_data->ea_texture));
	if (ft_strncmp(line, "F ", 2) == 0)
		return (init_floor_ceiling(line, map_data->ceiling_color));
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (init_floor_ceiling(line, map_data->floor_color));
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
	if (map_data->no_texture == NULL || map_data->so_texture == NULL
		|| map_data->we_texture == NULL || map_data->ea_texture == NULL
		|| !map_data->floor_color[0] || !map_data->ceiling_color[0])
		return (1);
	return (SUCCESS);
}

void	free_textures(t_parse_data *map_data)
{
	if (map_data->ea_texture)
		free(map_data->ea_texture);
	if (map_data->no_texture)
		free(map_data->no_texture);
	if (map_data->we_texture)
		free(map_data->we_texture);
	if (map_data->so_texture)
		free(map_data->so_texture);
}
