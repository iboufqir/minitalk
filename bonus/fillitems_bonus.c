/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillitems_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboufqir <iboufqir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:13:38 by iboufqir          #+#    #+#             */
/*   Updated: 2024/04/28 14:40:40 by iboufqir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	fillitems1(t_long *data)
{
	data->backgrnd = mlx_xpm_file_to_image(data->mlx,
			"texture/backgrnd.xpm", &data->img_width, &data->img_height);
	data->enemy = (void **)malloc(3 * sizeof(void *));
	if (!data->enemy)
		msg_error(-2, "Error\n💥Invalid images", data);
	data->enemy[0] = mlx_xpm_file_to_image(data->mlx,
			"texture/enemy1.xpm", &data->img_width, &data->img_height);
	data->enemy[1] = mlx_xpm_file_to_image(data->mlx,
			"texture/enemy2.xpm", &data->img_width, &data->img_height);
	data->enemy[2] = mlx_xpm_file_to_image(data->mlx,
			"texture/enemy3.xpm", &data->img_width, &data->img_height);
	if (!data->wall || !data->coin || !data->exit || !data->player_r
		|| !data->player_l || !data->player_up || !data->player_down
		|| !data->player_f || !data->backgrnd || !data->enemy[0]
		|| !data->enemy[1] || !data->enemy[2] || !data->exit1)
		msg_error(-2, "Error\n💥Invalid images", data);
}

void	fillitems(t_long *data)
{
	data->wall = mlx_xpm_file_to_image(data->mlx,
			"texture/wall.xpm", &data->img_width, &data->img_height);
	data->coin = mlx_xpm_file_to_image(data->mlx,
			"texture/coin.xpm", &data->img_width, &data->img_height);
	data->exit = mlx_xpm_file_to_image(data->mlx,
			"texture/exit.xpm", &data->img_width, &data->img_height);
	data->exit1 = mlx_xpm_file_to_image(data->mlx,
			"texture/exit1.xpm", &data->img_width, &data->img_height);
	data->player_r = mlx_xpm_file_to_image(data->mlx,
			"texture/player_r.xpm", &data->img_width, &data->img_height);
	data->player_l = mlx_xpm_file_to_image(data->mlx,
			"texture/player_l.xpm", &data->img_width, &data->img_height);
	data->player_up = mlx_xpm_file_to_image(data->mlx,
			"texture/player_up.xpm", &data->img_width, &data->img_height);
	data->player_down = mlx_xpm_file_to_image(data->mlx,
			"texture/player_down.xpm", &data->img_width, &data->img_height);
	data->player_f = mlx_xpm_file_to_image(data->mlx,
			"texture/player_f.xpm", &data->img_width, &data->img_height);
	data->backgrnd = mlx_xpm_file_to_image(data->mlx,
			"texture/backgrnd.xpm", &data->img_width, &data->img_height);
	fillitems1(data);
}
