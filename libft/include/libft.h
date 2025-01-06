/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: quincy <quincy@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 15:16:10 by quincy        #+#    #+#                 */
/*   Updated: 2024/12/11 10:36:35 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdint.h>

// STRUCTS
// 	Linked lists
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_listdoub
{
	void				*content;
	struct s_listdoub	*prev;
	struct s_listdoub	*next;
}	t_listdoub;

//	Vectors
typedef struct s_vector
{
	void		*items;
	size_t		item_size;
	size_t		capacity;
	size_t		size;
}	t_vector;

typedef struct s_vector_ptr
{
	void		**items;
	size_t		item_size;
	size_t		capacity;
	size_t		size;
}	t_vector_ptr;

// FUNCTIONS
// 	Characters

int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);

// 	Lists
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstdoubadd_back(t_listdoub **lst, t_listdoub *new);
void		ft_lstdoubadd_front(t_listdoub **lst, t_listdoub *new);
t_listdoub	*ft_lstdoublast(t_listdoub *lst);
t_listdoub	*ft_lstdoubnew(void *content);
int			ft_lstdoubsize(t_listdoub *lst);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);

// 	Math
int			ft_hexlen(uintptr_t n);
int			ft_intlen(long n);

// 	Memory
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
void		ft_free_matrix(char *matrix[]);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t len);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_realloc(void *ptr, size_t old_size, size_t new_size);

// 	Output
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putnbr(long n);
void		ft_putstr_fd(char *s, int fd);
int			ft_printf(const char *format, ...);
int			ft_printf_fd(int fd, const char *format, ...);
int			ft_print_matrix(char **matrix);

//	Strings
int			ft_atoi(const char *str);
long long	ft_atoll(const char *str);
char		*ft_itoa(int n);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *s);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *s);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strndup(const char *s, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*get_next_line(int fd);

//	Vectors
int			ft_vecappend_ptr(t_vector_ptr *vec, void *item);
int			ft_vecappend(t_vector *vec, void *item);
void		ft_vecdelete_ptr(t_vector_ptr *vec);
void		*ft_vecget_ptr(t_vector_ptr *vec, size_t index);
void		*ft_vecget(t_vector *vec, size_t index);
int			ft_vecinit_ptr(t_vector_ptr *vec,
				size_t capacity, size_t item_size);
int			ft_vecinit(t_vector *vec, size_t capacity, size_t item_size);
int			ft_vecinsert_ptr(t_vector_ptr *vec, void *item, size_t index);
int			ft_vecinsert(t_vector *vec, void *item, size_t index);
int			ft_vecpop_ptr(t_vector_ptr *vec, size_t index);
int			ft_vecpop(t_vector *vec, size_t index);
int			ft_vecresize_ptr(t_vector_ptr *vec, size_t new_capacity);
int			ft_vecresize(t_vector *vec, size_t new_capacity);
void		ft_vecset_ptr(t_vector_ptr *vec, void *item, size_t index);
void		ft_vecset(t_vector *vec, void *item, size_t index);

#endif