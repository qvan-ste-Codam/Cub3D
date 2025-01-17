/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 17:35:12 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/17 17:23:52 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../libs/libft/include/libft.h"
#include <stdlib.h>

static void	free_lines(t_display *display)
{
	int		i;
	t_line	*lines;
	t_ray	*ray;

	i = 0;
	lines = display -> lines;
	while (i < display->width)
	{
		ray = lines[i].ray;
		if (ray)
		{
			free(ray);
		}
		i++;
	}
	free(lines);
}

void	clean_exit(t_data game)
{
	if (game.map)
		ft_free_matrix(game.map);
	if (game.player)
		free(game.player);
	if (game.camera)
		free(game.camera);
	if (game.display)
	{
		if (game.display->lines)
		{
			free_lines(game.display);
		}
		free(game.display);
	}
}

int	check_extension(char *arg)
{
	char	*last_four_chars;

	last_four_chars = &arg[ft_strlen(arg) - 4];
	return (ft_strcmp(".cub", last_four_chars));
}
