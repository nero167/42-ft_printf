/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namirtha <namirtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:46:33 by namirtha          #+#    #+#             */
/*   Updated: 2024/04/13 13:51:07 by namirtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
