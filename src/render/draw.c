/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 18:35:28 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/19 20:26:19 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/MLX42/include/MLX42/MLX42.h"
#include "../../include/cub3D.h"
#define BLUE 0x00FFFF
#define BLACK 0x0000FF
#define WHITE 0xFFFFFFFF

// TODO:
// - Make norm proof reusuable render function
// - Render by image instead of per pixel
// - Use textures instead of colours

static void	render_ceiling(
	mlx_image_t *img, int draw_start, int draw_end, int x)
{
	while (draw_start < draw_end)
	{
		mlx_put_pixel(img, x, draw_start, BLACK);
		draw_start++;
	}
}

static void	render_floor(
	mlx_image_t *img, int draw_start, int draw_end, int x)
{
	while (draw_start < draw_end)
	{
		mlx_put_pixel(img, x, draw_start, WHITE);
		draw_start++;
	}
}

static void	render_wall(
	mlx_image_t *img, int draw_start, int draw_end, int x)
{
	while (draw_start < draw_end)
	{
		mlx_put_pixel(img, x, draw_start, BLUE);
		draw_start++;
	}
}

void	draw_line(mlx_image_t *img, t_line *line, int height)
{
	int	draw_start;
	int	draw_end;

	draw_start = line -> render_start;
	draw_end = line -> render_end;
	render_ceiling(img, 0, draw_end, line->screen_pos_x);
	render_wall(img, draw_start, draw_end, line->screen_pos_x);
	render_floor(img, draw_end, height, line->screen_pos_x);
}

int	draw_frame(t_data *data)
{
	int			i;
	mlx_image_t	*frame;
	t_display	*display;

	i = 0;
	display = data -> display;
	frame = mlx_new_image(display->renderer, display->width, display->height);
	if (!frame)
	{
		return (-1);
	}
	while (i < display -> width)
	{
		draw_line(frame, &display->lines[i], display->height);
		i++;
	}
	if (display->frame)
	{
		mlx_delete_image(display->renderer, display->frame);
	}
	mlx_image_to_window(display->renderer, frame, 0, 0);
	display->frame = frame;
	return (0);
}
