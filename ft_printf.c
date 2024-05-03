/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phartman <phartman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:28:42 by phartman          #+#    #+#             */
/*   Updated: 2024/05/03 14:49:12 by phartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"




int ft_print_hex(unsigned long n, char *base)
{
	unsigned long power;
	int count;
	int digit;

	count = 0;
	power = 1;
	while (power <= n / 16) 
		power *= 16;
	while (power > 0)
	{
		digit = n / power;
		if (digit < 16)
		{
			ft_putchar_fd(base[digit], 1);
			count++;
		}
		n %= power;
		power /= 16;
	}
	return (count);
}


int ft_print_pointer(void *n)
{
	unsigned long address;
	int size;
	int count;

	count = 2;
	size = sizeof(address) * 2;
	address = (unsigned long)n;
	ft_putstr_fd("0x", 1);
	count += ft_print_hex(address, "0123456789abcdef");
	return (count); 
}

int ft_countnbr(int n)
{
	int count;
	count = 1;
	ft_putnbr_fd(n, 1);

	while(n >= 10)
	{
		 n /= 10;
		count++;
	}
	return(count);
}

int ft_countnbruns(unsigned int n)
{
	int count;
	count = 1;
	ft_putnbruns_fd(n, 1);

	while(n >= 10)
	{
		 n /= 10;
		count++;
	}
	return(count);
}

int ft_countstr(char *str)
{
	int count;
	count = ft_strlen(str);
	ft_putstr_fd(str, 1);	
	return (count);
}


int	parse_string(const char ch, va_list args)
{
	int count;

	if (ch == 'c')
	{
		ft_putchar_fd((char)va_arg(args, int), 1);
		count = 1;
	}
	if (ch == 's')
		count = ft_countstr(va_arg(args, char *));
	if (ch == 'p')
		count = ft_print_pointer(va_arg(args, void *));
	if (ch == 'd' || ch == 'i')
		count = ft_countnbr(va_arg(args, int));
	if (ch == 'u')
		count = ft_countnbruns(va_arg(args, unsigned int));
	if (ch == 'x')
		count = ft_print_hex(va_arg(args, int), "0123456789abcdef");
	if (ch == 'X')
		count = ft_print_hex(va_arg(args, int), "0123456789ABCDEF");
	if (ch == '%')
	{
		ft_putchar_fd('%', 1);
		count = 1;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	int		count;
	va_list	args;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += parse_string(format[i + 1], args);
			i++;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

int main()
{
	unsigned int existingVariable = 0;
	unsigned int *dog = &existingVariable;
	*dog = 10;  // This is now valid because 'dog' points to 'existingVariable'.
	unsigned char existing = 0;
	unsigned char *cat = &existing;
	*cat = 10;  // This is now valid because 'dog' points to 'existingVariable'.

	printf("Total size:%i: \n", ft_printf("%u", 123));
	printf("Total size:%i: \n", printf("%u", 123));
	printf("Total size:%i: \n", ft_printf("%c, %s, %p, %d, %i, %u, %x, %X, %%", 'c', "string", cat, 123, 123, 123, 1111, 1111));
	printf("Total size:%i: \n", printf("%c, %s, %p, %d, %i, %u, %x, %X, %%", 'c', "string", cat, 123, 123, 123, 1111, 1111));
}


