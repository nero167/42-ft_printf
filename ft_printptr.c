/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namirtha <namirtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:31:43 by namirtha          #+#    #+#             */
/*   Updated: 2024/04/11 14:58:25 by namirtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(void *ptr)
{
	size_t	len;

	len = 0;
	len += ft_printstr("0x");
	len += ft_printptr_addr((uintptr_t)ptr, 'x');
	return (len);
}
