/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:39:07 by taretiuk          #+#    #+#             */
/*   Updated: 2024/07/08 13:52:56 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	if_sorted(t_stack *stack)
{
	t_stack	*ptr;

	if (stack == NULL)
	{
		return (false);
	}
	ptr = stack;
	while (ptr->next != NULL)
	{
		if (ptr->data > ptr->next->data)
			return (false);
		ptr = ptr->next;
	}
	return (true);
}
