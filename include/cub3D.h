/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 17:18:48 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/17 17:41:58 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libs/MLX42/include/MLX42/MLX42.h"
# define SUCCESS 0

// Structs
typedef struct s_ray
{
	int			map_pos_x;
	int			map_pos_y;
	double		dir_x;
	double		dir_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	double		step_x;
	double		step_y;
	double		wall_dist;
}	t_ray;

typedef struct s_line
{
	int			render_start;
	int			render_end;
	int			x_pos;
	int			side;
	int			wall_x;
	t_ray		*ray;
}	t_line;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
}	t_player;

typedef struct s_camera
{
	double		plane_x;
	double		plane_y;
	double		view_dir_x;
	double		view_dir_y;
}	t_camera;

typedef struct s_display
{
	int			width;
	int			height;
	t_line		*lines;
	mlx_t		*renderer;
	mlx_image_t	*screen;
}	t_display;

typedef struct s_data
{
	char		**map;
	t_player	*player;
	t_camera	*camera;
	t_display	*display;
}	t_data;

// Functions
// Engine
int			execute_game(t_data *data);
void		handle_input(mlx_key_data_t keydata, void *param);

// Input
void		move_forward(t_data *data);
void		move_backwards(t_data *data);
void		move_left(t_data *data);
void		move_right(t_data *data);

// Parsing
char		**create_map(char *map_file);

// Utils
int			check_extension(char *arg);
void		clean_exit(t_data data);

// Init
t_player	*init_player(int player_x, int player_y);
t_camera	*init_camera(int view_dir_x, int view_dir_y);
t_display	*init_display(void);

// Render
void		render_line(mlx_image_t *img, t_line *line, int height);
void		calculate_line(t_data *data, t_line *line);
void		calculate_line_distance(t_ray *ray, t_player *player);

#endif
