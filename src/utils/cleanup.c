/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:35:12 by qvan-ste          #+#    #+#             */
/*   Updated: 2025/02/12 16:39:38 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"
#include "../../libs/libft/include/libft.h"
#include <stdlib.h>

static void	free_lines(t_display *display)
{
	int				i;
	t_line			*lines;
	t_ray			*ray;
	t_texture_props	*texture_props;

	i = 0;
	lines = display -> lines;
	while (i < display->width)
	{
		ray = lines[i].ray;
		if (ray)
		{
			free(ray);
		}
		texture_props = lines[i].texture_props;
		if (texture_props)
		{
			free (texture_props);
		}
		i++;
	}
	free(lines);
}

void	free_data(t_data game)
{
	if (game.map)
		ft_free_matrix(game.map);
	if (game.player)
		free(game.player);
	if (game.camera)
		free(game.camera);
	if (game.display)
	{
		mlx_delete_texture(game.display->textures[NORTH]);
		mlx_delete_texture(game.display->textures[SOUTH]);
		mlx_delete_texture(game.display->textures[EAST]);
		mlx_delete_texture(game.display->textures[WEST]);
		if (game.display->lines)
		{
			free_lines(game.display);
		}
		free(game.display);
	}
}
int	free_init(t_parse_data *parse_data)
{
	ft_free_matrix(parse_data->input_file);
	free_textures(parse_data);
	free(parse_data);
	return (FAILURE);
}
