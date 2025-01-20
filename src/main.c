/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 16:12:48 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/20 17:25:02 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../libs/libft/include/libft.h"

int	main(int argc, char **argv)
{
	t_data			data;

	ft_bzero(&data, sizeof(t_data));
	if (validate_input(argc, argv) != SUCCESS)
	{
		return (FAILURE);
	}
	if (init_data(&data, argv[1]) != SUCCESS)
	{
		free_data(data);
		return (FAILURE);
	}
	execute(&data);
	free_data(data);
}
