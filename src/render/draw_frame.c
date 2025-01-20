/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_frame.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 18:35:28 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/20 22:38:44 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/MLX42/include/MLX42/MLX42.h"
#include "../../include/cub3D.h"

// TODO:
// - Render by image instead of per pixel
// - Fix sticky vertical walls

static void	draw_wall(
	mlx_image_t *img, t_line *line, mlx_image_t *text)
{
	int				y;
	int				wall_height;
	unsigned int	x_pos;
	unsigned int	y_pos;

	wall_height = line->draw_end - line->draw_start;
	x_pos = (unsigned int)(line->wall_hit_x * (double)text->width);
	if (line->dir == EAST || line->dir == WEST)
		x_pos = text->width - x_pos - 1;
	if (x_pos >= text->width)
		x_pos = text->width - 1;
	y = 0;
	while (y < wall_height)
	{
		y_pos = (unsigned int)((y * text->height) / wall_height);
		if (y_pos >= text->height)
			y_pos = text->height - 1;
		mlx_put_pixel(img, line->screen_pos_x,
			line->draw_start + y, get_pixel_color(text, x_pos, y_pos));
		y++;
	}
}

void	draw_line(t_display *display, t_line *line)
{
	int	y;

	y = 0;
	while (y < line->draw_start)
	{
		mlx_put_pixel(display->frame, line->screen_pos_x,
			y, display->floor_color);
		y++;
	}
	draw_wall(display->frame, line, display->textures[line->dir]);
	y = line->draw_end;
	while (y < display->height)
	{
		mlx_put_pixel(display->frame, line->screen_pos_x,
			y, display->ceiling_color);
		y++;
	}
}

int	create_new_frame(t_display *display)
{
	mlx_image_t	*frame;

	mlx_delete_image(display->renderer, display->frame);
	frame = mlx_new_image(display->renderer, display->width, display->height);
	if (!frame)
	{
		return (FAILURE);
	}
	display->frame = frame;
	return (SUCCESS);
}

int	draw_frame(t_display *display)
{
	int	i;

	i = 0;
	if (create_new_frame(display) == FAILURE)
	{
		return (FAILURE);
	}
	while (i < display -> width)
	{
		draw_line(display, &display->lines[i]);
		i++;
	}
	mlx_image_to_window(display->renderer, display->frame, 0, 0);
	return (SUCCESS);
}
