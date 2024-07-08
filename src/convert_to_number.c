/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:44:23 by taretiuk          #+#    #+#             */
/*   Updated: 2024/07/08 14:26:07 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	check_long_bounderies(long int result)
{
	if ((result > LONG_MAX || result < LONG_MIN)
		|| (result > INT_MAX || result < INT_MIN))
	{
		return (false);
	}
	return (true);
}

bool	ft_atol(const char *str, long *num)
{
	long	result;
	int		sign;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		result = (*str - '0') + (result * 10);
		str++;
	}
	result *= sign;
	if (!check_long_bounderies(result))
		return (false);
	*num = result;
	return (true);
}
