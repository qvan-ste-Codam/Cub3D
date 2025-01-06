/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vecpop_ptr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/17 16:42:58 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/09/06 18:41:47 by quincy        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

int	ft_vecpop_ptr(t_vector_ptr *vec, size_t index)
{
	if (index >= vec -> size)
		return (0);
	free(ft_vecget_ptr(vec, index));
	while (index < vec -> size - 1)
	{
		vec -> items[index] = vec -> items [index + 1];
		index++;
	}
	vec -> items[index] = NULL;
	vec -> size--;
	if (vec -> size <= (vec -> capacity / 4))
		return (ft_vecresize_ptr(vec, vec -> capacity / 2));
	return (0);
}
