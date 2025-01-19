/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 16:12:48 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/19 20:35:23 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/include/libft.h"
#include "../include/cub3D.h"

static int	init_data(t_data *game, char *map_file)
{
	game->map = create_map(map_file);
	if (!game->map)
		return (1);
	game->player = init_player(3, 4);
	if (!game->player)
		return (1);
	game->camera = init_camera(-1, 0);
	if (!game->camera)
		return (1);
	game->display = init_display();
	if (!game->display)
		return (1);
	return (SUCCESS);
}

static void	execute(t_data *data)
{
	mlx_t	*renderer;

	renderer = data->display->renderer;
	mlx_key_hook(renderer, &handle_exit, data);
	mlx_loop_hook(renderer, &game_loop, data);
	mlx_loop(renderer);
	mlx_terminate(renderer);
}

int	main(int argc, char **argv)
{
	t_data			data;

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
	if (init_data(&data, argv[1]) != SUCCESS)
	{
		ft_printf_fd(2, "Error\nFailed to initialize game\n");
		clean_exit(data);
		return (1);
	}
	execute(&data);
	clean_exit(data);
	return (0);
}
