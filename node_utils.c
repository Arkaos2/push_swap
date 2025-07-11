/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saibelab <saibelab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:33:43 by saibelab          #+#    #+#             */
/*   Updated: 2025/07/11 13:24:07 by saibelab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_new(int value)
{
	t_node *new = malloc(sizeof(t_node));
	if (!new)
		return NULL;
	new->value = value;
	new->next = NULL;
	return new;
}
void	node_add_back(t_node **lst, t_node *new)
{
	t_node *tmp;

	if (!lst || !new)
		return;
	if (!*lst)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

int	node_size(t_node *lst)
{
	int count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return count;
}

t_node	*node_last(t_node *lst)
{
	if (!lst)
		return NULL;
	while (lst->next)
		lst = lst->next;
	return lst;
}
void free_pile(t_node *pile)
{
	t_node *tmp;
	while (pile)
	{
		tmp = pile;
		pile = pile->next;
		free(tmp);
	}
}
