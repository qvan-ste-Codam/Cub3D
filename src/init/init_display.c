/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:03:15 by qvan-ste          #+#    #+#             */
/*   Updated: 2025/02/11 15:35:32 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"
#include "../../libs/libft/include/libft.h"
#include <stdlib.h>

static int	get_resolution(t_display *display)
{
	mlx_t	*mlx;

	mlx_set_setting(MLX_HEADLESS, true);
	mlx = mlx_init(1, 1, "", false);
	if (!mlx)
	{
		return (FAILURE);
	}
	mlx_get_monitor_size(0, &display->width, &display->height);
	mlx_terminate(mlx);
	mlx_set_setting(MLX_HEADLESS, false);
	return (SUCCESS);
}

static int	init_renderer(t_display *display)
{
	if (LIMIT_RESOLUTION == true)
	{
		display->width = 1920;
		display->height = 1080;
	}
	else
	{
		if (get_resolution(display) != SUCCESS)
		{
			return (FAILURE);
		}
	}
	display->renderer = mlx_init(display->width, display->height, "Cub3D",
			false);
	if (!display->renderer)
	{
		return (FAILURE);
	}
	return (SUCCESS);
}

static t_line	*init_lines(int width)
{
	int				x;
	t_line			*lines;
	t_ray			*ray;
	t_texture_props	*texture_props;

	x = 0;
	lines = ft_calloc(width, sizeof(t_line));
	if (!lines)
		return (NULL);
	while (x < width)
	{
		ray = ft_calloc(1, sizeof(t_ray));
		if (!ray)
			return (NULL);
		texture_props = ft_calloc(1, sizeof(t_texture_props));
		if (!texture_props)
			return (NULL);
		lines[x].ray = ray;
		lines[x].texture_props = texture_props;
		lines[x].screen_pos_x = x;
		lines[x].ray->camera_x = 2 * x / (double)width - 1;
		x++;
	}
	return (lines);
}

static int	init_textures(t_display *display, char **texture_paths)
{
	size_t			i;
	mlx_texture_t	*texture;

	i = 0;
	while (i < NUM_OF_TEXTURES)
	{
		texture = mlx_load_png(texture_paths[i]);
		if (!texture)
		{
			return (FAILURE);
		}
		display->textures[i] = texture;
		i++;
	}
	return (SUCCESS);
}

t_display	*init_display(t_parse_data *parse_data)
{
	t_display	*display;

	display = malloc(sizeof(t_display));
	if (!display)
		return (NULL);
	ft_bzero(display, sizeof(t_display));
	if (init_renderer(display) != SUCCESS)
		return (NULL);
	if (init_textures(display, parse_data->texture_paths) != SUCCESS)
		return (NULL);
	display->lines = init_lines(display->width);
	if (!display->lines)
		return (NULL);
	display->floor_color = rgba_to_int(parse_data->floor_color[R],
			parse_data->floor_color[G], parse_data->floor_color[B], 255);
	display->ceiling_color = rgba_to_int(parse_data->ceiling_color[R],
			parse_data->ceiling_color[G], parse_data->ceiling_color[B], 255);
	display->should_rerender = true;
	return (display);
}
