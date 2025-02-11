/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:23:13 by tgoossen          #+#    #+#             */
/*   Updated: 2025/02/10 16:40:09 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"
#include "../../libs/libft/include/libft.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	init_path(char *line, char **texture)
{
	size_t	len;

	if (*texture != NULL)
	{
		ft_printf_fd(2, "Error\n double path: %s\n", line);
		return (1);
	}
	while (*line && *line != ' ')
		line++;
	while (*line && *line == ' ')
		line++;
	*texture = ft_strdup(line);
	if (*texture == NULL)
		return (0);
	len = ft_strlen(*texture);
	if (len < 4 || strcmp(*texture + len - 4, ".png") != 0)
	{
		free(*texture);
		*texture = NULL;
		ft_printf_fd(2, "Error\n incorrect texture format: %s\n", line);
		return (1);
	}
	return (SUCCESS);
}

int	parse_color_value(char **line, int *value)
{
	*value = 0;
	if (!(**line >= '0' && **line <= '9'))
		return (1);
	while (**line >= '0' && **line <= '9')
	{
		*value = *value * 10 + (**line - '0');
		(*line)++;
	}
	if (*value < 0 || *value > 255)
		return (1);
	return (0);
}

int	parse_color_component(char **line, int *color, int index)
{
	int	value;

	if (parse_color_value(line, &value))
		return (1);
	color[index] = value;
	if (index < 2)
	{
		if (**line != ',')
			return (1);
		(*line)++;
	}
	return (0);
}

int	parse_color(char *line, int *color)
{
	int	i;

	i = 0;
	while (*line && *line != ' ')
		line++;
	while (*line && *line == ' ')
		line++;
	while (i < 3)
	{
		if (parse_color_component(&line, color, i))
			return (1);
		i++;
	}
	while (*line && *line == ' ')
		line++;
	if (*line != '\0')
		return (1);
	return (SUCCESS);
}

int	init_parse_data(t_parse_data *map_data)
{
	map_data->ea_texture = NULL;
	map_data->no_texture = NULL;
	map_data->we_texture = NULL;
	map_data->so_texture = NULL;
	if (init_texpath(map_data->input_file, map_data) != SUCCESS)
	{
		ft_printf_fd(2, "Invalid texture path\n");
		return (1);
	}
	if (check_if_init(map_data) != SUCCESS)
	{
		ft_printf_fd(2,
			"Error\nNot all texture paths or colors are initialized\n");
		return (1);
	}
	if (check_map(map_data) != SUCCESS)
	{
		printf("Error\nmap not valid\n");
		free_textures(map_data);
		return (1);
	}
	return (SUCCESS);
}
