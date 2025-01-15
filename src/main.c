/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 16:12:48 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/15 15:33:49 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/include/libft.h"
#include "../include/cub3D.h"

static int	init_game_data(t_game_data *game, char *map_file)
{
	game -> map = create_map(map_file);
	if (!game -> map)
		return (1);
	game -> player = init_player(3, 3, -1, 0);
	if (!game -> player)
		return (1);
	game -> camera = init_camera();
	if (!game -> camera)
		return (1);
	game -> display = init_display();
	if (!game-> display)
		return (1);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_game_data			game;

	if (argc != 2)
	{
		ft_printf_fd(2, "Error\nIncorrect number of argments\n");
		return (1);
	}
	if (check_extension(argv[1]) != 0)
	{
		ft_printf_fd(2, "Error\nIncorrect file format\n");
		return (1);
	}
	if (init_game_data(&game, argv[1]) != SUCCESS)
	{
		ft_printf_fd(2, "Error\nFailed to initialize game\n");
		clean_exit(game);
		return (1);
	}
	clean_exit(game);
	return (0);
}
