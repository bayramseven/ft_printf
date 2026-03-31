/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayseven <bayseven@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 18:15:09 by bayseven          #+#    #+#             */
/*   Updated: 2026/03/30 22:20:34 by bayseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_print_unsigned(n / 10);
	len += write(1, &"0123456789"[n % 10], 1);
	return (len);
}

int	ft_print_hex(unsigned long long n, char format)
{
	int		len;
	char	*hexmap;

	len = 0;
	if (format == 'x')
		hexmap = "0123456789abcdef";
	else
		hexmap = "0123456789ABCDEF";
	if (n >= 16)
		len += ft_print_hex(n / 16, format);
	len += write(1, &hexmap[n % 16], 1);
	return (len);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	len += write(1, "0x", 2);
	len += ft_print_hex(ptr, 'x');
	return (len);
}
