/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namirtha <namirtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:29:17 by namirtha          #+#    #+#             */
/*   Updated: 2024/04/13 14:06:41 by namirtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	size_t	len;
	int		temp;

	va_start(ap, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			temp = ft_printformat(ap, format[++i]);
			if (temp == -1)
				return (-1);
		}
		else
		{
			temp = ft_printchar(format[i]);
			if (temp < 0)
				return (-1);
		}
		len += temp;
		i++;
	}
	return (va_end(ap), len);
}

int	ft_printformat(va_list ap, char format)
{
	size_t	len;

	len = 0;
	if (format == 'c')
		len = ft_printchar(va_arg(ap, int));
	else if (format == 's')
		len = ft_printstr(va_arg(ap, char *));
	else if (format == 'p')
		len = ft_printptr((void *)va_arg(ap, unsigned long long));
	else if (format == 'd' || format == 'i')
		len = ft_printint(va_arg(ap, int));
	else if (format == 'u')
		len = ft_printunsigned(va_arg(ap, unsigned int));
	else if (format == 'x')
		len = ft_printhex(va_arg(ap, unsigned int), 'x');
	else if (format == 'X')
		len = ft_printhex(va_arg(ap, unsigned int), 'X');
	else if (format == '%')
		len = write(1, "%", 1);
	return (len);
}
