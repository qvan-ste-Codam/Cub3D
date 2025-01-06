/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 16:12:48 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/06 19:35:53 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/include/libft.h"
#include "../include/cub3D.h"

int	main(int argc, char **argv)
{
	t_map_data	map_data;

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
	if (create_map(argv[1], &map_data) != SUCCESS)
		return (1);
	ft_print_matrix(map_data .map);
	ft_free_matrix(map_data.map);
	return (0);
}
