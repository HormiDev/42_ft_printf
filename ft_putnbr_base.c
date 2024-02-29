/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:27:17 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/02/29 20:08:02 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

int	ft_putnbr_base(long n, char *base, int lenbase)
{
	long	nbr;
	int		len;

	nbr = n;
	len = 0;
	if (lenbase == 0)
		lenbase = ft_strlen(base);
	if (nbr < 0)
	{
		nbr = nbr * -1;
		ft_putchar('-');
		len++;
	}
	if (nbr > lenbase - 1)
	{
		len = len + ft_putnbr_base (nbr / lenbase, base, lenbase);
		nbr = nbr % lenbase;
	}
	ft_putchar(base[nbr]);
	len++;
	return (len);
}
/*
#include <fcntl.h>

int main()
{
	int number = -2147483648;

	printf(": len %d ", ft_putnbr_base(number, "0123456789", 0));

	return 0;
}
*/