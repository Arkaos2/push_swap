/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saibelab <saibelab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:01:20 by saibelab          #+#    #+#             */
/*   Updated: 2025/07/07 17:03:28 by saibelab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int main(int argc, char **argv)
{
	char **tab;
	t_node *pile_a = NULL;

	if (argc < 2)
		return (0);
	init_args(argc, argv, &pile_a);
}

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

	while (args[i])
	{
		value = ft_atoi(args[i]);
		ft_lstadd_back(pile, ft_lstnew(value));
		i++;
	}
	if (argc == 2)
		free_split(args);
}
