/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledio <ledio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:49:14 by ldurmish          #+#    #+#             */
/*   Updated: 2024/10/08 14:19:10 by ledio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/**======================================================================= Libraries =======================================================================**/
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

/**=================================================================== Macros and Defines ===================================================================**/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/**====================================================================== Linked Lists ======================================================================**/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/**================================================================= ft_printf Structures ===================================================================**/
typedef struct ft_printf
{
	va_list		args;
	int			dash;
	int			zero;
	int			point;
	int			plus;
	int			space;
	int			hash;
	int			width;
	int			length;
	int			precision;
	int			baselen;
	char		specifier;
	char		*base;
	int			base_n;
}	t_print;

/**=============================================================== Get Next Line Structures =================================================================**/
typedef struct s_gnl
{
	char			*data;
	int				len;
	struct s_gnl	*next;
	int				to_delete;
	int				found_newline;
}			t_gnl_list;

typedef struct s_glfl
{
	char			*tmp;
	char			*line;
	char			*new_line;
	char			*part;
	t_gnl_list		*temp;
}			t_glfl;

/**====================================================================== Prototypes ====================================================================== **/

/*-------------------------------------------------------------------- Memory Functions --------------------------------------------------------------------*/
void							*ft_memset(void *s, int c, size_t n);
void							ft_bzero(void *s, size_t n);
void							*ft_memcpy(void *dest, const void *source, size_t num);
void							*ft_memmove(void *dest, const void *src, size_t n);
void							*ft_memchr(const void *s, int c, size_t n);
int								ft_memcmp( const void *str1, const void *str2, size_t num);

/*-------------------------------------------------------------------- String Functions --------------------------------------------------------------------*/
int								ft_isalnum(int c);
int								ft_isalpha(int c);
int								ft_isascii(int c);
int								ft_isdigit(int c);
int								ft_isprint(int c);
int								ft_strlen(const char *str);
size_t							ft_strlcpy(char *dest, const char *src, size_t size);
size_t							ft_strlcat(char *dest, const char *src, size_t size);
int								ft_toupper(int c);
int								ft_tolower(int c);
char							*ft_strchr(const char *s, int c);
char							*ft_strrchr(const char *str, int c);
int								ft_strncmp(const char *str1, const char *str2, size_t n);
char							*ft_strnstr(const char *str, const char *subs, size_t len);
int								ft_atoi(const char *str);
char							*ft_strdup(const char *s);

/*------------------------------------------------------------------- Memory Allocations -------------------------------------------------------------------*/
void							*ft_calloc(size_t count, size_t size);
char							*ft_substr(char const *s, unsigned int start, size_t len);
char							*ft_strjoin(char const *s1, char const *s2);
char							*ft_strtrim(char const *s1, char const *set);
char							**ft_split(char const *s, char c);
char							*ft_itoa(int n);

/*------------------------------------------------------------------ String Manipulation ------------------------------------------------------------------*/
char							*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void							ft_striteri(char *s, void (*f)(unsigned int, char*));

/*-------------------------------------------------------------------- File Descriptor --------------------------------------------------------------------*/
void							ft_putchar_fd(char c, int fd);
void							ft_putstr_fd(char *s, int fd);
void							ft_putendl_fd(char *s, int fd);
void							ft_putnbr_fd(int n, int fd);

/* ------------------------------------------------------------------ Linked list operations ------------------------------------------------------------------*/

int								ft_lstsize(t_list *lst);
t_list							*ft_lstnew(void *content);
void							ft_lstadd_front(t_list **lst, t_list *new);
t_list							*ft_lstlast(t_list *lst);
void							ft_lstadd_back(t_list **lst, t_list *new);
void							ft_lstdelone(t_list *lst, void (*del)(void*));
void							ft_lstclear(t_list **lst, void (*del)(void*));
void							ft_lstiter(t_list *lst, void (*f)(void *));
t_list							*ft_lstmap(t_list *lst, void *(*f)(void *),
									void (*del)(void *));

/**================================================================= ft_printf Functions ================================================================= **/

/*----------------------------------------------------------------- Main ft_printf function -----------------------------------------------------------------*/
int								ft_printf(const char *str, ...);

/*-------------------------------------------------------------- Helper functions for ft_printf --------------------------------------------------------------*/
void							ft_handle_char(t_print *print);
int								ft_get_width(t_print *print, const char *str, int pos);
int								ft_get_precision(t_print *print, const char *str, int pos);
void							ft_putnum_base(long int n, char *base);
int								ft_len_base(long int n, int base);
void							ft_pad_zeros(t_print *print, int len);
void							ft_right_align(t_print *print, int len);
void							ft_left_align(t_print *print, int len);
void							ft_handle_percentage(t_print *print);
void							ft_handle_pointer(t_print *print);
void							ft_init_print(t_print *print);

/*-------------------------------------------------------------- Error checking for ft_printf --------------------------------------------------------------*/
int								ft_error_handle(t_print *print, const char *format,
									int pos);
int								ft_check_error(const char *format, int pos);

/*----------------------------------------------------------- Functions to print specific values -----------------------------------------------------------*/
void							ft_put_nbr_un(t_print *print);
void							ft_print_hex(t_print *print);
void							ft_putchar(char c);
void							ft_handle_string(t_print *print);
void							ft_put_nbr(t_print *print);

/**=============================================================== Get Next Line Functions =============================================================== **/

/*------------------------------------------------------------- Get Next Line Main Function -------------------------------------------------------------*/
char							*get_next_line(int fd);

/*----------------------------------------------------------- Helper functions for Get Next Line -----------------------------------------------------------*/
void							ft_add_node(t_gnl_list **head, char *str);
void							ft_remove_data(t_gnl_list **head);
void							*ft_clear_list(t_gnl_list **list, t_gnl_list *clean_node,
									char *buf, int del_one);
char							*ft_strchr(const char *s, int c);

#endif