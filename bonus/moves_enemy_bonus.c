/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_enemy_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihaffout <ihaffout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:23:53 by ihaffout          #+#    #+#             */
/*   Updated: 2024/04/27 14:48:09 by ihaffout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_right(t_so_long *data)
{
	if (data->map[data->y_enemy / 75][(data->x_enemy / 75) + 1] == '1'
		|| data->map[data->y_enemy / 75][(data->x_enemy / 75) + 1] == 'C'
		|| data->map[data->y_enemy / 75][(data->x_enemy / 75) + 1] == 'E')
		return ;
	put_image(data, data->x_enemy, data->y_enemy, "./textures/grass.xpm");
	data->x_enemy += 75;
	if (data->x_enemy == data->x_player && data->y_enemy == data->y_player)
	{
		write(1, "\n):  GAMEOVER  :(\n\n", 19);
		ft_destroy(data);
	}
	put_image(data, data->x_enemy, data->y_enemy, "./textures/grass.xpm");
	put_image(data, data->x_enemy + 7, data->y_enemy + 14,
		"./textures/enemy.xpm");
}

void	enemy_left(t_so_long *data)
{
	if (data->map[data->y_enemy / 75][(data->x_enemy / 75) - 1] == '1'
		|| data->map[data->y_enemy / 75][(data->x_enemy / 75) - 1] == 'C'
		|| data->map[data->y_enemy / 75][(data->x_enemy / 75) - 1] == 'E')
		return ;
	put_image(data, data->x_enemy, data->y_enemy, "./textures/grass.xpm");
	data->x_enemy -= 75;
	if (data->x_enemy == data->x_player && data->y_enemy == data->y_player)
	{
		write(1, "\n):  GAMEOVER  :(\n\n", 19);
		ft_destroy(data);
	}
	put_image(data, data->x_enemy, data->y_enemy, "./textures/grass.xpm");
	put_image(data, data->x_enemy + 7, data->y_enemy + 14,
		"./textures/enemy.xpm");
}

void	enemy_up(t_so_long *data)
{
	if (data->map[(data->y_enemy / 75) - 1][data->x_enemy / 75] == '1'
		|| data->map[(data->y_enemy / 75) - 1][data->x_enemy / 75] == 'C'
		|| data->map[(data->y_enemy / 75) - 1][data->x_enemy / 75] == 'E')
		return ;
	put_image(data, data->x_enemy, data->y_enemy, "./textures/grass.xpm");
	data->y_enemy -= 75;
	if (data->x_enemy == data->x_player && data->y_enemy == data->y_player)
	{
		write(1, "\n):  GAMEOVER  :(\n\n", 19);
		ft_destroy(data);
	}
	put_image(data, data->x_enemy, data->y_enemy, "./textures/grass.xpm");
	put_image(data, data->x_enemy + 7, data->y_enemy + 14,
		"./textures/enemy.xpm");
}

void	enemy_down(t_so_long *data)
{
	if (data->map[(data->y_enemy / 75) + 1][data->x_enemy / 75] == '1'
		|| data->map[(data->y_enemy / 75) + 1][data->x_enemy / 75] == 'C'
		|| data->map[(data->y_enemy / 75) + 1][data->x_enemy / 75] == 'E')
		return ;
	put_image(data, data->x_enemy, data->y_enemy, "./textures/grass.xpm");
	data->y_enemy += 75;
	if (data->x_enemy == data->x_player && data->y_enemy == data->y_player)
	{
		write(1, "\n):  GAMEOVER  :(\n\n", 19);
		ft_destroy(data);
	}
	put_image(data, data->x_enemy, data->y_enemy, "./textures/grass.xpm");
	put_image(data, data->x_enemy + 7, data->y_enemy + 14,
		"./textures/enemy.xpm");
}
