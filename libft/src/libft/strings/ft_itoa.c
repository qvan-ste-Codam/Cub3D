/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 13:14:08 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/09/06 18:38:58 by quincy        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <limits.h>
#include <stdlib.h>

static int	int_len(long n)
{
	if (n < 0)
		n = -n;
	if (n > 9)
		return (1 + int_len(n / 10));
	return (1);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = int_len(n) + (n < 0);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	s[len] = '\0';
	len--;
	while (n > 0)
	{
		s[len] = n % 10 + 48;
		n /= 10;
		len--;
	}
	return (s);
}
