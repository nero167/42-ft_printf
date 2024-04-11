/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namirtha <namirtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:45:08 by namirtha          #+#    #+#             */
/*   Updated: 2024/04/11 14:45:59 by namirtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printint(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (ft_printstr("-2147483648"));
	if (n < 0)
	{
		len += ft_printchar('-');
		n *= -1;
	}
	if (n >= 10)
		len += ft_printint(n / 10);
	len += ft_printchar('0' + (n % 10));
	return (len);
}
