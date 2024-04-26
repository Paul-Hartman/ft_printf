/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phartman <phartman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:28:42 by phartman          #+#    #+#             */
/*   Updated: 2024/04/26 18:42:03 by phartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libftprintf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

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

void ft_print_hexupper(int n)
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

void ft_print_pointer(void *n)
{
	unsigned long long int adr;
	ft_putstr_fd("0x5555", 1);
	ft_print_hexlower((unsigned long long int)n);
}

int	parse_string(const char ch, va_list args)
{
	if (ch == 'c')
		ft_putchar_fd((char)va_arg(args, int), 1);
	if (ch == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	if (ch == 'p')
		ft_print_pointer(va_arg(args, void *));
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
	char *dog= "dog";
	ft_printf("Dog %c, %s, %d, %i, %u, %%, %x, %X, %p\n", 'b' ,"cat", 12345, 6345423, 2147483657, 45, 45, dog);
	printf("Dog %c, %s, %d, %i, %u, %%, %x, %X, %p\n", 'b' ,"cat", 12345, 6345423, 2147483657, 45, 45, dog);
}


