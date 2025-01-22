/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pixels.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/20 17:15:09 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/22 18:59:52 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/MLX42/include/MLX42/MLX42.h"
#include "../../include/cub3D.h"

int	rgba_to_int(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	get_pixel_color(mlx_texture_t *texture, uint32_t x_pos, uint32_t y_pos)
{
	int		index;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	if (x_pos >= texture->width || y_pos >= texture->height)
	{
		return (0);
	}
	index = (y_pos * texture->width + x_pos) * 4;
	r = texture->pixels[index];
	g = texture->pixels[index + 1];
	b = texture->pixels[index + 2];
	a = texture->pixels[index + 3];
	return (rgba_to_int(r, g, b, a));
}
