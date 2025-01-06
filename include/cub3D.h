/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 17:18:48 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/06 19:35:42 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define SUCCESS 0

// Structs
typedef struct s_map_data
{
	char	**map;
}	t_map_data;

// Functions
// Parsing
int		create_map(char *file, t_map_data *map_data);

//Utils
int		check_extension(char *arg);

#endif
