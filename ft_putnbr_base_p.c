/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:01:55 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/03/06 11:48:33 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_p(long n, char *base, int lenbase)
{
	unsigned long	nbr;
	unsigned int	baselen;
	int				len;

	nbr = n;
	len = 0;
	baselen = lenbase;
	if (baselen == 0)
		baselen = ft_strlen(base);
	if (nbr > (baselen - 1))
	{
		len = len + ft_putnbr_base_p (nbr / baselen, base, baselen);
		nbr = nbr % baselen;
	}
	ft_putchar(base[nbr]);
	len++;
	return (len);
}
