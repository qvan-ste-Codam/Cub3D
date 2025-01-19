/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 17:18:48 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/19 21:44:32 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libs/MLX42/include/MLX42/MLX42.h"
# define SUCCESS 0

// Enums
enum e_direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

enum e_side
{
	VERTICAL,
	HORIZONTAL,
};

// Structs
typedef struct s_ray
{
	int			map_pos_x;
	int			map_pos_y;
	int			side;
	double		dir_x;
	double		dir_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	double		step_x;
	double		step_y;
	double		wall_dist;
	double		camera_x;
}	t_ray;

typedef struct s_line
{
	int			render_start;
	int			render_end;
	int			screen_pos_x;
	double		texture_pos_x;
	int			dir;
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
	bool		rerender;
	t_line		*lines;
	mlx_t		*renderer;
	mlx_image_t	*frame;
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
void		game_loop(void *param);

// Input
void		handle_input(t_data *data);
void		handle_exit(mlx_key_data_t keydata, void *param);
void		handle_move_forward(t_data *data);
void		handle_move_backwards(t_data *data);
void		handle_move_left(t_data *data);
void		handle_move_right(t_data *data);

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
int			draw_frame(t_data *data);
void		render_line(t_data *data, t_line *line);
void		cast_ray(
				t_ray *ray, t_player *player, t_camera *camera, char **map);

#endif
