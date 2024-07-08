/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:20:48 by taretiuk          #+#    #+#             */
/*   Updated: 2024/07/08 14:22:05 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	lift_b_node(t_stack **stack_b, t_stack *node_b)
{
	int	cost;

	cost = node_b->cost;
	if (cost == 0)
	{
		return ;
	}
	else if (node_b->direction == eFORWARD)
	{
		while (cost != 0)
		{
			rb(stack_b);
			cost--;
		}
	}
	else if (node_b->direction == eBACKWARD)
	{
		while (cost != 0)
		{
			rrb(stack_b);
			cost--;
		}
	}
}

void	lift_a_node(t_stack **stack_a, t_stack *node_a)
{
	int	cost;

	cost = node_a->cost;
	if (node_a->cost == 0)
	{
		return ;
	}
	else if (node_a->direction == eFORWARD)
	{
		while (cost != 0)
		{
			ra(stack_a);
			cost--;
		}
	}
	else if (node_a->direction == eBACKWARD)
	{
		while (cost != 0)
		{
			rra(stack_a);
			cost--;
		}
	}
}

void	push_node(t_stack **b, t_stack **a, t_stack *node_b, t_stack *node_a)
{
	int	value;

	lift_b_node(b, node_b);
	lift_a_node(a, node_a);
	if (pop(b, &value) != 0)
	{
		push(a, value);
		write(1, "pa\n", 3);
	}
}
