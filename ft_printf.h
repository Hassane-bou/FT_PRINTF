/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboucha <haboucha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:38:44 by haboucha          #+#    #+#             */
/*   Updated: 2024/11/24 12:17:20 by haboucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putnbr_fd(int n);
int	ft_putnbruns(unsigned int n);
int	ft_hexa_upper(unsigned long nb);
int	ft_hexa_lower(unsigned long nb);
int	printf_bonus(const char *format, ...);
int	format_sharp(const char *format, va_list str, int i);
int	format_sign(const char *format, va_list str, int i);

#endif