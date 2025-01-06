/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vecset_ptr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/17 16:05:56 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/09/16 18:25:28 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_vecset_ptr(t_vector_ptr *vec, void *item, size_t index)
{
	if (index >= vec -> size)
		return ;
	vec -> items[index] = item;
}
