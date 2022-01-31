/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:02:37 by egomes            #+#    #+#             */
/*   Updated: 2022/01/31 18:28:04 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
};

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	struct node *head = NULL;
	head = (struct node *)malloc(sizeof(struct node));
	head->data = 45;
	head->link = NULL;

	printf("%d", head->data);
}
