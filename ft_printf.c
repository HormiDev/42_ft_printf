/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:53:20 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/02/29 20:59:40 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

int	ft_conversion(char conv, va_list arg)
{
	int		len;

	if (conv == 'c')
		len = ft_putchar(va_arg(arg, int));
	else if (conv == 's')
		len = ft_printf(va_arg(arg, char *));
	else if (conv == 'p')
		len = ft_printf("0x") +
		ft_putnbr_base(va_arg(arg, unsigned long long), "0123456789abcdef", 16);
	else if (conv == 'd' || conv == 'i')
		len = ft_putnbr_base(va_arg(arg, int), "0123456789", 10);
	else if (conv == 'u')
		len = ft_putnbr_base(va_arg(arg, unsigned int), "0123456789", 10);
	else if (conv == 'x')
		len = ft_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef", 16);
	else if (conv == 'X')
		len = ft_putnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF", 16);
	else if (conv == '%')
		len = ft_putchar('%');
	return (len);
}

int	ft_printf(char const *str, ...)
{
	int		cont;
	int		narg;
	int		len;
	va_list	varg;

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
		else
		{
			len = len + ft_putchar(str[cont]);
			cont++;
		}
	}
	va_end(varg);
	return (len);
}

#include <stdio.h>

int main() {
	char *puntero;
	
    printf("Hola mundo\n");
	ft_printf("Hola mundo\n");

	printf("| len %d\n", printf("Hola mundo"));
	ft_printf("| len %d\n", ft_printf("Hola mundo"));

	printf("| len %d\n", printf("prueba char %c %c %c %c", 'H', 'o', 'l', 'a'));
	ft_printf("| len %d\n", ft_printf("prueba char %c %c %c %c", 'H', 'o', 'l', 'a'));

	printf("| len %d\n", printf("prueba string %s %s", "Hola", "mundo"));
	ft_printf("| len %d\n", ft_printf("prueba string %s %s", "Hola", "mundo"));
	
	printf("| len %d\n", printf("prueba puntero %p", puntero));
	ft_printf("| len %d\n", ft_printf("prueba puntero %p", puntero));

	printf("| len %d\n", printf("prueba int %%d %d %d %d", 10, 11, 12));
	ft_printf("| len %d\n", ft_printf("prueba int %%d %d %d %d", 10, 11, 12));

	printf("| len %d\n", printf("prueba int %%i %i %i %i", 10, 11, 12));
	ft_printf("| len %d\n", ft_printf("prueba int %%i %i %i %i", 10, 11, 12));

	printf("| len %d\n", printf("prueba int %%u %u %u %u", 10, 11, 12));
	ft_printf("| len %d\n", ft_printf("prueba int %%u %u %u %u", 10, 11, 12));

	printf("| len %d\n", printf("prueba hexadecimal %x", 42424242));
	ft_printf("| len %d\n", ft_printf("prueba hexadecimal %x", 42424242));

	printf("| len %d\n", printf("prueba HEXADECIMAL %X", 42424242));
	ft_printf("| len %d\n", ft_printf("prueba HEXADECIMAL %X", 42424242));
    
    return 0;
}