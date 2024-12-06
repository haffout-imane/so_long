/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihaffout <ihaffout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 22:03:01 by ihaffout          #+#    #+#             */
/*   Updated: 2024/04/27 14:35:30 by ihaffout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_so_long
{
	int		size_x;
	int		size_y;

	char	**map;

	void	*mlx_ptr;
	void	*mlx_window;
	void	*img;
	int		x_player;
	int		y_player;
	int		coins;
	int		collectible;
	int		moves;
}			t_so_long;

/*-------------------------------- SO_LONG --------------------------------*/

int			handle_key(int keycode, t_so_long *data);
void		get_the_map(t_so_long *data, char *file, int fd);
void		create_window(t_so_long *data, char *file);
void		render_game(t_so_long *data);

/*-------------------------------- UTILS --------------------------------*/

//--------- check ---------//
void		check_start_exit(char **str, int len, t_so_long *data);
void		check_coins(char **str, int len, t_so_long *data);
void		check_name(char *name, t_so_long *data);
void		check_walls(char **str, int len, t_so_long *data);
void		check_path(t_so_long *data, char *file, int len, char **str);
void		check_rectangular(char **str, int len, t_so_long *data);
void		check_characters(char **str, int len, t_so_long *data);

//--------- moves ---------//
void		right(t_so_long *data);
void		left(t_so_long *data);
void		up(t_so_long *data);
void		down(t_so_long *data);

//--------- image ---------//
void		put_image(t_so_long *data, int x, int y, char *file);
void		choose_image(int x_map, int y_map, t_so_long *data);

// --------- errors ---------//
int			ft_destroy(t_so_long *data);
void		ft_exit(char *str, t_so_long *data, char **map, int len);
void		ft_exit_2(char **str, char **cpy, int len, t_so_long *data);

// --------- utils ---------//
int			count_the_lines(char *file);
void		ft_putnbr(int nbr);
void		player_position(t_so_long *data, char **str, int len);
size_t		ft_strlen(const char *s);

//--------- get_next_line ---------//
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char		*get_next_line(int fd);
char		*ft_strchr(const char *s, int c);
char		*ft_free(char *buffer);
char		*ft_strjoin(char const *s1, char const *s2);
void		ft_bzero(void *s, size_t n);

#endif
