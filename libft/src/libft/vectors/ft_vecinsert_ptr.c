/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vecinsert_ptr.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/17 16:16:43 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/09/16 18:25:33 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_vecinsert_ptr(t_vector_ptr *vec, void *item, size_t index)
{
	size_t	i;

	i = vec -> size;
	if (!vec || !item || index >= vec -> size)
		return (-1);
	if (vec -> size == vec -> capacity)
	{
		if (ft_vecresize_ptr(vec, vec -> capacity * 2) == -1)
			return (-1);
	}
	while (i > index)
	{
		vec -> items[i] = vec -> items [i - 1];
		i--;
	}
	vec -> items[index] = item;
	vec -> size++;
	return (0);
}
