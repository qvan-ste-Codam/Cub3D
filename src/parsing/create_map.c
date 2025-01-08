/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_map.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 17:29:30 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/08 13:06:18 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../../libs/libft/include/libft.h"
#include "../../include/cub3D.h"

static int	create_map_vector(t_vector_ptr *map_vector, int map_fd)
{
	char			*buf;

	buf = get_next_line(map_fd);
	if (!buf)
		return (-1);
	if (ft_vecinit_ptr(map_vector, 10, sizeof(char *)) == -1)
		return (-1);
	while (buf)
	{
		if (buf[ft_strlen(buf) - 1] == '\n')
			buf[ft_strlen(buf) - 1] = '\0';
		if (ft_vecappend_ptr(map_vector, buf) == -1)
		{
			free(buf);
			ft_vecdelete_ptr(map_vector);
			return (-1);
		}
		buf = get_next_line(map_fd);
	}
	return (0);
}

static char	**create_map_matrix(t_vector_ptr *map_vector)
{
	size_t	i;
	char	**map_matrix;

	i = 0;
	map_matrix = ft_calloc(map_vector -> size + 1, sizeof(char *));
	if (!map_matrix)
		return (NULL);
	while (i < map_vector -> size)
	{
		map_matrix[i] = ft_vecget_ptr(map_vector, i);
		i++;
	}
	return (map_matrix);
}

int	create_map(char *file, t_map_data *map_data)
{
	int				map_fd;
	t_vector_ptr	map_vector;

	map_fd = open(file, O_RDONLY);
	if (map_fd == -1)
	{
		perror("Cub3D");
		return (1);
	}
	if (create_map_vector(&map_vector, map_fd) == -1)
	{
		perror("Cub3D");
		close(map_fd);
		return (1);
	}
	map_data -> map = create_map_matrix(&map_vector);
	close(map_fd);
	free(map_vector.items);
	if (!map_data -> map)
		return (0);
	return (SUCCESS);
}
