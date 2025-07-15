/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiganymmoldagulova <aiganymmoldagulova@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:28:57 by aiganymmold       #+#    #+#             */
/*   Updated: 2025/07/14 13:07:21 by aiganymmold      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_overflow(int sign, long num)
{
	long result = sign * num;
	return (result > INT_MAX || result < INT_MIN);
}

long	ft_atol(t_stack_node **a, char **argv, bool flag_argc_2)
{
	long	num;
	int		sign;
	char	*str;

	num = 0;
	sign = 1;
	str = *argv;
	while (*str && (*str == ' ' || (*str >= 9 && *str <= 13)))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		if (is_overflow(sign, num))
			error_free(a, argv, flag_argc_2);
		str++;
	}
	return (sign * num);
}
