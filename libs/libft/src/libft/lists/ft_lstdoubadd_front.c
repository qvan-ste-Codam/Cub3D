/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdoubadd_front.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/17 15:59:47 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/06/05 15:59:09 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstdoubadd_front(t_listdoub **lst, t_listdoub *new)
{
	new -> next = *lst;
	if (new -> next)
		new -> next -> prev = new;
	*lst = new;
}
