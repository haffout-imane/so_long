/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihaffout <ihaffout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:52:17 by ihaffout          #+#    #+#             */
/*   Updated: 2024/04/25 11:42:50 by ihaffout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	spin_coins(t_so_long *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			if (data->map[y][x] == 'C')
			{
				put_image(data, x * 75, y * 75, "./textures/grass.xpm");
				choose_coin_image(x, y, data->counter, data);
			}
			x++;
		}
		y++;
	}
	data->counter++;
	if (data->counter == 4)
		data->counter = 0;
}

void	enemey_moves(t_so_long *data)
{
	int	random;

	random = rand() % 4;
	if (random == 0)
		enemy_left(data);
	else if (random == 1)
		enemy_right(data);
	else if (random == 2)
		enemy_up(data);
	else if (random == 3)
		enemy_down(data);
}
