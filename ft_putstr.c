/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:59:51 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/03/04 18:14:22 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	len;

	len = 6;
	if (s != 0)
	{
		len = ft_strlen(s);
		write(1, s, len);
	}
	else
		write(1, "(null)", 6);
	return (len);
}
