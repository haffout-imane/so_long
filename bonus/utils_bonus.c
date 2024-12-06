/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihaffout <ihaffout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:40:28 by ihaffout          #+#    #+#             */
/*   Updated: 2024/04/27 14:28:48 by ihaffout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	positions(char **str, t_so_long *data, int len)
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
			if (str[y][x] == 'Z')
			{
				data->x_enemy = x * 75;
				data->y_enemy = y * 75;
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

int	ft_count(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		c;
	char	*str;

	c = ft_count(n);
	str = malloc(c + 1);
	if (!str)
		return (NULL);
	str[c] = '\0';
	while (n != 0)
	{
		str[--c] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
