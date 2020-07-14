/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 21:29:34 by varnaud           #+#    #+#             */
/*   Updated: 2020/07/14 20:14:03 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <term.h>
# include <signal.h>
# include <sys/ioctl.h>
# include "libft.h"
# define T_T_KEY_UP "\e[A"
# define T_T_KEY_DOWN "\e[B"
# define T_T_KEY_RIGHT "\e[C"
# define T_T_KEY_LEFT "\e[D"
# define KEY_UP 1
# define KEY_DOWN 2
# define KEY_LEFT 4
# define KEY_RIGHT 8
# define KEY_SPACE 16
# define KEY_BACKSPACE 32
# define KEY_ESCAPE 64
# define KEY_DELETE 128
# define KEY_RETURN 256
# define KEY_PAGE_UP 512
# define KEY_PAGE_DOWN 1024
# define FTS_MARGIN 2
# define FTS_CLEAR 0
# define FTS_UNDERLINE 1
# define FTS_REVERSE_VIDEO 2

int					g_signals[32];

typedef struct		s_word
{
	int				deleted;
	int				selected;
	int				current;
	int				len;
	char			*value;
	struct s_word	*next;
	struct s_word	*prev;
}					t_word;

typedef struct		s_term
{
	int				width;
	int				height;
	char			*mw[16];
}					t_term;

typedef struct		s_case
{
	t_word			*word;
	int				x;
	int				y;
	int				active;
}					t_case;

typedef struct		s_page
{
	t_case			**cases;
	t_word			*word_list;
	struct s_book	*book;
	int				mid_width;
	int				mid_height;
	int				word_width;
	int				word_height;
	int				page_no;
	int				max_words;
	int				word_count;
	struct s_page	*next;
	struct s_page	*prev;
}					t_page;

typedef struct		s_book
{
	t_word			*word_list;
	int				word_list_size;
	int				longest_word;
	int				xw_max;
	int				yw_max;
	int				xw;
	int				yw;
	int				nb_page;
	t_page			*pages;
}					t_book;

typedef struct		s_reader
{
	t_page			*page;
	t_word			*word;
	t_case			*box;
	int				bxi;
	int				byi;
}					t_reader;

typedef struct		s_keys
{
	char			*up;
	char			*down;
	char			*left;
	char			*right;
	char			*back;
	char			*del;
	char			*page_up;
	char			*page_down;
}					t_keys;

typedef struct		s_ft_select
{
	t_term			term;
	t_word			*word_list;
	t_book			book;
	t_reader		reader;
	t_keys			keys;
	int				displayed;
	int				wait_resize;
}					t_ft_select;

t_word				*create_words_list(char **never);
t_word				*add_word(char *gonna);
void				delete_word(t_word **give, t_word *you);
int					get_word_list_size(t_word *up);
void				initialize_terminal(t_ft_select *never);
void				reset_terminal(void);
t_word				*get_word_no(t_word *gonna, int let);
void				init_signals(void);
void				check_signals(t_ft_select *you);
void				set_terminal(t_ft_select *down);
int					ft_putcap(int never);
int					get_longest_word(t_word *gonna);
void				ft_select(t_ft_select *run);
int					update_display(t_ft_select *around);
void				dummy_print_words_list(t_word *and);
void				move(int desert, int you,
						t_page *never, t_ft_select *gonna);
void				clean_exit(t_ft_select *make);
void				return_exit(t_ft_select *you);
void				display(t_ft_select *cry);
void				display_debug_info(t_ft_select *never);
void				underline(char *gonna);
void				reverse_video(char *say);
void				appearance(char *goodbye, int never);
int					check_termcaps(void);
void				move_cursor_to(int gonna, int tell);
void				handle_space(t_ft_select *a);
void				handle_delete(t_ft_select *lie);
void				handle_page_up(t_ft_select *and);
void				handle_page_down(t_ft_select *hurt);
void				display_page(t_page *you, t_ft_select *never);
void				set_reader_case(t_reader *gonna);
t_page				*find_word_page(t_page *give, t_word *you);
void				free_pages(t_book *up, t_page *never);
void				handle_resize(t_ft_select *gonna);
void				set_cases(t_book *let, t_page *you, int down);
void				init_keys(t_ft_select *never);
void				move_to_next_word(t_ft_select *gonna);

#endif
