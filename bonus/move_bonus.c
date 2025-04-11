/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboufqir <iboufqir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:11:52 by iboufqir          #+#    #+#             */
/*   Updated: 2024/04/28 14:40:51 by iboufqir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
		msg_error(-2, "👍🎉👍🎉👍🎉 Bravo 👍🎉👍🎉👍🎉\n", data);
	else if (data->map[data->x - 1][data->y] == 'N')
		msg_error(-2, "💥😵💥💥💥💥 Game Over 💥💥💥💥😵💥\n", data);
}

void	move_down(t_long *data)
{
	data->face = 'd';
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
	else if (data->map[data->x + 1][data->y] == 'N')
		msg_error(-2, "💥😵💥💥💥💥 Game Over 💥💥💥💥😵💥\n", data);
	else if (data->map[data->x + 1][data->y] == 'E' && data->c == 0)
		msg_error(-2, "👍🎉👍🎉👍🎉 Bravo 👍🎉👍🎉👍🎉\n", data);
}

void	move_right(t_long *data)
{
	data->face = 'r';
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
	else if (data->map[data->x][data->y + 1] == 'N')
		msg_error(-2, "💥😵💥💥💥💥 Game Over 💥💥💥💥😵💥\n", data);
	else if (data->map[data->x][data->y + 1] == 'E' && data->c == 0)
		msg_error(-2, "👍🎉👍🎉👍🎉 Bravo 👍🎉👍🎉👍🎉\n", data);
}

void	move_left(t_long *data)
{
	data->face = 'l';
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
	else if (data->map[data->x][data->y - 1] == 'N')
		msg_error(-2, "💥😵💥💥💥💥 Game Over 💥💥💥💥😵💥\n", data);
	else if (data->map[data->x][data->y - 1] == 'E' && data->c == 0)
		msg_error(-2, "👍🎉👍🎉👍🎉 Bravo 👍🎉👍🎉👍🎉\n", data);
}
