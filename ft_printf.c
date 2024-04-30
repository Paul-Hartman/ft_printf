/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phartman <phartman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:28:42 by phartman          #+#    #+#             */
/*   Updated: 2024/04/30 18:30:12 by phartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"


void ft_putnbruns_fd(unsigned int n, int fd)
{

	if (n >= 10)
	{
		ft_putnbruns_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

int	ft_power_of(int base, int exponent)
{
	int		counter;
	int		result;

	result = 1;
	counter = 0;
	while (counter < exponent)
	{
		result = result * base;
		counter++;
	}
	return (result);
}

void ft_print_hexlower(int n)
{

	int exponent;
	int remainder;
	int quotient;
	int power;
	char *base;

	exponent = 0;
	base = "0123456789abcdef";
	while (ft_power_of(16, exponent) <= (n / 16))
		exponent++;
	while (exponent >= 0)
	{
		power = ft_power_of(16, exponent);
		quotient = n / power;
		remainder = n % power;
		if (quotient < 16)
			ft_putchar_fd(base[quotient], 1);
		n = remainder;
		exponent--;
	}
}

void ft_print_hexupper(int n, char *base)
{
	int exponent;
	long remainder;
	long quotient;
	long power;
	char *base;

	exponent = 0;
	base = "0123456789ABCDEF";
	while (ft_power_of(16, exponent) <= (n / 16))
		exponent++;
	while (exponent >= 0)
	{
		power = ft_power_of(16, exponent);
		quotient = n / power;
		remainder = n % power;
		if (quotient < 16)
			ft_putchar_fd(base[quotient], 1);
		n = remainder;
		exponent--;
	}
}

int ft_print_pointer(void *n)
{
	unsigned long address;
	int digit;
	int size;
	int count;

	count = 0;
	size = sizeof(address) * 2;
	address = (unsigned long)n;
	ft_putstr_fd("0x", 1);
	
	{
		digit = (address >> (4 * (size - 1))) & 0xF;
		ft_putchar_fd("0123456789abcdef"[digit], 1);
		count++;
		size--;
	}
	return (count); 
}

int	parse_string(const char ch, va_list args)
{
	int count;
	char *str;

	count = 0;
	if (ch == 'c')
		ft_putchar_fd((char)va_arg(args, int), 1);
	if (ch == 's')
	{
		str = va_arg(args, char *);
		count = ft_strlen(str);
		ft_putstr_fd(str, 1);
	}
	if (ch == 'p')
		count = ft_print_pointer(va_arg(args, void *));
	if (ch == 'd' || ch == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	if (ch == 'u')
		ft_putnbruns_fd(va_arg(args, unsigned int), 1);
	if (ch == 'x')
		ft_print_hexlower(va_arg(args, int));
	if (ch == 'X')
		ft_print_hexupper(va_arg(args, int));
	if (ch == '%')
		ft_putchar_fd('%', 1);

	return (count);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	int		count;
	va_list	args;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			parse_string(format[i + 1], args);
			i++;
		}
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (i + count);
}

int main(int argc, char const *argv[])
{
	unsigned int *dog;
	ft_printf("Dog %c, %s, %d, %i, %u, %%, %x, %X, %p\n", 'b' ,"cat", 12345, 6345423, 27, 45457447, 45457447, dog);
	printf("Dog %c, %s, %d, %i, %u, %%, %x, %X, %p\n", 'b' ,"cat", 12345, 6345423, 27, 45457447, 45457447, dog);
}


