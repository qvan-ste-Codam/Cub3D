/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/20 16:16:36 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/20 16:18:46 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"
#include "../../libs/libft/include/libft.h"

static int	check_extension(char *arg)
{
	const char	*last_four_chars;

	last_four_chars = &arg[ft_strlen(arg) - 4];
	return (ft_strcmp(".cub", last_four_chars));
}

int	validate_input(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf_fd(2, "Error\nIncorrect number of argments\n");
		return (FAILURE);
	}
	if (check_extension(argv[1]) != 0)
	{
		ft_printf_fd(2, "Error\nIncorrect file format\n");
		return (FAILURE);
	}
	return (SUCCESS);
}
