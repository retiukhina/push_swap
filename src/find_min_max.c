/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:18:52 by taretiuk          #+#    #+#             */
/*   Updated: 2024/07/08 13:44:16 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	find_max(t_stack *stack, int *num)
{
	*num = stack->data;
	while (stack)
	{
		if (stack->data > *num)
		{
			*num = stack->data;
		}
		stack = stack->next;
	}
	return (true);
}

bool	find_min(t_stack *stack, int *num)
{
	*num = stack->data;
	while (stack)
	{
		if (stack->data < *num)
		{
			*num = stack->data;
		}
		stack = stack->next;
	}
	return (true);
}
