/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/16 17:12:55 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/09/16 18:04:55 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

static int	split_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	n_splits(char const *s, char c)
{
	size_t	i;
	int		n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			n++;
			i += split_len(&s[i], c);
		}
		else
			i++;
	}
	return (n);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**ret;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	ret = ft_calloc(n_splits(s, c) + 1, sizeof(char *));
	if (!ret)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			ret[j] = ft_strndup(&s[i], split_len(&s[i], c));
			if (!ret[j++])
				return (ft_free_matrix(ret), NULL);
			i += split_len(&s[i], c);
		}
		else
			i++;
	}
	ret[j] = NULL;
	return (ret);
}
