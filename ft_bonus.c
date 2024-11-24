/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboucha <haboucha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 09:31:07 by haboucha          #+#    #+#             */
/*   Updated: 2024/11/24 13:45:58 by haboucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_sharp(const char *format, va_list str, int i)
{
	if (format[i] == 'x')
		return (write(1, "0x", 2) + ft_hexa_lower(va_arg(str, unsigned long)));
	else if (format[i] == 'X')
		return (write(1, "0X", 2) + ft_hexa_upper(va_arg(str, unsigned long)));
	return (0);
}

int	format_sign(const char *format, va_list str, int i)
{
	int	num;

	num = va_arg(str, int);
	printf("%d\n",num);
	if (format[i] == '+')
	{
		if (num >= 0)
			return (write(1, "+", 1) + ft_putnbr_fd(num));
		else
			return (ft_putnbr_fd(num));
	}
	else if (format[i] == ' ')
	{
		if (num >= 0)
			return (write(1, " ", 1) + ft_putnbr_fd(num));
		else
			return (ft_putnbr_fd(num));
	}
	return (0);
}

int	printf_bonus(const char *format, ...)
{
	va_list	str;
	int		count;
	int		i;

	va_start(str, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && (format[i + 1] == '+' || format[i + 1] == ' '))
		{
			count += format_sign(format, str, i + 1);
			i += 3;
		}
		else if (format[i] == '%' && format[i + 1] == '#')
		{
			count += format_sharp(format, str, i + 2);
			i += 3;
		}
		else
			count += write(1, &format[i++], 1);
	}
	va_end(str);
	return (count);
}
int	main(void)
{
	int i=printf_bonus("%+d\n",+42);
    printf("%d\n",i);
    int g=printf("hello\n");
    printf("%d\n",g);
}
