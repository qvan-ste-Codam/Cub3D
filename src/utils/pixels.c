/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pixels.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/20 17:15:09 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/20 20:35:41 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/MLX42/include/MLX42/MLX42.h"
#include "../../include/cub3D.h"

int	rgba_to_int(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	get_pixel_color(mlx_image_t *image, uint32_t x_pos, uint32_t y_pos)
{
	size_t	index;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	if (x_pos >= image->width || y_pos >= image->height)
	{
		return (0);
	}
	index = (y_pos * image->width + x_pos) * sizeof(int32_t);
	r = image->pixels[index];
	g = image->pixels[index + 1];
	b = image->pixels[index + 2];
	a = image->pixels[index + 3];
	return (rgba_to_int(r, g, b, a));
}
