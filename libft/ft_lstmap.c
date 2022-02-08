/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:22:14 by acanterg          #+#    #+#             */
/*   Updated: 2022/02/07 22:27:10 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*new;
	t_list	*temp;

	if (!lst)
		return (NULL);
	start = ft_lstnew(f(lst->content));
	if (!(start))
		return (NULL);
	temp = lst->next;
	while (temp)
	{
		new = ft_lstnew(f(temp->content));
		if (!(new))
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		ft_lstadd_back(&start, new);
		temp = temp->next;
	}
	return (start);
}
