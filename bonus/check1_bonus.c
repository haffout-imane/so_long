/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihaffout <ihaffout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 22:09:28 by ihaffout          #+#    #+#             */
/*   Updated: 2024/04/27 14:39:45 by ihaffout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_name(char *name, t_so_long *data)
{
	int	len;

	len = 0;
	while (name[len])
		len++;
	if (name[len - 1] == 'r' && name[len - 2] == 'e' && name[len - 3] == 'b'
		&& name[len - 4] == '.')
		return ;
	free(data);
	write(1, "Error\nInvalid file\n", 19);
	exit(0);
}

void	check_characters(char **str, int len, t_so_long *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] != '0' && str[i][j] != '1' && str[i][j] != 'C'
				&& str[i][j] != 'E' && str[i][j] != 'P' && str[i][j] != 'Z'
				&& str[i][j] != '\n')
				ft_exit("Error\nInvalid map\n", data, str, len);
			j++;
		}
		i++;
	}
	return ;
}

void	check_start_exit(char **str, int len, t_so_long *data)
{
	int	i;
	int	j;
	int	p;
	int	e;

	i = 0;
	p = 0;
	e = 0;
	while (i < len)
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P')
				p++;
			else if (str[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	if (p != 1 || e != 1)
		ft_exit("Error\nInvalid map\n", data, str, len);
	return ;
}

void	check_coins_enemy(char **str, int len, t_so_long *data)
{
	int	i;
	int	j;

	i = 0;
	data->coins = 0;
	data->enemy_nbr = 0;
	while (i < len)
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'C')
				data->coins++;
			else if (str[i][j] == 'Z')
				data->enemy_nbr++;
			j++;
		}
		i++;
	}
	if (data->coins < 1 || data->enemy_nbr > 1)
		ft_exit("Error\nInvalid map\n", data, str, len);
	return ;
}

void	check_rectangular(char **str, int len, t_so_long *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[0][j] != '\n')
		j++;
	while (i < len)
	{
		if (str[i][j] != '\0' && str[i][j] != '\n')
			ft_exit("Error\nInvalid map\n", data, str, len);
		i++;
	}
	return ;
}