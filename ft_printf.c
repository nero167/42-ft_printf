/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namirtha <namirtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:29:17 by namirtha          #+#    #+#             */
/*   Updated: 2024/04/11 16:35:25 by namirtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	size_t	len;

	va_start(ap, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			len += ft_printformat(ap, format[++i]);
		else
		{
			len += ft_printchar(format[i]);
			if (len < 0)
				return (-1);
		}
		i++;
	}
	va_end(ap);
	return (len);
}

int	ft_printformat(va_list ap, char format)
{
	size_t	len;

	len = 0;
	if (format == 'c')
		len += ft_printchar(va_arg(ap, int));
	else if (format == 's')
		len += ft_printstr(va_arg(ap, char *));
	else if (format == 'p')
		len += ft_printptr((void *)va_arg(ap, unsigned long long));
	else if (format == 'd' || format == 'i')
		len += ft_printint(va_arg(ap, int));
	else if (format == 'u')
		len += ft_printunsigned(va_arg(ap, unsigned int));
	else if (format == 'x')
		len += ft_printhex(va_arg(ap, unsigned int), 0);
	else if (format == 'X')
		len += ft_printhex(va_arg(ap, unsigned int), 1);
	else if (format == '%')
		len += write(1, "%", 1);
	return (len);
}
