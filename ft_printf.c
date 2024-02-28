/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:53:20 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/02/28 17:10:58 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

char	*ft_itoa(int n);

int	ft_conversion(char conv, void *arg)
{
	int		len;
	char	*str;

	if (conv == 'd')
	{
		str = ft_itoa((int) arg);
		ft_printf(str);
	}

	len = ft_strlen(str);
	free(str);
	return (len);
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