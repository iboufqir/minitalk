/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboufqir <iboufqir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:15:05 by iboufqir          #+#    #+#             */
/*   Updated: 2024/04/15 09:36:42 by iboufqir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > (unsigned int)ft_strlen(s))
		len = (unsigned int)ft_strlen(s) - start;
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, &s[start], len);
	str[len] = '\0';
	return (str);
}
