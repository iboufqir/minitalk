/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboufqir <iboufqir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:09:27 by iboufqir          #+#    #+#             */
/*   Updated: 2023/11/17 15:15:35 by iboufqir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;
	size_t	trimmed_len;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	end = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]) != NULL)
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]) != NULL)
		end--;
	trimmed_len = end - start;
	trimmed = (char *)ft_calloc(trimmed_len + 1, sizeof(char));
	if (trimmed == NULL)
		return (NULL);
	ft_strncpy(trimmed, s1 + start, trimmed_len);
	return (trimmed);
}
