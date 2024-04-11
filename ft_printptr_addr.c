/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr_addr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namirtha <namirtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:05:28 by namirtha          #+#    #+#             */
/*   Updated: 2024/04/11 15:06:30 by namirtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr_addr(uintptr_t n, const char format)
{
	size_t	len;
	char	ref;

	len = 0;
	ref = 'a';
	if (format == 'X')
		ref = 'A';
	if (n >= 16)
		len += ft_printptr_addr(n / 16, format);
	n %= 16;
	if (n <= 9)
		ft_printchar(n + '0');
	else
		ft_printchar(n - 10 + ref);
	return (len + 1);
}
