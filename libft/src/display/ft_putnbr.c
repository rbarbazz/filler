/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:13:51 by rbarbazz          #+#    #+#             */
/*   Updated: 2017/11/09 17:38:17 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long l;

	l = n;
	if (l < 0)
	{
		ft_putchar('-');
		l = -l;
	}
	if (l >= 0 && l <= 9)
		ft_putchar(l + 48);
	if (l > 9)
	{
		ft_putnbr(l / 10);
		ft_putnbr(l % 10);
	}
}
