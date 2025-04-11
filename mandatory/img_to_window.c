/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboufqir <iboufqir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:14:19 by iboufqir          #+#    #+#             */
/*   Updated: 2024/04/28 14:57:35 by iboufqir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_to_window2(t_long *data, int x, int y)
{
	if (data->c == 0)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->exit1, y * 50, x * 50);
	else
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->exit, y * 50, x * 50);
}

void	img_to_window1(t_long *data, int x, int y)
{
	if (data->map[x][y] == 'P')
	{
		if (data->face == 'x')
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->player_f, y * 50, x * 50);
		else if (data->face == 'd')
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->player_down, y * 50, x * 50);
		else if (data->face == 'u')
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->player_up, y * 50, x * 50);
		else if (data->face == 'r')
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->player_r, y * 50, x * 50);
		else if (data->face == 'l')
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->player_l, y * 50, x * 50);
	}
	else if (data->map[x][y] == 'E')
		img_to_window2(data, x, y);
}

void	img_to_window(t_long *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = -1;
		while (data->map[x][++y])
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->backgrnd, y * 50, x * 50);
			if (data->map[x][y] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->wall, y * 50, x * 50);
			else if (data->map[x][y] == 'P' || data->map[x][y] == 'E')
				img_to_window1(data, x, y);
			else if (data->map[x][y] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->coin, y * 50, x * 50);
		}
		x++;
	}
	if (data->oldmove != data->move)
		ft_printf("Hamster moved %d times\n", data->move);
	data->oldmove = data->move;
}
