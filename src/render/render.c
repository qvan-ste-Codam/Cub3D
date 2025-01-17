/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 18:35:28 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/17 19:28:56 by qvan-ste      ########   odam.nl         */
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

void	render_line(mlx_image_t *img, t_line *line, int height)
{
	int	draw_start;
	int	draw_end;

	draw_start = line -> render_start;
	draw_end = line -> render_end;
	render_ceiling(img, 0, draw_end, line->x_pos);
	render_wall(img, draw_start, draw_end, line->x_pos);
	render_floor(img, draw_end, height, line->x_pos);
}
