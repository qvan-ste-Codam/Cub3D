/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/05 17:38:26 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/09/06 18:38:35 by quincy        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size && ptr)
		return (free(ptr), NULL);
	new = malloc(new_size);
	if (!new)
		return (NULL);
	ft_bzero(new, new_size);
	ft_memcpy(new, ptr, old_size);
	free(ptr);
	return (new);
}
