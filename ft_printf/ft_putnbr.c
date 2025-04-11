/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboufqir <iboufqir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:18:12 by iboufqir          #+#    #+#             */
/*   Updated: 2023/12/23 11:15:36 by iboufqir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(long nbr, int *count)
{
	if (nbr < 0)
	{
		ft_putchr('-', count);
		ft_putnbr(-nbr, count);
	}
	else if (nbr <= 9)
		ft_putchr(nbr + '0', count);
	else
	{
		ft_putnbr(nbr / 10, count);
		ft_putnbr(nbr % 10, count);
	}
}
