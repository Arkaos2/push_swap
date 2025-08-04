#include "push_swap.h"

int find_value(t_node *pile_a, t_chunk *chunk, int *tab)
{
	int i;

	i = 0;
	while(pile_a)
	{
		if((pile_a->value >= tab[chunk->start]) && (pile_a->value <= tab[chunk->end]))
		{
			return (i);
		}
		i++;
		pile_a = pile_a->next;
	}
	return (-1);
}
void log_pose(t_node **pile_a, int pos)
{
	int size;
	int i;

	size = node_size(*pile_a);
	i = 0;
	if (pos <= size / 2)
	{
		while (i++ < pos)
			ra(pile_a, 0);
	}
	else
	{
		while (i++ < size - pos)
			rra(pile_a, 0);
	}
}

void log_pose_b(t_node **pile_b, int pos)
{
	int size;
	int i;

	size = node_size(*pile_b);
	i = 0;
	if (pos <= size / 2)
	{
		while (i++ < pos)
			rb(pile_b, 0);
	}
	else
	{
		while (i++ < size - pos)
			rrb(pile_b, 0);
	}
}
int choose_chunk_count(int size)
{
	if (size <= 100)
		return (5);
	else if (size <= 200)
		return (6);
	else if (size <= 300)
		return (8);
	else if (size <= 400)
		return (10);
	else if (size <= 500)
		return (11);
	else if (size <= 1000)
		return (13);
	else
		return (18);
}

int find_max_position(t_node *pile)
{
	int max;
	int pos_max;
	int pos;
	t_node *tmp;

	max = pile->value;
	pos_max = 0;
	pos = 0;
	tmp = pile;
	while (tmp)
	{
		if (tmp->value > max)
		{
			max = tmp->value;
			pos_max = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return pos_max;
}
