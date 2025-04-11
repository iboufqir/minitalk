/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboufqir <iboufqir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:59:48 by iboufqir          #+#    #+#             */
/*   Updated: 2024/04/28 15:03:52 by iboufqir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_ber(char *av, char *ber, t_long *data)
{
	int	i;
	int	j;

	i = ft_strlen(av) - 1;
	j = 3;
	while (j >= 0)
	{
		if (av[i] != ber[j])
			msg_error(-1, "Error\n💥Invalid Extension!", data);
		i--;
		j--;
	}
}
