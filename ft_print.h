/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:04:17 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/02/28 18:53:24 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

int	ft_putstr(char *s);
int	ft_strlen(const char *str);
int	ft_printf(char const *f, ...);
int	ft_putnbr_base(int n, char *base, int lenbase);
int	ft_putchar(char c);

#endif