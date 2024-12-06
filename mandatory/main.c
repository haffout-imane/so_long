/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihaffout <ihaffout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 22:01:40 by ihaffout          #+#    #+#             */
/*   Updated: 2024/04/27 15:12:48 by ihaffout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	int			fd;
	t_so_long	*data;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
		{
			write(1, "Error\nFile not found\n", 21);
			return (0);
		}
		data = malloc(sizeof(t_so_long));
		if (!data)
			return (0);
		get_the_map(data, av[1], fd);
		data->collectible = 0;
		data->moves = 0;
		create_window(data, av[1]);
		render_game(data);
		mlx_hook(data->mlx_window, 17, 0, ft_destroy, data);
		mlx_hook(data->mlx_window, 2, 0, handle_key, data);
		mlx_loop(data->mlx_ptr);
	}
}
