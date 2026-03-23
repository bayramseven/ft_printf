/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printffunc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayram-seven <bayram-seven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 15:33:47 by bayram-seve       #+#    #+#             */
/*   Updated: 2026/03/23 13:20:13 by bayram-seve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// 1. Karakter ve String Yazdırma
int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		if (write(1, &s[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

// 2. Sayı Yazdırma (Recursive - Mallocsuz)
int	ft_print_nbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		len += write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
		len += ft_print_nbr(n / 10);
	len += write(1, &"0123456789"[n % 10], 1);
	return (len);
}

// 3. Unsigned ve Hexadecimal Yazdırma
int	ft_print_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_print_unsigned(n / 10);
	len += write(1, &"0123456789"[n % 10], 1);
	return (len);
}

int	ft_print_hex(unsigned int n, char format)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_print_hex(n / 16, format);
	if (format == 'x')
		len += write(1, &"0123456789abcdef"[n % 16], 1);
	else
		len += write(1, &"0123456789ABCDEF"[n % 16], 1);
	return (len);
}

// 4. Pointer Adresi Yazdırma (%p)
int	ft_print_ptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (write(1, "(nil)", 5)); // Bazı sistemlerde 0x0, 42'de genellikle (nil)
	if (len == 0)
		len += write(1, "0x", 2);
	if (ptr >= 16)
		len += ft_print_hex(ptr / 16, 'x'); // Hex fonksiyonunu kullanabiliriz
	len += write(1, &"0123456789abcdef"[ptr % 16], 1);
	return (len);
}