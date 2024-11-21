/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:26:25 by tjuvan            #+#    #+#             */
/*   Updated: 2023/11/21 16:13:19 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	which_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += put_char(va_arg(ap, int));
	else if (specifier == 's')
		count += put_str(va_arg(ap, char *));
	else if (specifier == 'i' || specifier == 'd')
		count = put_nbr(va_arg(ap, int), 10, &count, 'i');
	else if (specifier == 'u')
		count = put_nbr(va_arg(ap, unsigned int), 10, &count, 'u');
	else if (specifier == 'x')
		count = put_nbr(va_arg(ap, unsigned int), 16, &count, 'x');
	else if (specifier == 'X')
		count = put_nbr(va_arg(ap, unsigned int), 16, &count, 'X');
	else if (specifier == 'p')
		count = put_address(va_arg(ap, void *), &count);
	else if (specifier == '%')
		count += put_char('%');
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, str);
	while (*str != 0)
	{
		if (*str == '%')
			count += which_format(*(++str), ap);
		else
		{
			write(1, str, 1);
			count++;
		}
		str++;
	}
	va_end(ap);
	return (count);
}
/*
int	main(void)
{
	int	count;
	int	num = 0;
	int	num2 = -2147483647;
	char	*str = NULL;

	ft_printf("test to see return of both print functions\n");
	count = printf("%i\n", num2);
	printf("writte the number of chars orig i: %i\n", count);
	count = printf("\n");
	printf("writte the number of chars orig no: %i\n", count);
	count = ft_printf("%i\n", num2);
	ft_printf("writte the number of chars my i: %i\n", count);
	count = ft_printf("\n");
	ft_printf("writte the number of chars my no: %i\n", count);
	printf("writte the number of chars: %i\n", count);
	ft_printf("\n\ntest 2 -> 1st line printf, 2nd line ft_printf\n");

	printf("char:%c,\tstr:%s,\tint:%i,\tdec:%d,
	\tunsigned:%u,\thexl:%x,\thexU:%X,\taddress:%p,\t%%\n",
	't', str, num, num2, num, num, num2, str);
	ft_printf("char:%c,\tstr:%s,\tint:%i,\tdec:%d,
	\tunsigned:%u,\thexl:%x,\thexU:%X,\taddress:%p,\t%%\n",
	't', str, num, num2, num, num, num2, str);
}
*/
