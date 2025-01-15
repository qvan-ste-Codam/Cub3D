/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 17:18:48 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/15 21:24:48 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libs/MLX42/include/MLX42/MLX42.h"
# define SUCCESS 0

// Structs

typedef struct s_line
{
	double		ray_direction[2];
	double		delta_distance[2];
	double		side_distance[2];
	double		wall_distance;
	int			position[2];
	int			step[2];
	int			draw_start;
	int			draw_end;
	int			x_position;
}	t_line;

typedef struct s_player
{
	double	position[2];
}	t_player;

typedef struct s_camera
{
	double	plane[2];
	double	view_dir[2];
}	t_camera;

typedef struct s_display
{
	int			width;
	int			height;
	t_line		*lines;
	mlx_t		*renderer;
	mlx_image_t	*screen;
}	t_display;

typedef struct s_game_data
{
	char		**map;
	t_player	*player;
	t_camera	*camera;
	t_display	*display;
}	t_game_data;

// Functions
int			execute_game(t_game_data *game);

// Parsing
char		**create_map(char *map_file);

// Utils
int			check_extension(char *arg);
void		clean_exit(t_game_data game);

// Init
t_player	*init_player(int player_x, int player_y);
t_camera	*init_camera(int view_dir_x, int view_dir_y);
t_display	*init_display(void);

// Render
void		render_line(mlx_image_t *img, t_line *line, int height);
void		calculate_line(
				t_game_data *game, t_line *line, double camera_x, int height);

#endif
