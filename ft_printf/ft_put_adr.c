/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_adr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboufqir <iboufqir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:58:22 by iboufqir          #+#    #+#             */
/*   Updated: 2023/12/23 11:11:36 by iboufqir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_hexapos(unsigned long nbr, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr <= 15 && nbr >= 0)
		ft_putchr(base[nbr], count);
	else
	{
		ft_hexapos(nbr / 16, count);
		ft_hexapos(nbr % 16, count);
	}
}

void	ft_put_adr(void *p, int *count)
{
	unsigned long	pos;

	pos = (unsigned long)p;
	ft_putstr("0x", count);
	ft_hexapos(pos, count);
}
