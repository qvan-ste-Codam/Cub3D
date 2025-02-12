/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:39:32 by tgoossen          #+#    #+#             */
/*   Updated: 2025/02/12 16:51:10 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"
#include "../../libs/libft/include/libft.h"

int	is_not_map(char *line)
{
	static const char	*list[] = {"NO ", "SO ", "WE ",
		"EA ", "F ", "C ", NULL};
	int					i;

	i = 0;
	if (!line || line[0] == '\0' || line[0] == '\n')
		return (1);
	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	while (i < 6)
	{
		if (ft_strncmp(line, list[i], ft_strlen(list[i])) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ' || c == '\t');
}

void	ft_set_null(t_parse_data *map_data)
{
	map_data->ea_texture = NULL;
	map_data->no_texture = NULL;
	map_data->we_texture = NULL;
	map_data->so_texture = NULL;
	map_data->floor_color[0] = 0;
	map_data->floor_color[1] = 0;
	map_data->floor_color[2] = 0;
	map_data->ceiling_color[0] = 0;
	map_data->ceiling_color[1] = 0;
	map_data->ceiling_color[2] = 0;
}
