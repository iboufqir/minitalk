/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboufqir <iboufqir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:26:35 by iboufqir          #+#    #+#             */
/*   Updated: 2024/04/28 14:41:02 by iboufqir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	val_map(t_long *data, char *map)
{
	int	i;

	i = 0;
	data->ptr = read_map(map);
	if (!data->ptr)
		msg_error(-1, "Error\n💥Invalid file !", data);
	while (data->ptr[i])
	{
		if (data->ptr[0] == '\n'
			|| (data->ptr[i] == '\n' && data->ptr[i + 1] == '\n')
			|| (data->ptr[ft_strlen(data->ptr) - 1] == '\n'))
			msg_error(-1, "Error\n💥Empty line !", data);
		i++;
	}
	data->lines = ft_split(data->ptr, '\n');
	if (!data->lines)
		msg_error(-1, "Error\n💥Empty map !", data);
	free(data->ptr);
	checkchar(data->lines, data);
	lenline(data);
	checkwall(data);
	flood_fill(data->x, data->y, data);
	if (data->e != 0 || data->c != 0)
		msg_error(-1, "Error\n💥'E' or 'C' or 'P' is invalid !", data);
}

void	ft_game(t_long *data, char *str)
{
	data->face = 'x';
	data->mlx = mlx_init();
	mlx_loop_hook(data->mlx, render_next_frame, data);
	data->mlx_win = mlx_new_window(data->mlx, data->lenline * 50,
			data->nbline * 50, "Hamster Game !");
	data->pttr = read_map(str);
	if (!data->pttr)
		msg_error(-2, "Error\n", data);
	data->map = ft_split(data->pttr, '\n');
	if (!data->map)
		msg_error(-1, "Error\n💥Empty map !", data);
	free(data->pttr);
	fillitems(data);
	checkchar(data->map, data);
	img_to_window(data);
	mlx_hook(data->mlx_win, 2, 0, key_hook, data);
	mlx_hook(data->mlx_win, 17, 0, ft_exit, data);
	mlx_loop(data->mlx);
}

int	main(int ac, char **av)
{
	t_long	data;

	ft_memset(&data, 0, sizeof(t_long));
	if (ac == 2)
	{
		check_ber(av[1], ".ber", &data);
		val_map(&data, av[1]);
		ft_game(&data, av[1]);
	}
	else
		ft_printf("💥Invalid arguments !");
}
