/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboufqir <iboufqir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:16:53 by iboufqir          #+#    #+#             */
/*   Updated: 2023/11/17 11:56:02 by iboufqir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_obj;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_obj = ft_lstnew(NULL);
		if (!new_obj)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_obj->content = f(lst->content);
		ft_lstadd_back(&new_list, new_obj);
		lst = lst->next;
	}
	return (new_list);
}
