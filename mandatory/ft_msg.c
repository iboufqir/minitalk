/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboufqir <iboufqir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:11:23 by iboufqir          #+#    #+#             */
/*   Updated: 2024/04/26 09:09:00 by iboufqir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_img(t_long *data)
{
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->coin)
		mlx_destroy_image(data->mlx, data->coin);
	if (data->exit)
		mlx_destroy_image(data->mlx, data->exit);
	if (data->player_r)
		mlx_destroy_image(data->mlx, data->player_r);
	if (data->player_l)
		mlx_destroy_image(data->mlx, data->player_l);
	if (data->player_f)
		mlx_destroy_image(data->mlx, data->player_f);
	if (data->player_up)
		mlx_destroy_image(data->mlx, data->player_up);
	if (data->player_down)
		mlx_destroy_image(data->mlx, data->player_down);
	if (data->backgrnd)
		mlx_destroy_image(data->mlx, data->backgrnd);
	mlx_destroy_window(data->mlx, data->mlx_win);
}

void	*ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

void	msg_error(int i, char *msg, t_long *data)
{
	if (i == -1)
		ft_putstr_fd(msg, 2);
	else if (i == -2)
	{
		ft_free(data->lines);
		ft_free(data->map);
		destroy_img(data);
		ft_putstr_fd(msg, 2);
	}
	exit(1);
}
