/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 17:18:48 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/15 15:37:43 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libs/MLX42/include/MLX42/MLX42.h"
# define SUCCESS 0

// Structs

typedef struct s_player
{
	double	position[2];
	int		map_position[2];
	double	view_dir[2];
}	t_player;

typedef struct s_camera
{
	double	plane[2];
	double	camera_x;
}	t_camera;

typedef struct s_display
{
	int		width;
	int		height;
	mlx_t	*renderer;
}	t_display;

typedef struct s_game_data
{
	char		**map;
	t_player	*player;
	t_camera	*camera;
	t_display	*display;
}	t_game_data;

// Functions
// Parsing
char		**create_map(char *map_file);

// Utils
int			check_extension(char *arg);
void		clean_exit(t_game_data game);

// init
t_player	*init_player(int player_x, int player_y,
				int view_dir_x, int view_dir_y);
t_camera	*init_camera(void);
t_display	*init_display(void);

#endif
