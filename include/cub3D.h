/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 17:18:48 by qvan-ste      #+#    #+#                 */
/*   Updated: 2025/01/20 21:53:16 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libs/MLX42/include/MLX42/MLX42.h"

# define NUM_OF_TEXTURES 4
# define MOVEMENT_SPEED 0.1
# define ROTATION_SPEED 0.1

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

enum e_color
{
	R,
	G,
	B,
};

enum e_error
{
	SUCCESS,
	FAILURE,
};

// Structs
typedef struct s_ray
{
	int				map_pos_x;
	int				map_pos_y;
	int				side;
	double			dir_x;
	double			dir_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	double			step_x;
	double			step_y;
	double			wall_dist;
	double			camera_x;
}	t_ray;

typedef struct s_line
{
	int				draw_start;
	int				draw_end;
	int				screen_pos_x;
	int				wall_hit_x;
	int				dir;
	t_ray			*ray;
}	t_line;

typedef struct s_player
{
	double			pos_x;
	double			pos_y;
}	t_player;

typedef struct s_camera
{
	double			plane_x;
	double			plane_y;
	double			view_dir_x;
	double			view_dir_y;
}	t_camera;

typedef struct s_display
{
	bool			should_rerender;
	t_line			*lines;
	mlx_t			*renderer;
	mlx_image_t		*frame;
	mlx_image_t		*textures[NUM_OF_TEXTURES];
	int				width;
	int				height;
	int				floor_color;
	int				ceiling_color;
}	t_display;

typedef struct s_data
{
	char			**map;
	t_player		*player;
	t_camera		*camera;
	t_display		*display;
}	t_data;

// Functions
// Engine
void		execute(t_data *data);

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
int			validate_input(int argc, char **argv);
void		free_data(t_data data);
int			rgba_to_int(int r, int g, int b, int a);
int			get_pixel_color(mlx_image_t *image, uint32_t x_pos, uint32_t y_pos);

// Init
int			init_data(t_data *game, char *map_file);
t_display	*init_display(
				char **texture_paths, int *rgb_floor, int *rgb_ceiling);

// Render
int			draw_frame(t_display *display);
void		render_line(t_data *data, t_line *line);
void		cast_ray(
				t_ray *ray, t_player *player, t_camera *camera, char **map);

#endif
