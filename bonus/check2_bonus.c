/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihaffout <ihaffout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 01:11:33 by ihaffout          #+#    #+#             */
/*   Updated: 2024/04/27 14:49:29 by ihaffout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	flood_fill(char **str, int x, int y, int len)
{
	if (x < 0 || (size_t)x >= ft_strlen(str[0]) || y >= len || y < 0)
		return ;
	if (str[y][x] == '1')
		return ;
	else
		str[y][x] = '1';
	flood_fill(str, x + 1, y, len);
	flood_fill(str, x, y + 1, len);
	flood_fill(str, x - 1, y, len);
	flood_fill(str, x, y - 1, len);
}

char	**mapcpy(char *file, int len, t_so_long *data, char **str)
{
	int		y;
	int		fd;
	char	**cpy;

	y = 0;
	fd = open(file, O_RDONLY);
	cpy = malloc(sizeof(char *) * len);
	if (!cpy)
	{
		while (y < len)
			free(str[y++]);
		free(str);
		free(data);
		exit(0);
	}
	y = 0;
	while (y < len)
	{
		cpy[y] = get_next_line(fd);
		y++;
	}
	close(fd);
	return (cpy);
}

void	check_path(t_so_long *data, char *file, int len, char **str)
{
	size_t	x;
	int		y;
	char	**cpy;

	cpy = mapcpy(file, len, data, str);
	flood_fill(cpy, data->x_player, data->y_player, len);
	y = 0;
	while (y < len)
	{
		x = 0;
		while (x < ft_strlen(cpy[0]) - 1)
		{
			if (cpy[y][x] != '1' && cpy[y][x] != '0' && cpy[y][x] != 'Z')
				ft_exit_2(str, cpy, len, data);
			x++;
		}
		y++;
	}
	y = 0;
	while (y < len)
		free(cpy[y++]);
	free(cpy);
	return ;
}

void	check_walls(char **str, int len, t_so_long *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[0][j] && str[0][j] != '\n' && str[len - 1][j] && str[len
		- 1][j] != '\n')
	{
		if ((str[0][j] != '1' || str[len - 1][j] != '1'))
			ft_exit("Error\nInvalid map\n", data, str, len);
		j++;
		i++;
	}
	j = 0;
	while (j < len)
	{
		if (str[j][0] != '1' || str[j][i - 1] != '1')
			ft_exit("Error\nInvalid map\n", data, str, len);
		j++;
	}
}
