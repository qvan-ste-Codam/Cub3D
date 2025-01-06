RED =\033[0;31m
ORANGE=\033[0;33m
GREEN =\033[0;32m
NO_COLOUR =\033[0m

CFILES = $(wildcard src/*.c) $(wildcard src/parsing/*.c) 

OFILES = $(CFILES:.c=.o)

LIBFT_FOLDER = libs/libft

MLX42_FOLDER = libs/MLX42

MLX42 = $(MLX42_FOLDER)/build/libmlx42.a

LIBFT = $(LIBFT_FOLDER)/libft.a 

LFILES = $(LIBFT) $(MLX42)

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g

LDFLAGS = -ldl -lglfw -pthread -lm

NAME = cub3D

all: $(NAME)

.c.o:
	@echo "$(ORANGE)[$(NAME)] Compiling $<$(NO_COLOUR)"
	@$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(LFILES) $(OFILES) 
	@$(CC) $(CFLAGS) $(LDFLAGS) $(OFILES) $(LFILES) -o $(NAME)
	@echo "$(GREEN)[$(NAME)] Compiling finished$(NO_COLOUR)"

$(LIBFT): $(LIBFT_FOLDER)
	@$(MAKE) --no-print-directory -C $(LIBFT_FOLDER)

$(MLX42): $(MLX42_FOLDER)
	@cmake -S $(MLX42_FOLDER) -B $(MLX42_FOLDER)/build && $(MAKE) --no-print-directory -C $(MLX42_FOLDER)/build -j4

clean:
	@$(MAKE) clean --no-print-directory -C $(LIBFT_FOLDER)
	@echo "$(RED)[MLX42] Removing .o files$(NO_COLOUR)"
	@echo "$(RED)[$(NAME)] Removing .o files$(NO_COLOUR)"
	@rm -f $(OFILES)
	@$(MAKE) clean --no-print-directory -C $(MLX42_FOLDER)/build


fclean:  clean
	@$(MAKE) libclean --no-print-directory -C $(LIBFT_FOLDER)
	@echo "$(RED)[MLX42] Removing MLX42 build folder$(NO_COLOUR)"
	@rm -rf $(MLX42_FOLDER)/build
	@echo "$(RED)[$(NAME)] Removing $(NAME)$(NO_COLOUR)"
	@rm -f $(NAME)

re: fclean all

.PHONY:  all clean fclean re .c.o