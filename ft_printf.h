/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayram-seven <bayram-seven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 15:30:36 by bayram-seve       #+#    #+#             */
/*   Updated: 2026/03/02 16:06:13 by bayram-seve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

/* Ana fonksiyon prototipi - Subject ile birebir aynı olmalı [cite: 98] */
int	ft_printf(const char *format, ...);

/* Yardımcı yazdırma fonksiyonları (Mandatory: cspdiuxX%) [cite: 101, 109] */
int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_ptr(unsigned long long ptr);
int	ft_print_nbr(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_hex(unsigned int n, char format);
int	ft_print_percent(void);

#endif