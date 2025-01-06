# Colours
RED =\033[0;31m
ORANGE=\033[0;33m
GREEN =\033[0;32m
NO_COLOUR =\033[0m

# Directories
FT_PRINTFDIR = src/ft_printf
FT_PRINTF_FDDIR = src/ft_printf_fd
GET_NEXT_LINEDIR = src/get_next_line
CHARACTERSDIR = src/libft/characters
LISTSDIR = src/libft/lists
MATHDIR = src/libft/math
MEMORYDIR = src/libft/memory
OUTPUTDIR = src/libft/output
STRINGSDIR = src/libft/strings
VECTORSDIR = src/libft/vectors

# Files
FT_PRINTF = $(FT_PRINTFDIR)/ft_printf.c $(FT_PRINTFDIR)/print_basic.c \
			$(FT_PRINTFDIR)/print_hex.c $(FT_PRINTFDIR)/print_num.c \
			$(FT_PRINTFDIR)/print_ptr.c

FT_PRINTF_FD =  $(FT_PRINTF_FDDIR)/ft_printf_fd.c $(FT_PRINTF_FDDIR)/print_basic_fd.c \
				$(FT_PRINTF_FDDIR)/print_hex_fd.c $(FT_PRINTF_FDDIR)/print_num_fd.c \
				$(FT_PRINTF_FDDIR)/print_ptr_fd.c

GET_NEXT_LINE = $(GET_NEXT_LINEDIR)/get_next_line.c

CHARACTERS = $(CHARACTERSDIR)/ft_isalnum.c $(CHARACTERSDIR)/ft_isalpha.c \
				$(CHARACTERSDIR)/ft_isascii.c $(CHARACTERSDIR)/ft_isdigit.c \
				$(CHARACTERSDIR)/ft_isprint.c $(CHARACTERSDIR)/ft_isspace.c \
				$(CHARACTERSDIR)/ft_tolower.c $(CHARACTERSDIR)/ft_toupper.c

LISTS = $(LISTSDIR)/ft_lstadd_back.c $(LISTSDIR)/ft_lstadd_front.c \
		$(LISTSDIR)/ft_lstdoubadd_back.c $(LISTSDIR)/ft_lstdoubadd_front.c \
		$(LISTSDIR)/ft_lstdoublast.c $(LISTSDIR)/ft_lstdoubnew.c \
		$(LISTSDIR)/ft_lstdoubsize.c $(LISTSDIR)/ft_lstlast.c \
		$(LISTSDIR)/ft_lstnew.c $(LISTSDIR)/ft_lstsize.c

MATH = $(MATHDIR)/ft_hexlen.c $(MATHDIR)/ft_intlen.c

MEMORY = $(MEMORYDIR)/ft_bzero.c $(MEMORYDIR)/ft_calloc.c $(MEMORYDIR)/ft_free_matrix.c \
			$(MEMORYDIR)/ft_memchr.c $(MEMORYDIR)/ft_memcmp.c $(MEMORYDIR)/ft_memcpy.c \
			$(MEMORYDIR)/ft_memmove.c $(MEMORYDIR)/ft_memset.c \
			$(MEMORYDIR)/ft_realloc.c

OUTPUT = $(OUTPUTDIR)/ft_print_matrix.c $(OUTPUTDIR)/ft_putchar_fd.c \
			$(OUTPUTDIR)/ft_putendl_fd.c $(OUTPUTDIR)/ft_putnbr_fd.c \
			$(OUTPUTDIR)/ft_putnbr.c $(OUTPUTDIR)/ft_putstr_fd.c

STRINGS = $(STRINGSDIR)/ft_atoi.c $(STRINGSDIR)/ft_atoll.c $(STRINGSDIR)/ft_itoa.c \
			$(STRINGSDIR)/ft_split.c $(STRINGSDIR)/ft_strchr.c $(STRINGSDIR)/ft_strcmp.c \
			$(STRINGSDIR)/ft_strdup.c $(STRINGSDIR)/ft_striteri.c $(STRINGSDIR)/ft_strjoin.c \
			$(STRINGSDIR)/ft_strlcat.c $(STRINGSDIR)/ft_strlcpy.c $(STRINGSDIR)/ft_strlen.c \
			$(STRINGSDIR)/ft_strmapi.c $(STRINGSDIR)/ft_strncmp.c $(STRINGSDIR)/ft_strndup.c \
			$(STRINGSDIR)/ft_strnstr.c $(STRINGSDIR)/ft_strrchr.c $(STRINGSDIR)/ft_strtrim.c \
			$(STRINGSDIR)/ft_substr.c

VECTORS = $(VECTORSDIR)/ft_vecappend.c  $(VECTORSDIR)/ft_vecinit.c \
			$(VECTORSDIR)/ft_vecset.c $(VECTORSDIR)/ft_vecget.c  \
			$(VECTORSDIR)/ft_vecpop.c $(VECTORSDIR)/ft_vecresize.c \
			$(VECTORSDIR)/ft_vecinsert.c $(VECTORSDIR)/ft_vecappend_ptr.c \
			$(VECTORSDIR)/ft_vecinit_ptr.c $(VECTORSDIR)/ft_vecset_ptr.c \
			$(VECTORSDIR)/ft_vecget_ptr.c  $(VECTORSDIR)/ft_vecpop_ptr.c \
			$(VECTORSDIR)/ft_vecresize_ptr.c $(VECTORSDIR)/ft_vecinsert_ptr.c \
			$(VECTORSDIR)/ft_vecdelete_ptr.c

CFILES = $(FT_PRINTF) $(FT_PRINTF_FD) $(GET_NEXT_LINE) $(CHARACTERS) \
			$(OUTPUT) $(LISTS) $(MATH) $(MEMORY) $(STRINGS) $(VECTORS)

OFILES = $(CFILES:.c=.o)

# Compilation
INCLUDES = -I include
CFLAGS = -c -Wall -Werror -Wextra
CC = clang
NAME = libft.a

# Targets
all: $(NAME)

clean:
	@echo "$(RED)[libft] Removing .o files$(NO_COLOUR)"
	@rm -f $(OFILES)

fclean:  clean
	@echo "$(RED)[libft] Removing $(NAME)$(NO_COLOUR)"
	@rm -f $(NAME)

.c.o:
	@echo "$(ORANGE)[libft] Compiling $<$(NO_COLOUR)"
	@$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

$(NAME): $(OFILES)
	@ar rcs $(NAME) $(OFILES)
	@echo "$(GREEN)[libft] Compiling finished$(NO_COLOUR)"

libclean:
	@echo "$(RED)[libft] Removing $(NAME)$(NO_COLOUR)"
	@rm -f $(NAME)

re: fclean all

.PHONY:  all clean fclean re .c.o libclean
