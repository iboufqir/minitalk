/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboufqir <iboufqir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:35:16 by iboufqir          #+#    #+#             */
/*   Updated: 2023/11/15 12:48:02 by iboufqir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			cc ;
	char			*r;

	i = 0;
	r = NULL;
	cc = (char)c;
	while (s[i])
	{
		if (s[i] == cc)
			r = (char *)&s[i];
		i++;
	}
	if (s[i] == cc)
		r = (char *) &s[i];
	return (r);
}
