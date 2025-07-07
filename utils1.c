/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saibelab <saibelab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:32:48 by saibelab          #+#    #+#             */
/*   Updated: 2025/07/02 16:37:12 by saibelab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void sa(t_node **pile_a, int s)
{
	t_node *first;
	t_node *second;

	if(!pile_a || ft_lstsize(*pile_a) < 2)
		return ;
	first = *pile_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*pile_a = second;
	if(!s)
		ft_printf("sa\n");
}

void sb(t_node **pile_b, int s)
{
	t_node *first;
	t_node *second;

	if(!pile_b || ft_lstsize(*pile_b) < 2)
		return ;
	first = *pile_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*pile_b = second;
	if(!s)
		ft_printf("sb\n");
}

void ss(t_node **pile_a, t_node **pile_b)
{
	sa(pile_a, 1);
	sb(pile_b, 1);
	ft_printf("ss\n");
}

void pb(t_node **pile_a, t_node **pile_b)
{
	t_node *tmp;

	if (!pile_a || !*pile_a)
		return;

	tmp = *pile_a;
	*pile_a = tmp->next;
	tmp->next = *pile_b;
	*pile_b = tmp;
	ft_printf("pb\n");
}
void pa(t_node **pile_a, t_node **pile_b)
{
	t_node *tmp;

	if (!pile_b || !*pile_b)
		return;

	tmp = *pile_b;
	*pile_b = tmp->next;
	tmp->next = *pile_a;
	*pile_a = tmp;
	ft_printf("pa\n");
}
