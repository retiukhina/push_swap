/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:19:05 by taretiuk          #+#    #+#             */
/*   Updated: 2024/07/08 13:56:12 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next_node;

	current = *stack;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*stack = NULL;
	return ;
}

int	empty_stack_error(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("Error\n");
	free_stack(stack_a);
	free_stack(stack_b);
	exit (-1);
}

void	free_2d_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return ;
}

int	error_split(char **array)
{
	free_2d_array(array);
	ft_printf("Error\n");
	exit (-1);
}

int	error_create_stack(char **array, t_stack **stack)
{
	free_2d_array(array);
	free_stack(stack);
	ft_printf("Error\n");
	exit (-1);
}
