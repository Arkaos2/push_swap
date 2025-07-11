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


int main(int argc, char **argv)
{
	t_node *pile_a = NULL;

	if (argc < 2)
		return (0);
	init_args(argc, argv, &pile_a);
	sort_pile(pile_a, argc);
	free_pile(pile_a);
	return (0);
}
// int main(int argc, char **argv)
// {
// 	t_node *pile_a = NULL;
// 	t_node *pile_b = NULL;
// 	t_node *tmp;

// 	if (argc < 2)
// 		return (0);
// 	init_args(argc, argv, &pile_a);
// 	printf("Pile avant :\n");
// 	tmp = pile_a;
// 	while (tmp)
// 	{
// 		printf("%d\n", tmp->value);
// 		tmp = tmp->next;
// 	}
// 	printf("\n");
// 	if (node_size(pile_a) == 3)
// 		sort_three(&pile_a);
// 	else if (node_size(pile_a) == 4)
// 		sort_four(&pile_a, &pile_b);
// 	printf("\nPile apres :\n");
// 	tmp = pile_a;
// 	while (tmp)
// 	{
// 		printf("%d\n", tmp->value);
// 		tmp = tmp->next;
// 	}
// 	free_pile(pile_a);
// 	free_pile(pile_b);
// 	return (0);
// }
