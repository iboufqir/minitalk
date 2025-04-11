/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboufqir <iboufqir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:29:06 by iboufqir          #+#    #+#             */
/*   Updated: 2024/04/26 09:02:48 by iboufqir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
		return (ft_strdup(buff));
	str = (char *)malloc((ft_strlen(left_str) + ft_strlen(buff)) + 1);
	if (str == NULL)
		return (free(left_str), left_str = NULL, NULL);
	i = 0;
	j = 0;
	while (left_str[i] != '\0')
	{
		str[i] = left_str[i];
		i++;
	}
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[i] = '\0';
	free(left_str);
	return (str);
}
