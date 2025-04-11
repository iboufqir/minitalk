/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexanbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboufqir <iboufqir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:30:00 by iboufqir          #+#    #+#             */
/*   Updated: 2023/12/23 11:03:59 by iboufqir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexanbr(unsigned int nbr, const char format, int *count)
{
	char	*base;

	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr <= 15 && nbr >= 0)
		ft_putchr(base[nbr], count);
	else
	{
		ft_hexanbr(nbr / 16, format, count);
		ft_hexanbr(nbr % 16, format, count);
	}
}
