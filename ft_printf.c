/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:53:20 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/02/29 17:17:22 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

int	ft_conversion(char conv, va_list arg)
{
	int		len;

	if (conv == 'd')
	{
		len = ft_putnbr_base(va_arg(arg, int), "0123456789", 10);
	}
	return (len);
}

int	ft_printf(char const *str, ...)
{
	int		cont;
	int		narg;
	int		len;
	va_list varg;
	
	va_start(varg, str);
	cont = 0;
	narg = 0;
	len = 0;
	while (str[cont] != 0)
	{
		if (str[cont] == '%')
			{
				cont++;
				len = len + ft_conversion(str[cont++], varg);
			}
		write(1, &str[cont], 1);
		cont++;
		len++;
	}
	va_end(varg);
	return (len);
}

#include <stdio.h>

int main() {
    
	printf("Hola mundo %d\n", 10);
	ft_printf("Hola mundo %d\n", 10);
    
    return 0;
}