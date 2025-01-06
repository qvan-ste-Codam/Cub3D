/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_matrix.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/16 16:41:07 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/09/16 16:44:41 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_print_matrix(char **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i])
	{
		ft_printf("%s\n", matrix[i]);
		i++;
	}
	return (i);
}
