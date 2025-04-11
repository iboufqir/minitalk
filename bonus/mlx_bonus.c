/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboufqir <iboufqir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:56:14 by iboufqir          #+#    #+#             */
/*   Updated: 2024/04/28 14:40:48 by iboufqir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_exit(t_long *data)
{
	destroy_img(data);
	ft_free(data->lines);
	ft_free(data->map);
	free(data->enemy);
	ft_printf("Exit🚪❌\n");
	exit(0);
}

int	key_hook(int keycode, t_long *data)
{
	(void)data;
	if (keycode == 126 || keycode == 13)
		move_up(data);
	else if (keycode == 125 || keycode == 1)
		move_down(data);
	else if (keycode == 124 || keycode == 2)
		move_right(data);
	else if (keycode == 123 || keycode == 0)
		move_left(data);
	else if (keycode == 53)
		ft_exit(data);
	img_to_window(data);
	return (1);
}
