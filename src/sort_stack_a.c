/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:17:05 by taretiuk          #+#    #+#             */
/*   Updated: 2024/07/08 14:41:12 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	find_target_node(t_stack *stack_a, int index, t_stack **target_node)
{
	int	i;

	i = 0;
	*target_node = stack_a;
	while (i <= index && *target_node != NULL)
	{
		if (i == index)
		{
			return ;
		}
		*target_node = (*target_node)->next;
		i++;
	}
	*target_node = NULL;
}

int	find_cheapest_node(t_stack *stack, t_stack **cheapest_node)
{
	t_stack	*current;

	current = stack->next;
	*cheapest_node = stack;
	if (stack == NULL)
	{
		return (-1);
	}
	while (current != NULL)
	{
		if (current->sum_cost == 0)
		{
			*cheapest_node = current;
			break ;
		}
		if (current->sum_cost < (*cheapest_node)->sum_cost)
		{
			*cheapest_node = current;
		}
		current = current->next;
	}
	return (0);
}

bool	sort_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;
	t_stack	*target_node;

	cheapest_node = NULL;
	target_node = NULL;
	while (stack_b != NULL)
	{
		if (!stack_b || !*stack_b)
		{
			return (false);
		}
		calculate_cost(*stack_a, *stack_b);
		find_cheapest_node(*stack_b, &cheapest_node);
		find_target_node(*stack_a, cheapest_node->target_index, &target_node);
		push_node(stack_b, stack_a, cheapest_node, target_node);
	}
	return (true);
}
