/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:27:17 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/03/06 11:16:33 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(long n, char *base, int lenbase)
{
	int		len;

	len = 0;
	if (lenbase == 0)
		lenbase = ft_strlen(base);
	if (n < 0)
	{
		n = n * -1;
		len = len + ft_putchar('-');
	}
	if (n > (lenbase - 1))
	{
		len = len + ft_putnbr_base (n / lenbase, base, lenbase);
		n = n % lenbase;
	}
	ft_putchar(base[n]);
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
