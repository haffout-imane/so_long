/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihaffout <ihaffout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:13:00 by ihaffout          #+#    #+#             */
/*   Updated: 2024/04/27 15:02:24 by ihaffout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_destroy(t_so_long *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	exit(0);
}

void	ft_exit(char *str, t_so_long *data, char **map, int len)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	i = 0;
	while (i < len)
		free(map[i++]);
	free(map);
	free(data);
	exit(0);
}

void	ft_exit_2(char **str, char **cpy, int len, t_so_long *data)
{
	int	y;

	y = 0;
	while (y < len)
		free(cpy[y++]);
	free(cpy);
	ft_exit("Error\nInvalid map\n", data, str, len);
}
