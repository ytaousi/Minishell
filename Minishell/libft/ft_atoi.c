/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaousi <ytaousi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:13:33 by ytaousi           #+#    #+#             */
/*   Updated: 2019/10/23 05:04:14 by ytaousi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

int			ft_atoi(const char* str)
{
	int sign;
	int totale;
	int i;

	i = 0;
	sign = 1;
	totale = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if ((unsigned int)totale * 10 > 2147483647 && sign == 1)
			return (-1);
		else if ((unsigned int)totale * 10 > 2147483648 && sign == -1)
			return (0);
		totale = totale * 10 + (str[i] - '0');
		i++;
	}
	return (totale * sign);
}
