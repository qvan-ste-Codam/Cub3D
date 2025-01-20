/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_display.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/20 15:03:15 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/20 22:24:06 by qvan-ste      ########   odam.nl         */
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
	if (get_resolution(display) != SUCCESS)
	{
		return (FAILURE);
	}
	display->renderer = mlx_init(display->width,
			display->height, "Cub3D", false);
	if (!display -> renderer)
	{
		return (FAILURE);
	}
	return (SUCCESS);
}

static t_line	*init_lines(int width)
{
	int		i;
	t_line	*lines;
	t_ray	*ray;

	i = 0;
	lines = ft_calloc(width, sizeof(t_line));
	if (!lines)
	{
		return (NULL);
	}
	while (i < width)
	{
		ray = ft_calloc(1, sizeof(t_ray));
		if (!ray)
		{
			return (NULL);
		}
		lines[i].ray = ray;
		lines[i].screen_pos_x = i;
		lines[i].ray->camera_x = 2 * i / (double)width - 1;
		i++;
	}
	return (lines);
}

static int	init_textures(t_display *display, char **texture_paths)
{
	size_t			i;
	mlx_texture_t	*texture;

	i = 0;
	while (texture_paths[i])
	{
		texture = mlx_load_png(texture_paths[i]);
		if (!texture)
		{
			return (FAILURE);
		}
		display->textures[i] = mlx_texture_to_image(display->renderer, texture);
		mlx_delete_texture(texture);
		if (!display->textures[i])
		{
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

t_display	*init_display(
		char **texture_paths, int *rgb_floor, int *rgb_ceiling)
{
	t_display	*display;

	display = malloc(sizeof(t_display));
	if (!display)
		return (NULL);
	ft_bzero(display, sizeof(t_display));
	if (init_renderer(display) != SUCCESS)
		return (NULL);
	if (init_textures(display, texture_paths) != SUCCESS)
		return (NULL);
	display->lines = init_lines(display->width);
	if (!display -> lines)
		return (NULL);
	display->floor_color
		= rgba_to_int(rgb_floor[R], rgb_floor[G], rgb_floor[B], 255);
	display->ceiling_color
		= rgba_to_int(rgb_ceiling[R], rgb_ceiling[G], rgb_ceiling[B], 255);
	display->should_rerender = true;
	return (display);
}
