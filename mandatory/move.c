/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboufqir <iboufqir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:11:52 by iboufqir          #+#    #+#             */
/*   Updated: 2024/04/26 11:44:40 by iboufqir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_long *data)
{
	data->face = 'u';
	if (data->map[data->x - 1][data->y] == '0' ||
		data->map[data->x - 1][data->y] == 'C')
	{
		if (data->map[data->x - 1][data->y] == '0')
		{
			data->map[data->x][data->y] = '0';
			data->x -= 1;
			data->map[data->x][data->y] = 'P';
		}
		else
		{
			data->c -= 1;
			data->map[data->x][data->y] = '0';
			data->x -= 1;
			data->map[data->x][data->y] = 'P';
		}
		data->move += 1;
	}
	else if (data->map[data->x - 1][data->y] == 'E' && data->c == 0)
	{
		ft_printf("Hamster moved %d times\n", data->move + 1);
		msg_error(-2, "👍🎉👍🎉👍🎉 Bravo 👍🎉👍🎉👍🎉\n", data);
	}
}

void	move_down(t_long *data)
{
	data->face = 'd';
	mlx_clear_window(data->mlx, data->mlx_win);
	if (data->map[data->x + 1][data->y] == '0' ||
		data->map[data->x + 1][data->y] == 'C')
	{
		if (data->map[data->x + 1][data->y] == '0')
		{
			data->map[data->x][data->y] = '0';
			data->x += 1;
			data->map[data->x][data->y] = 'P';
		}
		else
		{
			data->c -= 1;
			data->map[data->x][data->y] = '0';
			data->x += 1;
			data->map[data->x][data->y] = 'P';
		}
		data->move += 1;
	}
	else if (data->map[data->x + 1][data->y] == 'E' && data->c == 0)
	{
		ft_printf("Hamster moved %d times\n", data->move + 1);
		msg_error(-2, "👍🎉👍🎉👍🎉 Bravo 👍🎉👍🎉👍🎉\n", data);
	}
}

void	move_right(t_long *data)
{
	data->face = 'r';
	mlx_clear_window(data->mlx, data->mlx_win);
	if (data->map[data->x][data->y + 1] == '0' ||
		data->map[data->x][data->y + 1] == 'C')
	{
		if (data->map[data->x][data->y + 1] == '0')
		{
			data->map[data->x][data->y] = '0';
			data->y += 1;
			data->map[data->x][data->y] = 'P';
		}
		else
		{
			data->c -= 1;
			data->map[data->x][data->y] = '0';
			data->y += 1;
			data->map[data->x][data->y] = 'P';
		}
		data->move += 1;
	}
	else if (data->map[data->x][data->y + 1] == 'E' && data->c == 0)
	{
		ft_printf("Hamster moved %d times\n", data->move + 1);
		msg_error(-2, "👍🎉👍🎉👍🎉 Bravo 👍🎉👍🎉👍🎉\n", data);
	}
}

void	move_left(t_long *data)
{
	data->face = 'l';
	mlx_clear_window(data->mlx, data->mlx_win);
	if (data->map[data->x][data->y - 1] == '0' ||
		data->map[data->x][data->y - 1] == 'C')
	{
		if (data->map[data->x][data->y - 1] == '0')
		{
			data->map[data->x][data->y] = '0';
			data->y -= 1;
			data->map[data->x][data->y] = 'P';
		}
		else
		{
			data->c -= 1;
			data->map[data->x][data->y] = '0';
			data->y -= 1;
			data->map[data->x][data->y] = 'P';
		}
		data->move += 1;
	}
	else if (data->map[data->x][data->y - 1] == 'E' && data->c == 0)
	{
		ft_printf("Hamster moved %d times\n", data->move + 1);
		msg_error(-2, "👍🎉👍🎉👍🎉 Bravo 👍🎉👍🎉👍🎉\n", data);
	}
}
