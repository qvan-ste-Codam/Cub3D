/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 18:35:28 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/15 21:32:12 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/MLX42/include/MLX42/MLX42.h"
#include "../../include/cub3D.h"
#define BLUE 0x00FFFF
#define BLACK 0x0000FF
#define WHITE 0xFFFFFFFF

// static void	render_line_part(
// 	mlx_image_t *img, int draw_start, int draw_end, int x, int colour)
// {
// 	while (draw_start < draw_end)
// 	{
// 		mlx_put_pixel(img, x, draw_start, colour);
// 		draw_start++;
// 	}
// }

// void	render_line(mlx_image_t *img, t_line *line, int height)
// {
// 	int	draw_start;
// 	int	draw_end;

// 	draw_start = line -> draw_start;
// 	draw_end = line -> draw_end;
// 	render_line_part(img, 0, draw_start, line -> x_position, BLACK);
// 	render_line_part(img, draw_start, draw_end, line -> x_position, BLUE);
// 	render_line_part(img, draw_end, height, line -> x_position, WHITE);
// }
