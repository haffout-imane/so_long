/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_player_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihaffout <ihaffout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 22:50:02 by ihaffout          #+#    #+#             */
/*   Updated: 2024/04/27 14:48:59 by ihaffout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_moves(t_so_long *data)
{
	char	*str;
	char	*str2;
	char	*str3;

	data->moves++;
	put_image(data, 0, 0, "./textures/grass.xpm");
	put_image(data, 8, 0, "./textures/tree.xpm");
	put_image(data, 75, 0, "./textures/grass.xpm");
	put_image(data, 83, 0, "./textures/tree.xpm");
	str = "Move : ";
	str2 = ft_itoa(data->moves);
	str3 = ft_strjoin(str, str2);
	mlx_string_put(data->mlx_ptr, data->mlx_window, 10, 10, 0x00FFFFFF, str3);
	free(str2);
	free(str3);
}

void	player_right(t_so_long *data)
{
	if (data->map[data->y_player / 75][(data->x_player / 75) + 1] == '1')
		return ;
	put_image(data, data->x_player, data->y_player, "./textures/grass.xpm");
	if (data->map[data->y_player / 75][data->x_player / 75] == 'E')
		put_image(data, data->x_player + 7, data->y_player + 8,
			"./textures/hole.xpm");
	else if (data->map[data->y_player / 75][(data->x_player / 75) + 1] == 'C')
	{
		data->map[data->y_player / 75][(data->x_player / 75) + 1] = '0';
		data->collectible++;
	}
	data->x_player += 75;
	print_moves(data);
	if (data->map[data->y_player / 75][data->x_player / 75] == 'E')
	{
		if (data->collectible == data->coins)
		{
			write(1, "\nCONGRATS!!\n\n", 13);
			ft_destroy(data);
		}
	}
	else
		put_image(data, data->x_player, data->y_player, "./textures/grass.xpm");
	put_image(data, data->x_player, data->y_player + 8,
		"./textures/rabbit.xpm");
}

void	player_left(t_so_long *data)
{
	if (data->map[data->y_player / 75][(data->x_player / 75) - 1] == '1')
		return ;
	put_image(data, data->x_player, data->y_player, "./textures/grass.xpm");
	if (data->map[data->y_player / 75][data->x_player / 75] == 'E')
		put_image(data, data->x_player + 7, data->y_player + 8,
			"./textures/hole.xpm");
	else if (data->map[data->y_player / 75][(data->x_player / 75) - 1] == 'C')
	{
		data->map[data->y_player / 75][(data->x_player / 75) - 1] = '0';
		data->collectible++;
	}
	data->x_player -= 75;
	print_moves(data);
	if (data->map[data->y_player / 75][data->x_player / 75] == 'E')
	{
		if (data->collectible == data->coins)
		{
			write(1, "\nCONGRATS!!\n\n", 13);
			ft_destroy(data);
		}
	}
	else
		put_image(data, data->x_player, data->y_player, "./textures/grass.xpm");
	put_image(data, data->x_player, data->y_player + 8,
		"./textures/rabbit.xpm");
}

void	player_up(t_so_long *data)
{
	if (data->map[(data->y_player / 75) - 1][data->x_player / 75] == '1')
		return ;
	put_image(data, data->x_player, data->y_player, "./textures/grass.xpm");
	if (data->map[data->y_player / 75][data->x_player / 75] == 'E')
		put_image(data, data->x_player + 7, data->y_player + 8,
			"./textures/hole.xpm");
	if (data->map[(data->y_player / 75) - 1][data->x_player / 75] == 'C')
	{
		data->map[(data->y_player / 75) - 1][data->x_player / 75] = '0';
		data->collectible++;
	}
	data->y_player -= 75;
	print_moves(data);
	if (data->map[data->y_player / 75][data->x_player / 75] == 'E')
	{
		if (data->collectible == data->coins)
		{
			write(1, "\nCONGRATS!!\n\n", 13);
			ft_destroy(data);
		}
	}
	else
		put_image(data, data->x_player, data->y_player, "./textures/grass.xpm");
	put_image(data, data->x_player, data->y_player + 8,
		"./textures/rabbit.xpm");
}

void	player_down(t_so_long *data)
{
	if (data->map[(data->y_player / 75) + 1][data->x_player / 75] == '1')
		return ;
	put_image(data, data->x_player, data->y_player, "./textures/grass.xpm");
	if (data->map[data->y_player / 75][data->x_player / 75] == 'E')
		put_image(data, data->x_player + 7, data->y_player + 8,
			"./textures/hole.xpm");
	if (data->map[(data->y_player / 75) + 1][data->x_player / 75] == 'C')
	{
		data->map[(data->y_player / 75) + 1][data->x_player / 75] = '0';
		data->collectible++;
	}
	data->y_player += 75;
	print_moves(data);
	if (data->map[data->y_player / 75][data->x_player / 75] == 'E')
	{
		if (data->collectible == data->coins)
		{
			write(1, "\nCONGRATS!!\n\n", 13);
			ft_destroy(data);
		}
	}
	else
		put_image(data, data->x_player, data->y_player, "./textures/grass.xpm");
	put_image(data, data->x_player, data->y_player + 8,
		"./textures/rabbit.xpm");
}
