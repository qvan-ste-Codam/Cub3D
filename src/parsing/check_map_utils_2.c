/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map_utils_2.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tgoossen <tgoossen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/10 16:39:32 by tgoossen      #+#    #+#                 */
/*   Updated: 2025/02/14 13:31:04 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"
#include "../../libs/libft/include/libft.h"

int	is_not_map(char *line)
{
	static const char	*list[] = {"NO ", "SO ", "WE ",
		"EA ", "F ", "C ", NULL};
	int					i;

	i = 0;
	if (!line || line[0] == '\0' || line[0] == '\n')
		return (1);
	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	while (i < 6)
	{
		if (ft_strncmp(line, list[i], ft_strlen(list[i])) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ' || c == '\t');
}
