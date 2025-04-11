/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboufqir <iboufqir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:42:16 by iboufqir          #+#    #+#             */
/*   Updated: 2024/04/15 09:31:39 by iboufqir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	if (!s || !f)
		return (NULL);
	res = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < (unsigned int)ft_strlen(s))
	{
		res[i] = f(i, s[i]);
		i++;
	}
	return (res);
}
