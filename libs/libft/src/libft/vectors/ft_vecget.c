/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vecget.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/05 21:05:20 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/09/16 18:28:27 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_vecget(t_vector *vec, size_t index)
{
	if (index >= vec -> size)
		return (NULL);
	return (vec -> items + (index * vec -> item_size));
}
