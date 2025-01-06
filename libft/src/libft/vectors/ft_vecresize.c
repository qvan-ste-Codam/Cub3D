/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vecresize.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/05 21:41:24 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/09/06 18:41:25 by quincy        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_vecresize(t_vector *vec, size_t new_capacity)
{
	void	*new;
	size_t	old_size;
	size_t	new_size;

	old_size = vec -> size * vec -> item_size;
	new_size = new_capacity * vec -> item_size;
	new = ft_realloc(vec -> items, old_size, new_size);
	if (!new)
		return (-1);
	vec -> capacity = new_capacity;
	vec -> items = new;
	return (0);
}
