/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namirtha <student.42heilbronn.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:29:17 by namirtha          #+#    #+#             */
/*   Updated: 2024/04/07 16:26:26 by namirtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	size_t	len;

	va_start(ap, format);
	i = 0;
	while (*format)
	{
		if (format[i] == '%')
			len += ft_printformat(&ap, format[++i]);
		else
			len += ft_printchar(format[i]);
		i++;
	}
	va_end(ap);
	return (len);
}

int	ft_printformat(va_list *ap, char format)
{
	size_t len;

	len = 0;
	if (format == 'c')
		len += ft_printchar(va_arg(*ap, int));
	else if (format == 's')
		len += ft_printstr(va_arg(*ap, char *));
	else if (format == 'p')
		len += ft_printpointer(va_arg(*ap, unsigned long long));
	else if (format == 'd' || format == 'i')
		len += ft_printint(va_arg(*ap, int));
	else if (format == 'u')
		len += ft_printuint(va_arg(*ap, unsigned int));
	else if (format == 'x')
		len += ft_printhex(va_arg(*ap, unsigned int), 0);
	else if (format == 'X')
		len += ft_printhex(va_arg(*ap, unsigned int), 1);
	else if (format == '%')
		len += write(1, "%", 1);
	return (len);
}

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	size_t	len;

	len = 0;
	if (str == NULL)
		return (ft_printstr("(null)"));
	while (*str)
		len += ft_printchar(*str++);
	return (len);
}