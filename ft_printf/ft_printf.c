/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboufqir <iboufqir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:07:34 by iboufqir          #+#    #+#             */
/*   Updated: 2023/12/23 11:30:50 by iboufqir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(va_list pe, const char c, int *count)
{
	if (c == '%')
		ft_putchr(c, count);
	else if (c == 'c')
		ft_putchr(va_arg(pe, int), count);
	else if (c == 's')
		ft_putstr(va_arg(pe, char *), count);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(pe, int), count);
	else if (c == 'x' || c == 'X')
		ft_hexanbr(va_arg(pe, unsigned int), c, count);
	else if (c == 'p')
		ft_put_adr(va_arg(pe, void *), count);
	else if (c == 'u')
		ft_putnbr(va_arg(pe, unsigned int), count);
	else
		ft_putchr(c, count);
}

int	ft_printf(const char *format, ...)
{
	va_list	pe;
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (write(1, "", 0))
		return (-1);
	va_start(pe, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!format[i + 1])
				break ;
			ft_format(pe, format[++i], &count);
		}
		else
			ft_putchr(format[i], &count);
		i++;
	}
	va_end(pe);
	return (count);
}
