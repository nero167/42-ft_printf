/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namirtha <namirtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:36:07 by namirtha          #+#    #+#             */
/*   Updated: 2024/04/13 14:04:29 by namirtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned int n, const char format)
{
	size_t	len;
	char	rf;

	len = 0;
	rf = 'a';
	if (format == 'X')
		rf = 'A';
	if (n >= 16)
		len += ft_printptr_addr(n / 16, format);
	n %= 16;
	if (n <= 9)
		ft_printchar(n + '0');
	else
		ft_printchar(n - 10 + rf);
	return (len + 1);
}
