/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movenmy_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboufqir <iboufqir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:24:59 by iboufqir          #+#    #+#             */
/*   Updated: 2024/04/28 14:40:54 by iboufqir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	enemy_dir3(t_long *data)
{
	if (data->map[data->nx + 1][data->ny] == '0')
	{
		data->map[data->nx][data->ny] = '0';
		data->map[data->nx + 1][data->ny] = 'N';
	}
	else if (data->map[data->nx + 1][data->ny] == 'P')
	{
		data->map[data->nx][data->ny] = '0';
		data->map[data->nx + 1][data->ny] = 'N';
		msg_error(-2, "💥😵💥💥💥💥 Game Over 💥💥💥💥😵💥\n", data);
	}
}

static void	enemy_dir2(t_long *data)
{
	if (data->map[data->nx - 1][data->ny] == '0')
	{
		data->map[data->nx][data->ny] = '0';
		data->map[data->nx - 1][data->ny] = 'N';
	}
	else if (data->map[data->nx - 1][data->ny] == 'P')
	{
		data->map[data->nx][data->ny] = '0';
		data->map[data->nx - 1][data->ny] = 'N';
		msg_error(-2, "💥😵💥💥💥💥 Game Over 💥💥💥💥😵💥\n", data);
	}
}

static void	enemy_dir1(t_long *data)
{
	if (data->map[data->nx][data->ny + 1] == '0')
	{
		data->map[data->nx][data->ny] = '0';
		data->map[data->nx][data->ny + 1] = 'N';
	}
	else if (data->map[data->nx][data->ny + 1] == 'P')
	{
		data->map[data->nx][data->ny] = '0';
		data->map[data->nx][data->ny + 1] = 'N';
		msg_error(-2, "💥😵💥💥💥💥 Game Over 💥💥💥💥😵💥\n", data);
	}
}

static void	enemy_dir(t_long *data, int r)
{
	if (r == 0)
	{
		if (data->map[data->nx][data->ny - 1] == '0')
		{
			data->map[data->nx][data->ny] = '0';
			data->map[data->nx][data->ny - 1] = 'N';
		}
		else if (data->map[data->nx][data->ny - 1] == 'P')
		{
			data->map[data->nx][data->ny] = '0';
			data->map[data->nx][data->ny - 1] = 'N';
			msg_error(-2, "💥😵💥💥💥💥 Game Over 💥💥💥💥😵💥\n", data);
		}
	}
	else if (r == 1)
		enemy_dir1(data);
	else if (r == 2)
		enemy_dir2(data);
	else if (r == 3)
		enemy_dir3(data);
}

int	enemy_pos(t_long *data)
{
	int	i;
	int	j;
	int	r;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N')
			{
				r = rand() % 4;
				data->nx = i;
				data->ny = j;
				enemy_dir(data, r);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
