/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 17:35:12 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/06 17:37:29 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/include/libft.h"

int	check_extension(char *arg)
{
	char	*last_four_chars;

	last_four_chars = &arg[ft_strlen(arg) - 4];
	return (ft_strcmp(".cub", last_four_chars));
}
