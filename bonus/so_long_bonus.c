/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihaffout <ihaffout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 22:06:20 by ihaffout          #+#    #+#             */
/*   Updated: 2024/04/27 14:58:09 by ihaffout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_the_map(t_so_long *data, char *file, int fd)
{
	int		i;
	int		len;
	char	**str;

	i = 0;
	check_name(file, data);
	len = count_the_lines(file);
	str = malloc(sizeof(char *) * len);
	if (!str)
	{
		free(data);
		exit(0);
	}
	while (i < len)
		str[i++] = get_next_line(fd);
	close(fd);
	check_characters(str, len, data);
	check_start_exit(str, len, data);
	check_coins_enemy(str, len, data);
	check_rectangular(str, len, data);
	check_walls(str, len, data);
	positions(str, data, len);
	check_path(data, file, len, str);
	data->map = str;
}

void	create_window(t_so_long *data, char *file)
{
	int	y;

	y = 0;
	data->size_x = ft_strlen(data->map[0]) - 1;
	data->size_y = count_the_lines(file);
	if (data->size_x > 110 || data->size_y > 80)
		ft_exit("Error\nTry a smaller map", data, data->map, data->size_y);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		ft_exit("Error\nConnection failed", data, data->map, data->size_y);
	data->mlx_window = mlx_new_window(data->mlx_ptr, data->size_x * 75,
			data->size_y * 75, "so_long");
	if (!data->mlx_window)
	{
		while (y < data->size_y)
			free(data->map[y++]);
		free(data->map);
		write(1, "Error\n Try a smaller map\n", 25);
		exit(0);
	}
}

void	render_game(t_so_long *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			put_image(data, x * 75, y * 75, "./textures/grass.xpm");
			choose_image(x * 75, y * 75, data);
			x++;
		}
		y++;
	}
	return ;
}

int	handle_key(int keycode, t_so_long *data)
{
	if (keycode == 53)
		ft_destroy(data);
	else if (keycode == 0 || keycode == 123)
		player_left(data);
	else if (keycode == 13 || keycode == 126)
		player_up(data);
	else if (keycode == 1 || keycode == 125)
		player_down(data);
	else if (keycode == 2 || keycode == 124)
		player_right(data);
	return (0);
}

int	control_animation(t_so_long *data)
{
	int	x;

	x = 0;
	spin_coins(data);
	if (data->enemy_nbr > 0)
		enemey_moves(data);
	while (x < 50000000)
		x++;
	return (0);
}
