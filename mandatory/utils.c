/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihaffout <ihaffout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 10:39:12 by ihaffout          #+#    #+#             */
/*   Updated: 2024/04/27 14:28:20 by ihaffout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_position(t_so_long *data, char **str, int len)
{
	size_t	x;
	int		y;

	y = 0;
	while (y < len)
	{
		x = 0;
		while (x < ft_strlen(str[0]))
		{
			if (str[y][x] == 'P')
			{
				data->x_player = x;
				data->y_player = y;
			}
			x++;
		}
		y++;
	}
}

int	count_the_lines(char *file)
{
	int		fd;
	int		len;
	char	*str;

	fd = open(file, O_RDONLY);
	len = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		len++;
		free(str);
	}
	close(fd);
	return (len);
}

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{
		c = (nbr + '0');
		write(1, &c, 1);
	}
}
