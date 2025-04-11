/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboufqir <iboufqir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:12:40 by iboufqir          #+#    #+#             */
/*   Updated: 2023/12/06 16:13:12 by iboufqir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static int	ft_check(int signe)
{
	if (signe < 0)
		return (0);
	return (-1);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				n;
	long			r;
	long			l;

	i = 0;
	r = 0;
	n = 1;
	l = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n *= -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		r = r * 10 + (str[i++] - 48);
		if (l > r)
			return (ft_check(n));
		l = r;
	}
	return (r * n);
}
