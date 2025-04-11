/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboufqir <iboufqir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:34:53 by iboufqir          #+#    #+#             */
/*   Updated: 2024/04/28 14:41:00 by iboufqir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	render_next_frame(t_long *data)
{
	if (data->count == 500)
	{
		enemy_pos(data);
		if (data->index == 1)
			data->index++;
		else if (data->index == 2)
			data->index = 0;
		else
			data->index++;
		data->count = 0;
		img_to_window(data);
	}
	else
		data->count++;
	usleep(500);
	return (0);
}
