/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:33:30 by taretiuk          #+#    #+#             */
/*   Updated: 2024/07/08 12:57:18 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	if_dubles(t_stack *stack)
{
	t_stack	*tmp;

	while (stack != NULL)
	{
		tmp = stack->next;
		while (tmp != NULL)
		{
			if (stack->data == tmp->data)
			{
				return (false);
			}
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (true);
}

t_stack	*last_node(t_stack *stack)
{
	if (!stack)
	{
		return (NULL);
	}
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	return (stack);
}

int	add_node_to_end(t_stack **stack, int num)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
	{
		return (-1);
	}
	new_node->next = NULL;
	new_node->data = num;
	if (*stack == NULL)
	{
		*stack = new_node;
	}
	else
	{
		last_node(*stack)->next = new_node;
	}
	return (0);
}

int	create_stack_a(t_stack **stack, char **argv)
{
	long	num;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (!(ft_atol(argv[i], &num)))
		{
			return (-1);
		}
		if (add_node_to_end(stack, num) == -1)
		{
			ft_printf("Error\n");
			free_stack(stack);
			return (-1);
		}
		i++;
	}
	if (!if_dubles(*stack))
	{
		return (-1);
	}
	return (0);
}
