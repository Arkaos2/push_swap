/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saibelab <saibelab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:21:06 by saibelab          #+#    #+#             */
/*   Updated: 2025/07/09 13:50:15 by saibelab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_valid(char *arg)
{
	int i = 0;

	if (!arg || arg[0] == '\0')
		return (0);
	if (arg[0] == '-' || arg[0] == '+')
		i++;
	if (arg[i] == '\0')
		return (0);
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int invalid_char (char **args)
{
	int i;

	i = 0;

	while(args[i])
	{
		if(!is_valid(args[i]))
			return (1);
		i++;
	}
	return (0);
}

int check_double(char **argv)
{
	int i = 0;
	int j;
	long num1;
	long num2;

	while (argv[i])
	{
		num1 = ft_atol(argv[i]);
		j = i + 1;
		while (argv[j])
		{
			num2 = ft_atol(argv[j]);
			if (num1 == num2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int is_overflow(char **args)
{
	long nb;
	int i;

	i = 0;
	while(args[i])
	{
		if (ft_strlen(args[i]) == 12)
			return (1);
		nb = ft_atol(args[i]);
		if (nb > 2147483647 || nb < -2147483648)
			return (1);
		i++;
	}
	return (0);
}
int check_error(char **args)
{
	if(invalid_char(args))
		return (1);
	if(check_double(args))
		return (1);
	if(is_overflow(args))
		return (1);
	return(0);
}

