/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdoubsize.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/17 16:02:34 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/06/05 15:59:20 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_lstdoubsize(t_listdoub *lst)
{
	int	n;

	n = 0;
	while (lst)
	{
		lst = lst -> next;
		n++;
	}
	return (n);
}
