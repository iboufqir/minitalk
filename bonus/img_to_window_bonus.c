/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_window_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboufqir <iboufqir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:14:19 by iboufqir          #+#    #+#             */
/*   Updated: 2024/04/28 14:40:45 by iboufqir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	img_to_window2(t_long *data, int x, int y)
{
	if (data->map[x][y] == 'N')
	{
		if (data->index == 0)
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->enemy[0], y * 50, x * 50);
		else if (data->index == 1)
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->enemy[1], y * 50, x * 50);
		else if (data->index == 2)
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->enemy[2], y * 50, x * 50);
	}
	else if (data->c == 0)
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
	else if (data->map[x][y] == 'E' || data->map[x][y] == 'N')
		img_to_window2(data, x, y);
	else if (data->map[x][y] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->coin, y * 50, x * 50);
}

void	img_to_window(t_long *data)
{
	int	x;
	int	y;

	x = -1;
	mlx_clear_window(data->mlx, data->mlx_win);
	while (data->map[++x])
	{
		y = -1;
		while (data->map[x][++y])
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->backgrnd, y * 50, x * 50);
			if (data->map[x][y] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->wall, y * 50, x * 50);
			else if (data->map[x][y] == 'P' || data->map[x][y] == 'E'
				|| data->map[x][y] == 'N' || data->map[x][y] == 'C')
				img_to_window1(data, x, y);
		}
	}
	data->tmp = ft_itoa(data->move);
	mlx_string_put(data->mlx, data->mlx_win, 5, 3, 0xFFFFFF, data->tmp);
	free(data->tmp);
	data->oldmove = data->move;
}
