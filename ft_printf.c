/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:53:20 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/02/27 20:59:21 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>



int	ft_conversion(char conv, void *arg)
{
	if (conv == 'd')
		{
			printf(ft_itoa((int) arg));
		}
	return (0);
}

int	ft_printf(char const *str, ...)
{
	int		cont;
	int		narg;
	int		len;
	va_list varg;
	void	*arg;
	
	va_start(varg, str);
	cont = 0;
	narg = 0;
	len = 0;
	while (str[cont] != 0)
	{
		if (str[cont++] == '%')
			{
				arg = va_arg(varg, void *);
				len = len + ft_conversion(str[cont++], arg);
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
    
	printf("Hola mundo\n");
	ft_printf("Hola mundo\n");
    
    return 0;
}