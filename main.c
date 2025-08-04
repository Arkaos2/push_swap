/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saibelab <saibelab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:01:20 by saibelab          #+#    #+#             */
/*   Updated: 2025/07/11 14:35:58 by saibelab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void init_args(int argc, char **argv, t_node **pile)
{
	char **args;
	int i;
	int value;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	if (check_error(args))
	{
		write(2, "Error\n", 6);
		if (argc == 2)
			free_split(args);
		exit(1);
	}
	while (args[i])
	{
		value = ft_atol(args[i]);
		node_add_back(pile, node_new(value));
		i++;
	}
	if (argc == 2)
		free_split(args);
}

void print_pile(t_node *pile)
{
	while (pile)
	{
		printf("%d\n", pile->value);
		pile = pile->next;
	}
}
#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_node *pile_a = NULL;
	t_node *pile_b = NULL;

	int size;

	if (argc < 2)
		return (0);

	// Initialisation de la pile A
	init_args(argc, argv, &pile_a);


	size = node_size(pile_a);

	// Choix du tri en fonction du nombre d'éléments
	if (size == 2)
		sa(&pile_a, 0);
	else if (size == 3)
		sort_three(&pile_a);
	else if (size == 4)
		sort_four(&pile_a, &pile_b);
	else
	{
		if (is_sort(pile_a))
			return 1;
		else
			chunk_sort(&pile_a, &pile_b);
	}
	free_pile(pile_a);
	free_pile(pile_b);
	return (0);
}


