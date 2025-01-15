/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 17:35:12 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/15 21:51:06 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../libs/libft/include/libft.h"
#include <stdlib.h>

void	clean_exit(t_game_data game)
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
			free (game.display->lines);
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
