/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaousi <yassir.taous@student.1337.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:21:11 by ytaousi           #+#    #+#             */
/*   Updated: 2019/10/17 12:08:36 by ytaousi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int numb;

	numb = nb;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		numb = -nb;
	}
	if (numb < 10)
		ft_putchar_fd(numb + '0', fd);
	if (numb >= 10)
	{
		ft_putnbr_fd(numb / 10, fd);
		ft_putchar_fd((numb % 10) + '0', fd);
	}
}
