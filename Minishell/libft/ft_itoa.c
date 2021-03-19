/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaousi <yassir.taous@student.1337.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 09:43:55 by ytaousi           #+#    #+#             */
/*   Updated: 2019/10/17 12:08:02 by ytaousi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digit(int n)
{
	int				i;
	unsigned int	nb;

	i = 0;
	nb = n;
	if (n == 0)
		return (1);
	if (n < 0)
		nb = -n;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static char	*ft_isnegatif(int n, unsigned int *nb)
{
	char *negatif;

	negatif = NULL;
	if (n < 0)
	{
		negatif = (char *)malloc(sizeof(char) * 2);
		if (!negatif)
			return (NULL);
		negatif[0] = '-';
		negatif[1] = '\0';
		*nb = -n;
	}
	return (negatif);
}

char		*ft_itoa(int n)
{
	char			*number;
	char			*negatif;
	int				digit;
	int				i;
	unsigned int	nb;

	i = 0;
	nb = n;
	digit = ft_count_digit(n);
	number = (char *)malloc(sizeof(char) * (digit + 1));
	if (!number)
		return (NULL);
	if (n < 0)
		negatif = ft_isnegatif(n, &nb);
	number[digit] = '\0';
	while (--digit >= 0)
	{
		number[digit] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		return (ft_strjoin(negatif, number));
	else
		return (number);
}
