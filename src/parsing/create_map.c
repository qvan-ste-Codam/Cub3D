/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:29:30 by qvan-ste          #+#    #+#             */
/*   Updated: 2025/02/11 15:14:47 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"
#include "../../libs/libft/include/libft.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	create_map_vector(t_vector_ptr *map_vector, int map_fd)
{
	char	*buf;

	buf = get_next_line(map_fd);
	if (!buf)
		return (FAILURE);
	if (ft_vecinit_ptr(map_vector, 10, sizeof(char *)) != SUCCESS)
		return (FAILURE);
	while (buf)
	{
		if (buf[ft_strlen(buf) - 1] == '\n')
			buf[ft_strlen(buf) - 1] = '\0';
		if (ft_vecappend_ptr(map_vector, buf) != SUCCESS)
		{
			free(buf);
			ft_vecdelete_ptr(map_vector);
			return (FAILURE);
		}
		buf = get_next_line(map_fd);
	}
	return (SUCCESS);
}

static char	**create_map_matrix(t_vector_ptr *map_vector)
{
	size_t	i;
	char	**map_matrix;

	i = 0;
	map_matrix = ft_calloc(map_vector->size + 1, sizeof(char *));
	if (!map_matrix)
		return (NULL);
	while (i < map_vector->size)
	{
		map_matrix[i] = ft_vecget_ptr(map_vector, i);
		i++;
	}
	return (map_matrix);
}

char	**allocate_map(t_parse_data *parse_data, int map_size)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = malloc(sizeof(char *) * (map_size + 1));
	if (!map)
		return (NULL);
	while (is_not_map(parse_data->input_file[i]))
		i++;
	while (parse_data->input_file[i])
	{
		map[j] = parse_data->input_file[i];
		i++;
		j++;
	}
	map[j] = NULL;
	return (map);
}

char	**create_map(char *file, t_parse_data *parse_data)
{
	int				map_fd;
	t_vector_ptr	map_vector;

	map_fd = open(file, O_RDONLY);
	if (map_fd == -1)
	{
		perror("Cub3D");
		return (NULL);
	}
	if (create_map_vector(&map_vector, map_fd) == FAILURE)
	{
		perror("Cub3D");
		close(map_fd);
		return (NULL);
	}
	parse_data->input_file = create_map_matrix(&map_vector);
	close(map_fd);
	free(map_vector.items);
	if (!parse_data->input_file)
		return (NULL);
	return (allocate_map(parse_data, map_vector.size));
}
