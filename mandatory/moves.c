/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihaffout <ihaffout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 22:50:02 by ihaffout          #+#    #+#             */
/*   Updated: 2024/04/27 14:47:28 by ihaffout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(t_so_long *data)
{
	data->moves++;
	write(1, "Move : ", 7);
	ft_putnbr(data->moves);
	write(1, "\n", 1);
}

void	right(t_so_long *data)
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
	put_image(data, data->x_player + 8, data->y_player + 4,
		"./textures/rabbit.xpm");
}

void	left(t_so_long *data)
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
	put_image(data, data->x_player + 8, data->y_player + 4,
		"./textures/rabbit.xpm");
}

void	up(t_so_long *data)
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
	put_image(data, data->x_player + 8, data->y_player + 4,
		"./textures/rabbit.xpm");
}

void	down(t_so_long *data)
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
	put_image(data, data->x_player + 8, data->y_player + 4,
		"./textures/rabbit.xpm");
}
