/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdoubnew.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/17 16:00:58 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/09/06 18:37:59 by quincy        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

t_listdoub	*ft_lstdoubnew(void *content)
{
	t_listdoub	*new;

	new = malloc(sizeof(t_listdoub));
	if (!new)
		return (NULL);
	new -> content = content;
	new -> prev = NULL;
	new -> next = NULL;
	return (new);
}
