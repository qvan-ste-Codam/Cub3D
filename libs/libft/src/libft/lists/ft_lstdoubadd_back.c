/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdoubadd_back.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/17 15:58:29 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/06/05 15:59:06 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstdoubadd_back(t_listdoub **lst, t_listdoub *new)
{
	t_listdoub	*last;

	last = ft_lstdoublast(*lst);
	last -> next = new;
	new -> prev = last;
}
