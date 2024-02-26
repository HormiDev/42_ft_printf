/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:53:20 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/02/26 16:26:21 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_printf(char const *str, ...)
{
	int		cont;
	va_list	args;

	
	cont = 0;
	while (str[cont] != 0)
	{
		write(1, &str[cont], 1);
		cont++;
	}
	return (cont);
}

#include <stdio.h>

int main() {
    
	printf("Hola mundo\n");
	ft_printf("Hola mundo\n");
    
    return 0;
}