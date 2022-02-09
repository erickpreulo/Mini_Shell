/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:02:37 by egomes            #+#    #+#             */
/*   Updated: 2022/02/09 18:02:33 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft/libft.h"
// #include <stdio.h>

// typedef struct s_pessoa {
// 	int id;
// 	int age;
// } t_pessoa;

// t_pessoa *create_pessoa(int id, int age)
// {
// 	t_pessoa *pessoa = malloc(sizeof(t_pessoa));

// 	pessoa->id = id;
// 	pessoa->age = age;

// 	return (pessoa);
// }

// void print_lst(t_list **lst)
// {
// 	t_list *curr;

// 	curr = *lst;

// 	while (curr)
// 	{
// 		printf("Pessoa -> id: %d, age: %d\n", ((t_pessoa *)curr->content)->id, ((t_pessoa *)curr->content)->age);
// 		curr = curr->next;
// 	}
// }

// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*item;

// 	if (!(item = malloc(sizeof(t_list))))
// 		return (NULL);
// 	item->content = content;
// 	item->next = NULL;
// 	return (item);
// }

// void	ft_lstadd_front(t_list **lst, t_list *new)
// {
// 	new->next = *lst;
// 	*lst = new;
// }

// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	t_list	*last;

// 	if (lst)
// 	{
// 		if (*lst == NULL)
// 			*lst = new;
// 		else
// 		{
// 			last = ft_lstlast(*lst);
// 			last->next = new;
// 		}
// 	}
// }

// t_list	*ft_lstlast(t_list *lst)
// {
// 	t_list	*last;

// 	if (!(last = lst))
// 		return (NULL);
// 	while (last->next)
// 		last = last->next;
// 	return (last);
// }


// int	main()
// {
// 	t_list **lst;
// 	int ids = 0;
// 	lst = malloc(sizeof(t_list *));

// 	ft_lstadd_back(lst, ft_lstnew(create_pessoa(ids++, 12)));
// 	ft_lstadd_back(lst, ft_lstnew(create_pessoa(ids++, 24)));
// 	ft_lstadd_back(lst, ft_lstnew(create_pessoa(ids++, 36)));

// 	ft_lstadd_front(lst, ft_lstnew(create_pessoa(ids++, 48)));
// 	ft_lstadd_front(lst, ft_lstnew(create_pessoa(ids++, 60)));
// 	ft_lstadd_front(lst, ft_lstnew(create_pessoa(ids++, 72)));

// 	ft_lstadd_back(lst, ft_lstnew(create_pessoa(ids++, 100)));

// 	print_lst(lst);
// }
