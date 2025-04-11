/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboufqir <iboufqir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:53:19 by iboufqir          #+#    #+#             */
/*   Updated: 2023/12/06 16:14:40 by iboufqir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_converter(int n, char *r)
{
	int	i;
	int	ng;

	i = get_num_len(n) - 1;
	ng = 0;
	if (n < 0)
	{
		ng = 1;
		n *= -1;
		r[0] = '-';
	}
	while (i >= ng)
	{
		r[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (r);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*result;

	len = get_num_len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	result = ft_calloc(len + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	result = ft_converter(n, result);
	return (result);
}
