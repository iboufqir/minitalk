/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboufqir <iboufqir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:50:34 by iboufqir          #+#    #+#             */
/*   Updated: 2024/04/17 14:45:01 by iboufqir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static int	word_count(const char *str, char c)
{
	int	count;
	int	x;

	count = 0;
	x = 0;
	while (*str)
	{
		if (*str != c && x == 0)
		{
			x = 1;
			count++;
		}
		else if (*str == c)
			x = 0;
		str++;
	}
	return (count);
}

static void	ft_initiate_vars(int *i, int *j, int *start)
{
	*i = -1;
	*j = 0;
	*start = -1;
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		start;

	if (!s || !s[0])
		return (NULL);
	ft_initiate_vars(&i, &j, &start);
	res = ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (!res)
		return (NULL);
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			res[j] = ft_substr(s, start, i - start);
			if (!(res[j]))
				return (ft_free(res, j));
			start = -1;
			j++;
		}
	}
	return (res);
}
