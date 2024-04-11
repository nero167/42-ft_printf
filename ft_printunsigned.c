/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namirtha <namirtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:33:39 by namirtha          #+#    #+#             */
/*   Updated: 2024/04/11 14:53:21 by namirtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_printunsigned(n / 10);
	len += ft_printchar('0' + (n % 10));
	return (len);
}
