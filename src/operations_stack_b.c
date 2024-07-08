/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_stack_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:19:19 by taretiuk          #+#    #+#             */
/*   Updated: 2024/07/08 13:59:00 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rb(t_stack **stack)
{
	t_stack	*first;
	t_stack	*current;

	first = *stack;
	current = *stack;
	while (current->next != NULL)
	{
		current = current->next;
	}
	*stack = first->next;
	first->next = NULL;
	current->next = first;
	write(1, "rb\n", 3);
}

void	rrb(t_stack **stack)
{
	t_stack	*second_last;
	t_stack	*last;

	second_last = NULL;
	last = *stack;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
	write(1, "rrb\n", 4);
}
