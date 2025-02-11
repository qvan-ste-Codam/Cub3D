/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:18:48 by qvan-ste          #+#    #+#             */
/*   Updated: 2025/02/11 14:31:37 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libs/MLX42/include/MLX42/MLX42.h"

# define NUM_OF_TEXTURES 4
# define GAME_SPEED 1.4
# ifndef LIMIT_RESOLUTION
#  define LIMIT_RESOLUTION false
# endif

// Enums
enum				e_direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

enum				e_side
{
	VERTICAL,
	HORIZONTAL,
};

enum				e_color
{
	R,
	G,
	B,
};

enum				e_error
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
}					t_ray;

typedef struct s_texture_props
{
	int				x_pos;
	double			step_size;
	mlx_texture_t	*texture;
}					t_texture_props;

typedef struct s_line
{
	int				draw_start;
	int				draw_end;
	int				height;
	int				dir;
	int				screen_pos_x;
	t_ray			*ray;
	t_texture_props	*texture_props;
}					t_line;

typedef struct s_player
{
	double			pos_x;
	double			pos_y;
}					t_player;

typedef struct s_camera
{
	double			plane_x;
	double			plane_y;
	double			view_dir_x;
	double			view_dir_y;
}					t_camera;

typedef struct s_display
{
	int				width;
	int				height;
	int				floor_color;
	int				ceiling_color;
	bool			should_rerender;
	t_line			*lines;
	mlx_t			*renderer;
	mlx_image_t		*frame;
	mlx_texture_t	*textures[NUM_OF_TEXTURES];
}					t_display;

typedef struct s_data
{
	char			**map;
	t_player		*player;
	t_camera		*camera;
	t_display		*display;
}					t_data;

typedef struct s_parse_data
{
	char			**input_file;
	char			*no_texture;
	char			*so_texture;
	char			*we_texture;
	char			*ea_texture;
	int				floor_color[3];
	int				ceiling_color[3];
	int				start_pos_x;
	int				start_pos_y;
	int				view_direction;
	char			*texture_paths[NUM_OF_TEXTURES];
}					t_parse_data;

// Functions
// Engine
void				execute(t_data *data);

// Input
void				handle_input(t_data *data);
void				handle_exit(mlx_key_data_t keydata, void *param);
void				handle_move_forward(t_data *data, double speed);
void				handle_move_backwards(t_data *data, double speed);
void				handle_move_left(t_data *data, double speed);
void				handle_move_right(t_data *data, double speed);

// Parsing
char				**create_map(char *file, t_parse_data *map_data);
int					main_mcheck(t_parse_data *map_data);
int					is_not_map(char *line);
int					check_map(t_parse_data *map_data);
void				free_textures(t_parse_data *map_data);
int					init_parse_data(t_parse_data *map_data);
t_player			*init_player(int player_x, int player_y);
int					init_path(char *line, char **texture);
int					init_floor_ceiling(char *line, int *color);
int					init_texture(char *line, t_parse_data *map_data);
int					init_texpath(char **map, t_parse_data *map_data);
int					check_if_init(t_parse_data *map_data);
void				free_textures(t_parse_data *map_data);
int					parse_color(char *line, int *color);
int					check_i_map(char **map);
int					is_valid_map_char(char c);
void	cam_xy(int y, int x, char var, t_parse_data *map_data);
int	has_valid_starting_position(char **map, int map_height,
		t_parse_data *map_data);
		int	check_valid_char(char **map, int map_height, int i);
		int	longest_line(char **map);
char	**fill_map(char **oldmap, int height);

// Utils
int					validate_input(int argc, char **argv);
void				free_data(t_data data);
int					rgba_to_int(int r, int g, int b, int a);
int					get_pixel_color(mlx_texture_t *texture, uint32_t x_pos,
						uint32_t y_pos);
// Init
int					init_data(t_data *game, char *map_file);
t_display			*init_display(t_parse_data *parse_data);

// Render
int					render_frame(t_display *display);
void				compute_line(t_data *data, t_line *line);
void				cast_ray(t_ray *ray, t_player *player, t_camera *camera,
						char **map);

#endif
