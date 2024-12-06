/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihaffout <ihaffout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:45:17 by ihaffout          #+#    #+#             */
/*   Updated: 2024/04/27 14:41:55 by ihaffout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	choose_image(int x_map, int y_map, t_so_long *data)
{
	int	x;
	int	y;

	x = x_map / 75;
	y = y_map / 75;
	if (data->map[y][x] == '1')
		put_image(data, x_map + 8, y_map, "./textures/tree.xpm");
	else if (data->map[y][x] == 'C')
		put_image(data, x_map + 17, y_map + 17, "./textures/coins.xpm");
	else if (data->map[y][x] == 'E')
		put_image(data, x_map + 7, y_map + 8, "./textures/hole.xpm");
	else if (data->map[y][x] == 'P')
	{
		data->x_player = x_map;
		data->y_player = y_map;
		put_image(data, x_map, y_map + 8, "./textures/rabbit.xpm");
	}
}

void	put_image(t_so_long *data, int x, int y, char *file)
{
	int	a;
	int	b;
	int	i;

	i = 0;
	data->img = mlx_xpm_file_to_image(data->mlx_ptr, file, &a, &b);
	if (!data->img)
	{
		while (i < data->size_y)
			free(data->map[i++]);
		free(data->map);
		exit(0);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->img, x, y);
}
