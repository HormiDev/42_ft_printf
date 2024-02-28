/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:27:17 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/02/28 19:12:01 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_print.h"

int	ft_putnbr_base(int n, char *base, int lenbase)
{
	long	nbr;

	nbr = n;
	if (lenbase == 0)
		lenbase = ft_strlen(base);
	if (nbr < 0)
	{
		nbr = nbr * -1;
		ft_putchar('-');
	}
	if (nbr > lenbase - 1)
	{
		ft_putnbr_base (nbr / lenbase, base, lenbase);
		nbr = nbr % lenbase;
	}
	ft_putchar(base[nbr]);
	return (0);
}
/*
int	ft_putnbr_base(int n, char *base, int lenbase)
{
	if (lenbase == 0)
		lenbase = ft_strlen(base);
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n = n * -1;
			ft_putchar('-');
		}
		if (n > lenbase - 1)
		{
			ft_putnbr_base (n / lenbase, base, lenbase);
			n = n % lenbase;
		}
		ft_putchar(base[n]);
	}
	return (0);
}
*/

#include <fcntl.h>

int main()
{
	int number = -2147483648;

	ft_putnbr_base(number, "0123456789", 0);

	return 0;
}