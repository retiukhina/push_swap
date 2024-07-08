/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:36:28 by taretiuk          #+#    #+#             */
/*   Updated: 2024/07/08 14:40:23 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef enum enumeration
{
	eFORWARD,
	eBACKWARD
}	t_direction;

typedef struct s_stack
{
	int				target_index;
	int				data;
	int				index;
	int				cost;
	int				sum_cost;
	t_direction		direction;
	struct s_stack	*next;
}	t_stack;

int		empty_stack_error(t_stack **stack_a, t_stack **stack_b);
bool	find_min(t_stack *stack, int *num);
void	final_rotation(t_stack **stack);
bool	push(t_stack **stack, int value);
bool	pop(t_stack **stack, int *value);
bool	calculate_cost(t_stack *stack_a, t_stack *stack_b);
bool	find_max(t_stack *stack, int *num);
bool	find_min(t_stack *stack, int *num);
bool	find_target_index(t_stack *stack, int number, t_stack **target);
int		find_index(t_stack *stack, int number);
bool	sort_stack_a(t_stack **stack_a, t_stack **stack_b);
void	push_node(t_stack **b, t_stack **a, t_stack *node_b, t_stack *node_a);
int		create_stack_b(t_stack **stack_a, t_stack **stack_b);
void	rb(t_stack **stack);
void	rrb(t_stack **stack);
void	ra(t_stack **stack);
void	rra(t_stack **stack);
void	sa(t_stack **stack);
void	sort_3(t_stack **stack_a);
int		list_size(t_stack *stack, int *out_size);
int		choose_sort(t_stack **stack_a, t_stack **stack_b);
bool	if_sorted(t_stack *stack);
int		create_stack_a(t_stack **stack, char **argv);
bool	ft_atol(const char *str, long *num);
int		parse_second_argument(char *str, t_stack **stack);
int		error_create_stack(char **split_argv, t_stack **stack);
int		error_split(char **array);
void	free_2d_array(char **array);
void	free_stack(t_stack **stack);
int		check_number_arguments(int argc, char **array);

#endif
