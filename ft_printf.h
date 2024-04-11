/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namirtha <namirtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:38:54 by namirtha          #+#    #+#             */
/*   Updated: 2024/04/11 15:16:48 by namirtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_printformat(va_list ap, char format);
int	ft_printchar(int c);
int	ft_printstr(char *str);
int	ft_printhex(unsigned int n, const char format);
int	ft_printint(int n);
int	ft_printptr(void *ptr);
int	ft_printunsigned(unsigned int n);
int	ft_printptr_addr(uintptr_t n, const char format);

#endif