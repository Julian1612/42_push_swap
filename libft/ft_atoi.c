/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 08:42:33 by jschneid          #+#    #+#             */
/*   Updated: 2022/09/15 15:28:52 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *nptr);

long	ft_atoi(const char *nptr)
{
	long	sign;
	long	num;
	long	i;

	sign = 1;
	num = 0;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\f'
		|| nptr[i] == '\t' || nptr[i] == '\r' || nptr[i] == '\v')
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		sign = 1 - 2 * (nptr[i] == '-');
		i ++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = 10 * num + (nptr[i] - 48);
		i++;
	}
	return (num * sign);
}
